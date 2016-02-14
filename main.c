#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>

#include "input.h"
#include "chip8.h"
#include "graphics.h"

/**
 * Takes a binary ROM for CHIP-8 and copies it into
 * the chip8 memory.
 *
 * @param chip8 The chip8 struct we load the ROM into.
 * @param file The file containing the ROM we want to load.
 * @return Returns 0 if ROM loaded from file correctly. 1 otherwise.
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

/**
 * Main function!
 */
int main(int argc, char *argv[])
{
    int status = 0;

    /* Let's verify that we're getting a file */
    if (argc != 2) {
        fprintf(stderr, "Incorrect amount of args\n");
        fprintf(stderr, "Usage: ./chipb8 <filename>\n");
        status = 1;
        goto done;
    }
    /* Create our chip8 struct */
    struct chip8 *chip8 = malloc(sizeof(struct chip8));
    if (chip8 == NULL) {
        fprintf(stderr, "Memory for chip8 could not be allocated.\n");
        status = 1;
        goto cleanup_chip8;
    }

    /* Initialize our chip8 struct and load the ROM */
    init_chip8(chip8);
    if (load_program(chip8, argv[1])) {
        status = 1;
        goto cleanup_chip8;
    }

    /* Initialize SDL stuff*/
    srand(time(NULL));
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "SDL Initialization failed: %s\n", SDL_GetError());
        status = 1;
        goto cleanup_SDL;
    }

    struct graphics *graphics = malloc(sizeof(struct graphics));

    if (init_graphics(graphics)) {
        fprintf(stderr, "Error in creating window\n");
        status = 1;
        goto cleanup_graphics;
    }

    SDL_Event event;

    int quit = 0;
    int cycle_ticks = 0;
    int delay_ticks = 0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        if (SDL_GetTicks() - cycle_ticks > 1) {
            if (chip8->wait_key == -1) {
                step(chip8);
            } else {
                for (int i = 0; i <= 0xF; i++) {
                    if (keydown(i)) {
                        chip8->keyboard[chip8->wait_key] = i;
                        chip8->wait_key = -1;
                        break;
                    }
                }
            }
            cycle_ticks = SDL_GetTicks();
        }

        if (SDL_GetTicks() - delay_ticks > (1000 / 60)) {
            if (chip8->reg_delay) {
                chip8->reg_delay--;
            }

            if (chip8->reg_sound) {
                chip8->reg_sound--;
                //TODO sound here
            }
            delay_ticks = SDL_GetTicks();
        }
        render(graphics, chip8);

    }

cleanup_graphics:
    destroy_graphics(graphics);
    free(graphics);
cleanup_SDL:
    SDL_Quit();
cleanup_chip8:
    free(chip8);
done:
    return status;
}

