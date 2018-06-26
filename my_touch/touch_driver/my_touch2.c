/*
*
* The driver for FT5406DQ9 touch screen controller on raspberry pi 3 environment. 
*
*
*/

#include <linux/input.h>
#include <linux/input/mt.h>
#include <linux/input-polldev.h>
#include <linux/dma-mapping.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/stddef.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/bitops.h>
#include <asm/io.h>
#include <soc/bcm2835/raspberrypi-firmware.h>
#include "raspi_FT5406DQ9.h"

struct FT5406DQ9
{
	struct platform_device *p_dev;
	struct input_dev *input_dev;
	void __iomem *ts_base;
	dma_addr_t bus_addr;
	struct task_struct *thread;
};
struct registers 
{
	uint8_t device_mode;
	uint8_t gesture_id;
	uint8_t num_points;
	struct dev_touch
	{
		uint8_t xh;
		uint8_t xl;
		uint8_t yh;
		uint8_t yl;
		uint8_t res1;
		uint8_t res2;
	} point[MAX_POINTS];

};

static uint32_t FT5406DQ9_poll_thread(void *data)
{
	struct FT5406DQ9 *ts = (struct FT5406DQ9 *) data;
	struct registers regs;
	uint32_t known_ids = 0, modified_ids, released_ids, i, x, y, touchid;

	while(!kthread_should_stop())
	{
		modified_ids = 0;
		dev_info(&ts->p_dev->dev, "VV: thread fun in device ft5406\n");
		memcpy_fromio(&regs, ts->ts_base, sizeof(struct registers));
		iowrite8(99, ts->ts_base + offsetof(struct registers, num_points));
		msleep_interruptible(20);
		
		if (regs.num_points == 99)
			continue;
		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");
		if (regs.num_points == 0 && known_ids == 0)
			continue;

		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");
		for (i = 0; i < regs.num_points; i++) 
		{
			x = (((uint32_t) regs.point[i].xh & 0xf) << 8) + regs.point[i].xl;
			y = (((uint32_t) regs.point[i].yh & 0xf) << 8) + regs.point[i].yl;
			touchid = (regs.point[i].yh >> 4) & 0xf;
			uint32_t event_id = (regs.point[i].xh >> 6) & 0x3;
			modified_ids |= 1 << touchid;
			if (event_id == FTS_TOUCH_CONTACT || event_id == FTS_TOUCH_DOWN) 
			{ 
				input_mt_slot(ts->input_dev, touchid);
				input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, 1);
				input_report_abs(ts->input_dev, ABS_MT_POSITION_X, x);
				input_report_abs(ts->input_dev, ABS_MT_POSITION_Y, y);
			}		
		} 

		dev_info(&ts->p_dev->dev, "V: thread fun in device ft5406\n");
		released_ids = known_ids & ~modified_ids;
		for (i = 0; released_ids &&  i < MAX_POINTS; i++)
 		{
			if (released_ids & (1<<i))
 			{
				dev_dbg(&ts->p_dev->dev, "Released %d, known = %x modified = %x\n", i, known_ids, modified_ids);
				input_mt_slot(ts->input_dev, i);
				input_mt_report_slot_state(ts->input_dev, MT_TOOL_FINGER, 0);
				modified_ids &= ~(1 << i);
			}
		}
		input_mt_report_pointer_emulation(ts->input_dev, true);
		input_sync(ts->input_dev);
		known_ids = modified_ids;
		dev_info(&ts->p_dev->dev, "V: Thread func of device ft5406\n");
	}
	return 0;
}

