#include <stdlib.h>
#include <string.h>
#include "chip8.h"

void init_chip8(struct chip8 *chip8)
{
	if (chip8) {

		// Initialize Memory
		memset(chip8->memory, 0x00, MEM_SIZE);

		// Initialize Registers
		memset(chip8->regs, 0x00, REGISTER_LIST_SIZE);
		chip8->reg_I = 0;
		chip8->reg_PC = PROGRAM_START;
		chip8->reg_delay = 0;
		chip8->reg_sound = 0;

		// Initialize Stack
		memset(chip8->stack, 0x00, STACK_SIZE);

		// Initialize keyboard
		memset(chip8->keyboard, 0, KEY_LIST_SIZE);

	}
}
