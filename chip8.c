#include <stdlib.h>
#include <string.h>
#include "chip8.h"

/*
 * This function assumes that the chip8
 * has already been malloc'd.
 */
void init_font(struct chip8 *chip8)
{
	// Set up '0'
	chip8->memory[0] = 0xF0;
	chip8->memory[1] = 0x90;
	chip8->memory[2] = 0x90;
	chip8->memory[3] = 0x90;
	chip8->memory[4] = 0xF0;

	// Set up '1'
	chip8->memory[5] = 0x20;
	chip8->memory[6] = 0x60;
	chip8->memory[7] = 0x20;
	chip8->memory[8] = 0x20;
	chip8->memory[9] = 0x70;

	// Set up '2'
	chip8->memory[10] = 0xF0;
	chip8->memory[11] = 0x10;
	chip8->memory[12] = 0xF0;
	chip8->memory[13] = 0x80;
	chip8->memory[14] = 0xF0;

	// Set up '3'
	chip8->memory[15] = 0xF0;
	chip8->memory[16] = 0x10;
	chip8->memory[17] = 0xF0;
	chip8->memory[18] = 0x10;
	chip8->memory[19] = 0xF0;

	// Set up '4'
	chip8->memory[20] = 0x90;
	chip8->memory[21] = 0x90;
	chip8->memory[22] = 0xF0;
	chip8->memory[23] = 0x10;
	chip8->memory[24] = 0x10;

	// Set up '5'
	chip8->memory[25] = 0xF0;
	chip8->memory[26] = 0x80;
	chip8->memory[27] = 0xF0;
	chip8->memory[28] = 0x10;
	chip8->memory[29] = 0xF0;

	// Set up '6'
	chip8->memory[30] = 0xF0;
	chip8->memory[31] = 0x80;
	chip8->memory[32] = 0xF0;
	chip8->memory[33] = 0x90;
	chip8->memory[34] = 0xF0;

	// Set up '7'
	chip8->memory[35] = 0xf0;
	chip8->memory[36] = 0x10;
	chip8->memory[37] = 0x20;
	chip8->memory[38] = 0x40;
	chip8->memory[39] = 0x40;

	// Set up '8'
	chip8->memory[40] = 0xF0;
	chip8->memory[41] = 0x90;
	chip8->memory[42] = 0xF0;
	chip8->memory[43] = 0x90;
	chip8->memory[44] = 0xF0;

	// Set up '9'
	chip8->memory[45] = 0xF0;
	chip8->memory[46] = 0x90;
	chip8->memory[47] = 0xF0;
	chip8->memory[48] = 0x10;
	chip8->memory[49] = 0xF0;

	// Set up 'A'
	chip8->memory[50] = 0xF0;
	chip8->memory[51] = 0x90;
	chip8->memory[52] = 0xF0;
	chip8->memory[53] = 0x90;
	chip8->memory[54] = 0x90;

	// Set up 'B'
	chip8->memory[55] = 0xE0;
	chip8->memory[56] = 0x90;
	chip8->memory[57] = 0xE0;
	chip8->memory[58] = 0x90;
	chip8->memory[59] = 0xE0;

	// Set up 'C'
	chip8->memory[60] = 0xF0;
	chip8->memory[61] = 0x80;
	chip8->memory[62] = 0x80;
	chip8->memory[63] = 0x80;
	chip8->memory[64] = 0xF0;

	// Set up 'D'
	chip8->memory[65] = 0xE0;
	chip8->memory[66] = 0x90;
	chip8->memory[67] = 0x90;
	chip8->memory[68] = 0x90;
	chip8->memory[69] = 0xE0;

	// Set up 'E'
	chip8->memory[70] = 0xF0;
	chip8->memory[71] = 0x80;
	chip8->memory[72] = 0xF0;
	chip8->memory[73] = 0x80;
	chip8->memory[74] = 0xF0;

	// Set up 'F'
	chip8->memory[75] = 0xF0;
	chip8->memory[76] = 0x80;
	chip8->memory[77] = 0xF0;
	chip8->memory[78] = 0x80;
	chip8->memory[79] = 0x80;

}

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

		init_font(chip8);
	}
}