static int FT5406DQ9_probe(struct platform_device *pdev)
{  
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct FT5406DQ9 *ts;
	struct device_node *fw_node;
	struct rpi_firmware *fw;
	uint32_t ret=0, touchbuf;

	dev_info(dev, "V:Probing device ft5406\n");
	if(!(ts = devm_kzalloc(dev, sizeof(struct FT5406DQ9), GFP_KERNEL) ))
	{
		dev_err(dev, "ERRPR:memory alloction for ts failed \n");
		return -ENOMEM;
	}
	
	ts->ts_base = dma_zalloc_coherent(dev, PAGE_SIZE, &ts->bus_addr, GFP_KERNEL);
	if (!ts->ts_base) 
	{
		pr_err("[%s]: failed to dma_alloc_coherent(%ld)\n", __func__, PAGE_SIZE);
		return  ret = -ENOMEM;	
	}

	touchbuf = (u32)ts->bus_addr;
	fw_node = of_parse_phandle(np, "firmware", 0);
	if (!fw_node) 
	{
		dev_err(dev, "ERROR: Missing firmware node\n");
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return -ENOENT;
	}

	fw = rpi_firmware_get(fw_node);
	if (!fw)
	{
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return -EPROBE_DEFER;
	}

	ret = rpi_firmware_property(fw, RPI_FIRMWARE_FRAMEBUFFER_SET_TOUCHBUF, &touchbuf, sizeof(touchbuf));
	if (ret < 0 || touchbuf != 0)
 	{
		dev_warn(dev, "ERROR:Failed to set touchbuf, trying to get err:%x\n",ret);
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return ret;
	}

	if(!( ts->input_dev = input_allocate_device() ))
	{
		pr_err("[%s]: failed to dma_alloc_coherent(%ld)\n", __func__, PAGE_SIZE);
		ret = -ENOMEM;
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return ret;
	}

	platform_set_drvdata(pdev, ts);
	ts->p_dev = pdev;
	ts->input_dev->name = "FT5406 memory based driver";
//	__set_bit(EV_KEY, ts->input_dev->evbit);
//	__set_bit(EV_SYN, ts->input_dev->evbit);
	__set_bit(EV_ABS, ts->input_dev->evbit);
	input_set_abs_params(ts->input_dev, ABS_MT_POSITION_X, 0, SCR_WIDTH, 0, 0);
	input_set_abs_params(ts->input_dev, ABS_MT_POSITION_Y, 0, SCR_HEIGHT, 0, 0);
	input_mt_init_slots(ts->input_dev, MAX_POINTS, INPUT_MT_DIRECT);
	input_set_drvdata(ts->input_dev, ts);

	ret = input_register_device(ts->input_dev);
	if(ret < 0)
	{
		dev_err(dev, "ERROR: Failed the device as input device");
		input_free_device(ts->input_dev);
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return;
	}

	dev_info(dev, "V: Probe climax in device ft5406\n");
	ts->thread = kthread_run(FT5406DQ9_poll_thread, ts, "FT5406DQ9_touch");
	if(ts->thread == NULL)
	{
		dev_err(dev, "ERROR: Failed to create kernel thread");
		input_unregister_device(ts->input_dev);
		input_free_device(ts->input_dev);
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
		return ret;
	}
	return 0;
}

static int FT5406DQ9_remove(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct FT5406DQ9 *ts = (struct FT5406DQ9 *) platform_get_drvdata(pdev);
	dev_info(dev, "V:Removing device ft5406\n");

	kthread_stop(ts->thread);
	if (ts->ts_base) 
		dma_free_coherent(dev, PAGE_SIZE, ts->ts_base, ts->bus_addr);
	
	if (ts->input_dev) 
	{
		input_unregister_device(ts->input_dev);
		input_free_device(ts->input_dev);
	}
	return 0;
}

static const struct of_device_id FT5406DQ9_match[] = {
	{ .compatible = "rpi,rpi-ft5406", },
	{},
};

MODULE_DEVICE_TABLE( ff, FT5406DQ9_match);

static struct platform_driver FT5406DQ9_touch_driver = {
	.driver = {
		.name   = "rpi-ft5406",
		.owner  = THIS_MODULE,
		.of_match_table = FT5406DQ9_match,
	},
	.probe          = FT5406DQ9_probe,
	.remove         = FT5406DQ9_remove,
};

static int __init FT5406DQ9_touch_init(void)
{
	return platform_driver_register(&FT5406DQ9_touch_driver);
}

static void __exit FT5406DQ9_touch_exit(void)
{
	platform_driver_unregister(&FT5406DQ9_touch_driver);
}

module_init (FT5406DQ9_touch_init);
module_exit (FT5406DQ9_touch_exit);

MODULE_DESCRIPTION("The FT5406 touch screen driver on Raspberry pi");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tatikonda Venkata Rao");
MODULE_INFO(intree,"Y");
