.PHONY : clean1 clean2

all : target1 target2 

target1 : 
	$(MAKE) -C ./source/application 

target2 :
	$(MAKE) -C ./source/driver  

clean : clean1 clean2

clean1 : 
	$(MAKE) -C ./source/application clean

clean2 :
	$(MAKE) -C ./source/driver clean
