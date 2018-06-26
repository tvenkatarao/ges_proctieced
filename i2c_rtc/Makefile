obj-m:=rtc_ds1307.o
#PREFIX:=/home/venkata/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-

#all:
#	make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) modules
#	#make -C CROSS_COMPILE=arm-linux-gnueabihf- M=$(PWD) modules
#	make -C /lib/modules/3.13.0-83-generic/build M=$(PWD) modules
#clean:
#	 make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) clean
#	make -C CROSS_COMPILE=arm-linux-gnueabihf- M=$(PWD) clean
#	make -C /lib/modules/3.13.0-83-generic/build M=$(PWD) clean	obj-m:=spi_adc_ioctl.o
KDIR:=/home/venkata/raspi/linux
PWD:=$(shell pwd)

all:
	$(MAKE) ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C $(KDIR) M=$(PWD) modules
	#make -C /lib/modules/4.9.64-v7+/build M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	# rm -fr *.o *.order *.mod.c *.mod.o *.ko Module.symvers
