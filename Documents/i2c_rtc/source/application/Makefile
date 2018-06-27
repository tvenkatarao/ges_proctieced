.PHONY : clean

GCC := $(COMPILER)gcc 
INCLUDE := -I ../../header/

SOURCE  := $(wildcard *.c)
 
executable : $(SOURCE)
	$(GCC) $(SOURCE) -o $@ $(INCLUDE)

clean :
	@rm  executable 

