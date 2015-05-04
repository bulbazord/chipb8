#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "input.h"
#include "chip8.h"
#include "graphics.h"

/**
 * Takes a binary ROM for CHIP-8 and copies it into
 * the chip8 memory.
 */
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

void test(struct chip8 *chip8, int ticks)
{
	int i;
	for (i = 0; i < 64*ticks; i++) {
		chip8->screen[i] = 0;
	}
	for (i = 64*ticks; i < (64*ticks)+64; i++) {
		chip8->screen[i] = 1;
	}
	for (i = (64*ticks)+64; i < (2048); i++) {
		chip8->screen[i] = 0;
	}

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
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		fprintf(stderr, "SDL Initialization failed: %s\n", SDL_GetError());
		return 1;
	}

	struct graphics *graphics = malloc(sizeof(struct graphics));

	if (init_graphics(graphics)) {
		fprintf(stderr, "Error in creating window\n");
		return 1;
	}

	SDL_Event event;

	int quit = 0;
	int ticks = 0;

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}

		step(chip8);
		test(chip8, ticks);
		ticks = (ticks + 1) & 31;
		render(graphics, chip8);
	}

	destroy_graphics(graphics);
	free(graphics);
	SDL_Quit();
	free(chip8);
	return 0;
}
