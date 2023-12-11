as --32 boot.s -o boot.o

#compile kernel.c file
cd kernel
gcc -m32 -c kernel.c -o kernel.o  -ffreestanding -O2 -Wall -Wextra
nasm -felf switch_to_32bit.asm -o switch_to_32bit.o
cd ../
#compile a20 line check
cd servers/memory/
nasm -felf paging_enable.asm -o paging_enable.o
nasm -felf flatGDT.asm -o flatGDT.o
cd ../../

cd ipc/tasking/
as --32 taskSwitcher.s -o taskSwitcher.o
cd ../../
#linking the kernel with kernel.o and boot.o files
cd kernel
ld -m elf_i386 -T linker.ld kernel.o  ../servers/memory/paging_enable.o ../servers/memory/flatGDT.o ../ipc/tasking/taskSwitcher.o switch_to_32bit.o boot.o -o MyOS.bin -nostdlib
find . -name '*.h' -o -name '*.asm' -o -name '*.s' -o -name '*.c' -o -name '*.cpp' | xargs wc -l

#check MyOS.bin file is x86 multiboot file or not
grub-file --is-x86-multiboot MyOS.bin

#building the iso file
mkdir -p isodir/boot/grub
cp MyOS.bin isodir/boot/MyOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o MyOS.iso isodir
cd ../

#run it in qemu
qemu-system-x86_64 -cdrom MyOS.iso
