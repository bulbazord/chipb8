#include <stdio.h>
#include <stdlib.h>
#include "chip8.h"

int main(int argc, char **argv)
{
	struct chip8 *chip8 = malloc(sizeof(struct chip8));
	if (chip8 == NULL) {
		printf("Memory for chip8 could not be allocated.\n");
		return 1;
	}

	init_chip8(chip8);
        free(chip8);
	return 0;
}
