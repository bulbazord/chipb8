#include "chip8.h"

struct chip8 *chip8 = NULL;

void init_chip8(struct chip8 *chip8)
{
	if (chip8) {

		// Initialize Memory
		memset(chip8->memory, 0x00, MEM_SIZE);

		// Initialize Registers
		memset(chip8->regs, 0x00, REGISTER_LIST_SIZE);
		chip8->reg_I = 0x0000;
		chip8->reg_PC = PROGRAM_START;
		chip8->reg_delay = 0x00;
		chip8->reg_sound = 0x00;

		// Initialize Stack
		memset(chip8->stack, 0x0000, STACK_SIZE);

		// Initialize keyboard
		memset(chip8->keyboard, 0, KEY_LIST_SIZE);
	}
}
