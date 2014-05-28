all: chip8.o main.o
	gcc chip8.o main.o -o chipb8

clean:
	rm *.o chipb8
