#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>

#include "input.h"
#include "chip8.h"

int load_program(struct chip8 *c8, char *file)
{
	FILE *program;
	program = fopen(file, "r");

	if (program == NULL) {
		fprintf(stderr, "Can't open that file.\n");
		return -1;
	}

	printf("File loaded: %s\n", file);
	fclose(program);
	return 0;
}

int main(int argc, char *argv[])
{
	/* Let's verify that we're getting a file */
	if (argc != 2) {
		printf("Incorrect amount of args\n");
		fprintf(stderr, "Usage: ./chipb8 <filename>\n");
		return 1;
	}
	struct chip8 *chip8 = malloc(sizeof(struct chip8));
	if (chip8 == NULL) {
		fprintf(stderr, "Memory for chip8 could not be allocated.\n");
		return 1;
	}

	init_chip8(chip8);
	load_program(chip8, argv[1]);
	free(chip8);
	return 0;
}
