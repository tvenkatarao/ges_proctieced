
#obj-m+:= kblock.o
#PREFIX:=/home/venkata/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-


#all:
#	make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) modules
	
#clean:
#	 make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) clean

obj-m:= kblock.o
KERNEL_DIR:=/lib/modules/3.13.0-83-generic/build
#PWD := $(pwd)
default:
	make -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules
clean:
	rm *.o *.ko *.mod.c
