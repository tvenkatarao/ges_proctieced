

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h> 
#include <linux/fs.h>     
#include <linux/errno.h>  
#include <linux/types.h>  
#include <linux/vmalloc.h>
#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/hdreg.h>

MODULE_LICENSE("GPL");
static char *Version = "1.3";

static int major_num = 0;
module_param(major_num, int, 0);
static int hardsect_size = 512;
module_param(hardsect_size, int, 0);
static int nsectors = 1024; 
module_param(nsectors, int, 0);

#define KERNEL_SECTOR_SIZE 512

static struct request_queue *Queue;

static struct sbd_device {
    unsigned long size;
    spinlock_t lock;
    u8 *data;
    struct gendisk *gd;
} Device;


static void sbd_transfer(struct sbd_device *dev, unsigned long sector,
		unsigned long nsect, char *buffer, int write)
{
    unsigned long offset = sector*hardsect_size;
    unsigned long nbytes = nsect*hardsect_size;
    
    if ((offset + nbytes) > dev->size) {
	printk (KERN_NOTICE "sbd: Beyond-end write (%ld %ld)\n", offset, nbytes);
	return;
    }
    if (write)
	memcpy(dev->data + offset, buffer, nbytes);
    else
	memcpy(buffer, dev->data + offset, nbytes);
}

static void sbd_request(request_queue_t *q)
{
    struct request *req;

    while ((req = elv_next_request(q)) != NULL) {
	if (! blk_fs_request(req)) {
	    printk (KERN_NOTICE "Skip non-CMD request\n");
	    end_request(req, 0);
	    continue;
	}
	sbd_transfer(&Device, req->sector, req->current_nr_sectors,
			req->buffer, rq_data_dir(req));
	end_request(req, 1);
    }
}




int sbd_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
	long size;
	struct hd_geometry geo;

	switch(cmd) {
	
	    case HDIO_GETGEO:
		size = Device.size*(hardsect_size/KERNEL_SECTOR_SIZE);
		geo.cylinders = (size & ~0x3f) >> 6;
		geo.heads = 4;
		geo.sectors = 16;
		geo.start = 4;
		if (copy_to_user((void *) arg, &geo, sizeof(geo)))
			return -EFAULT;
		return 0;
    }

    return -ENOTTY; 

static struct block_device_operations sbd_ops = {
    .owner           = THIS_MODULE,
    .ioctl	     = sbd_ioctl
};

static int __init sbd_init(void)
{
   Device.size = nsectors*hardsect_size;
    spin_lock_init(&Device.lock);
    Device.data = vmalloc(Device.size);
    if (Device.data == NULL)
	return -ENOMEM;

    Queue = blk_init_queue(sbd_request, &Device.lock);
    if (Queue == NULL)
	    goto out;
    blk_queue_hardsect_size(Queue, hardsect_size);

    major_num = register_blkdev(major_num, "sbd");
    if (major_num <= 0) {
	printk(KERN_WARNING "sbd: unable to get major number\n");
	goto out;
    }

    Device.gd = alloc_disk(16);
    if (! Device.gd)
	goto out_unregister;
    Device.gd->major = major_num;
    Device.gd->first_minor = 0;
    Device.gd->fops = &sbd_ops;
    Device.gd->private_data = &Device;
    strcpy (Device.gd->disk_name, "sbd0");
    set_capacity(Device.gd, nsectors*(hardsect_size/KERNEL_SECTOR_SIZE));
    Device.gd->queue = Queue;
    add_disk(Device.gd);

    return 0;

  out_unregister:
    unregister_blkdev(major_num, "sbd");
  out:
    vfree(Device.data);
    return -ENOMEM;
}

static void sbd_exit(void)
{
    del_gendisk(Device.gd);
    put_disk(Device.gd);
    unregister_blkdev(major_num, "sbd");
    blk_cleanup_queue(Queue);
    vfree(Device.data);
}
	
module_init(sbd_init);
module_exit(sbd_exit);
