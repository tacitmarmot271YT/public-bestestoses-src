#include "kernel.h"
#include "../ipc/gdt.h"
#include "../servers/video/Desktop_environment.h"

int kernel_entry()
{

	init_vga(GREEN,BLACK);
	setGdt();
	initTasking();
	print_string("This is Bestestoses version 0.45333 Shoshone");
	print_new_line();
	print_int(23);
	print_new_line();
	otherMain();
	initVBE();
return 0;
}

