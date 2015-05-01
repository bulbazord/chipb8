all: chip8.o main.o input.o
        gcc input.o chip8.o main.o -o chipb8

clean:
	rm *.o chipb8
