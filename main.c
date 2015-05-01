#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "chip8.h"

int main(int argc, char **argv)
{
        /* Let's verify that we're getting a file */
        if (argc != 2) {
                printf("Incorrect amount of args\n");
                fprintf(stderr, "Usage: ./chipb8 <filename>\n");
                return 1;
        }
	struct chip8 *chip8 = malloc(sizeof(struct chip8));
	if (chip8 == NULL) {
		printf("Memory for chip8 could not be allocated.\n");
		return 1;
	}

	init_chip8(chip8);
        FILE *program = fopen(argv[1], "r");
        load_program(chip8, program);

        fclose(program);
        free(chip8);
	return 0;
}
