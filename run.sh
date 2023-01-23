mkdir out

gcc -ffreestanding -c src/main.c -o out/main.o

nasm src/kernel.asm -f elf64 -o out/kernel.o

ld -o out/kernel.bin -Ttext 0x1000 out/kernel.o out/main.o --oformat binary

nasm src/bootsector.asm -f bin -o out/bootsector.bin

cat out/bootsector.bin out/kernel.bin > out/os-image.bin

qemu-system-i386 -fda out/os-image.bin