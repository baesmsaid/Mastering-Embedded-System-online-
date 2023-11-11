/* Linker_Script.ld CortexM3
Eng.Basem
*/

MEMORY
{
	flash(RX) : ORIGIN = 0x08000000,  LENGTH = 128k
	sram(WRX) : ORIGIN = 0x20000000,  LENGTH = 20k
}

SECTIONS
{
	.text :  
	{                /* Output Section */
		     *(.vectors*)        /* take any vectors from files.o */
		     *(.text*)           /* take any text from files.o */
		     *(.rodata*)         /* take any rodata from files.o */
			 _E_text = . ;       /* End of Text Section */  
	}> flash

	.data :  
	{
	_S_DATA = . ;       /* Start of data Section */
	*(.data*)           /* take any data from files.o */
	. = ALIGN (4) ;     /* Align memory before end data section and start bss section */
	_E_DATA = . ;       /* End of data Section */
	}> sram AT> flash

	.bss :  
	{                
	_S_bss = . ;      /* Start of bss Section */
	*(.bss*)          /* take any bss from files.o */
	_E_bss = . ;      /* End of bss Section */
	
	. = ALIGN (4) ;   /* Align memory before end bss section and start stack section */
	. = . + 0x1000;
	_stack_top = . ;
	
	}> sram
}