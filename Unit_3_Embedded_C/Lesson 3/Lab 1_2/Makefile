#@Copyright : Basem

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

Project_Name=Uart_Lab

all: $(Project_Name).bin
	@echo  "========== Build is Done =========="
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@	
	
%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $(INCS) $< -o $@
		
$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T Linker_Script.ld $(LIBS) -Map=details.map $(OBJ) $(AsOBJ) -o $@

$(Project_Name).bin: $(Project_Name).elf  
	$(CC)objcopy.exe -O binary $<  $@


clean_all:
	rm *.o *elf *.bin
	@echo " *** EveryThing Clean ***" 

clean:
	rm *elf *.bin	