obj-m:=fcd.o
PREFIX=/home/venkata/tools/arm-bcm2708/arm-bcm2708-linux-gnueabi/bin/arm-bcm2708-linux-gnueabi-

all:
	make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) modules

clean:
	 make ARCH=arm CROSS_COMPILE=$(PREFIX) -C /home/venkata/raspi/linux M=$(PWD) clean
