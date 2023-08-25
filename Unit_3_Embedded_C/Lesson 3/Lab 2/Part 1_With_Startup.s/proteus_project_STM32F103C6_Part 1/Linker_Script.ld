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
	.text :  {                /* Output Section */
		     *(.vectors*)        /* take any vectors from files.o */
		     *(.text*)           /* take any text from files.o */
		     *(.rodata*)           /* take any rodata from files.o */
	}> flash

	.data :  {                
		     *(.data*)        /* take any data from files.o */
	}> flash

	.bss :  {                
		     *(.bss*)        /* take any bss from files.o */
	}> sram
}