#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "input.h"
#include "chip8.h"

int load_program(struct chip8 *chip8, char *file)
{
	FILE *program;
	program = fopen(file, "r");

	if (program == NULL) {
		fprintf(stderr, "ROM could not be loaded.\n");
		return 1;
	}

	int current_addr = PROGRAM_START;

	unsigned char buffer;
	while (fread(&buffer, 1, 1, program) > 0) {
		chip8->memory[current_addr++] = buffer;
	}
	fclose(program);
	return 0;
}

int main(int argc, char *argv[])
{
	/* Let's verify that we're getting a file */
	if (argc != 2) {
		fprintf(stderr, "Incorrect amount of args\n");
		fprintf(stderr, "Usage: ./chipb8 <filename>\n");
		return 1;
	}
	/* Create our chip8 struct */
	struct chip8 *chip8 = malloc(sizeof(struct chip8));
	if (chip8 == NULL) {
		fprintf(stderr, "Memory for chip8 could not be allocated.\n");
		return 1;
	}

	/* Initialize our chip8 struct and load the ROM */
	init_chip8(chip8);
	if (load_program(chip8, argv[1])) {
		return 1;
	}

	/* Initialize SDL stuff*/
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		fprintf(stderr, "SDL Initialization failed: %s\n", SDL_GetError());
		return 1;
	}

	srand(time(NULL));

	int quit = 0;
	SDL_Window *screen = SDL_CreateWindow("CHIP-b8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 320, 0);
	SDL_Event event;

	while (!quit) {
		/* Check to see if user has quit */
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			quit = 1;
		}

		/* Execute instruction */
		step(chip8);
	}

	SDL_Quit();

	free(chip8);
	return 0;
}
