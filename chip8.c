#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chip8.h"

/**
 * This function assumes that the chip8 struct
 * has had memory allocated already and is 
 * valid.
 */
void init_instructions(struct chip8 *chip8)
{
	/* SYS addr */
	chip8->instr[0] = 0x0000;
	chip8->instr_masks[0] = 0xF000;
	/* CLS */
	chip8->instr[1] = 0x00E0;
	chip8->instr_masks[1] = 0xFFFF;
	/* RET */
	chip8->instr[2] = 0x00EE;
	chip8->instr_masks[2] = 0xFFFF;
	/* JP addr */
	chip8->instr[3] = 0x1000;
	chip8->instr_masks[3] = 0xF000;
	/* CALL addr */
	chip8->instr[4] = 0x2000;
	chip8->instr_masks[4] = 0xF000;
	/* SE Vx, byte */
	chip8->instr[5] = 0x3000;
	chip8->instr_masks[5] = 0xF000;
	/* SNE Vx, byte */
	chip8->instr[6] = 0x4000;
	chip8->instr_masks[6] = 0xF000;
	/* SE Vx, Vy */
	chip8->instr[7] = 0x5000;
	chip8->instr_masks[7] = 0xF00F;
	/* LD Vx, byte */
	chip8->instr[8] = 0x6000;
	chip8->instr_masks[8] = 0xF000;
	/* ADD Vx, byte */
	chip8->instr[9] = 0x7000;
	chip8->instr_masks[9] = 0xF000;
	/* LD Vx, Vy */
	chip8->instr[10] = 0x8000;
	chip8->instr_masks[10] = 0xF00F;
	/* OR Vx, Vy */
	chip8->instr[11] = 0x8001;
	chip8->instr_masks[11] = 0xF00F;
	/* AND Vx, Vy */
	chip8->instr[12] = 0x8002;
	chip8->instr_masks[12] = 0xF00F;
	/* XOR Vx, Vy */
	chip8->instr[13] = 0x8003;
	chip8->instr_masks[13] = 0xF00F;
	/* ADD Vx, Vy */
	chip8->instr[14] = 0x8004;
	chip8->instr_masks[14] = 0xF00F;
	/* SUB Vx, Vy */
	chip8->instr[15] = 0x8005;
	chip8->instr_masks[15] = 0xF00F;
	/* SHR Vx {, Vy} */
	chip8->instr[16] = 0x8006;
	chip8->instr_masks[16] = 0xF00F;
	/* SUBN Vx {, Vy} */
	chip8->instr[17] = 0x8007;
	chip8->instr_masks[17] = 0xF00F;
	/* SHL Vx {, Vy} */
	chip8->instr[18] = 0x800E;
	chip8->instr_masks[18] = 0xF00F;
	/* SNE Vx, Vy */
	chip8->instr[19] = 0x9000;
	chip8->instr_masks[19] = 0xF000;
	/* LD I, addr */
	chip8->instr[20] = 0xA000;
	chip8->instr_masks[20] = 0xF000;
	/* JP V0, addr */
	chip8->instr[21] = 0xB000;
	chip8->instr_masks[21] = 0xF000;
	/* RND Vx, byte */
	chip8->instr[22] = 0xC000;
	chip8->instr_masks[22] = 0xF000;
	/* DRW Vx, Vy, nibble */
	chip8->instr[23] = 0xD000;
	chip8->instr_masks[23] = 0xF000;
	/* SKP Vx */
	chip8->instr[24] = 0xE09E;
	chip8->instr_masks[24] = 0xF0FF;
	/* SKNP Vx */
	chip8->instr[25] = 0xE0A1;
	chip8->instr_masks[25] = 0xF0FF;
	/* LD Vx, DT */
	chip8->instr[26] = 0xF007;
	chip8->instr_masks[26] = 0xF0FF;
	/* LD Vx, K */
	chip8->instr[27] = 0xF00A;
	chip8->instr_masks[27] = 0xF0FF;
	/* LD DT, Vx */
	chip8->instr[28] = 0xF015;
	chip8->instr_masks[28] = 0xF0FF;
	/* LD ST, Vx */
	chip8->instr[29] = 0xF018;
	chip8->instr_masks[29] = 0xF0FF;
	/* ADD I, Vx */
	chip8->instr[30] = 0xF01E;
	chip8->instr_masks[30] = 0xF0FF;
	/* LD F, Vx */
	chip8->instr[31] = 0xF029;
	chip8->instr_masks[31] = 0xF0FF;
	/* LD B, Vx */
	chip8->instr[32] = 0xF033;
	chip8->instr_masks[32] = 0xF0FF;
	/* LD [I], Vx */
	chip8->instr[33] = 0xF055;
	chip8->instr_masks[33] = 0xF0FF;
	/* LD Vx, [I] */
	chip8->instr[34] = 0xF065;
	chip8->instr_masks[34] = 0xF0FF;

}

/**
 * This function assumes that the chip8 struct
 * has had memory allocated already and is
 * valid.
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
	chip8->memory[35] = 0xF0;
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
		chip8->reg_SP = 0;

		// Initialize Stack
		// Stack is 2 bytes per element, i.e. it stores 16 bits per location
		memset(chip8->stack, 0x00, STACK_SIZE * 2);

		// Initialize keyboard
		memset(chip8->keyboard, KEY_NOT_PRESSED, KEY_LIST_SIZE);

		init_font(chip8);
		init_instructions(chip8);
	}
}

void step(struct chip8 *chip8)
{
	// Retrive Instruction
	uint16_t instr = chip8->memory[chip8->reg_PC] << 8 | chip8->memory[chip8->reg_PC+1];
	chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;

	// Figure out which instruction
	int count = 0;
	int i;
	for (i = 0; i < INSTRUCTIONS_SIZE; i++) {
		if ((instr & chip8->instr_masks[i]) == chip8->instr[i]) {
			count = i;
		}
	}

	// nnn
	uint16_t addr = instr & 0x0FFF; 
	// Vx, Vy
	uint8_t vx = (instr & 0x0F00) >> 8;
	uint8_t vy = (instr & 0x00F0) >> 4;
	// k, kk
	uint8_t nibble = instr & 0x000F;
	uint8_t byte = instr & 0x00FF;

	// for arithmetic purposes
	int result;

	if (count == -1) {
		fprintf(stderr, "WARNING: Unrecognized Instruction 0x%x\n", instr);
	} else {
		switch (count) {
		// 0nnn - SYS addr
		case 0:
			chip8->reg_PC = addr;
			break;

		// 00E0 - CLS
		case 1:
			//TODO Clear screen here
			break;
		
		// 00EE - RET
		case 2:
			chip8->reg_PC = chip8->stack[chip8->reg_SP];
			chip8->reg_SP--;
			break;

		// 1nnn - JP addr
		case 3:
			chip8->reg_PC = addr;
			break;

		// 2nnn - CALL addr
		case 4:
			chip8->reg_SP++;
			chip8->stack[chip8->reg_SP] = chip8->reg_PC;
			chip8->reg_PC = addr;
			break;

		// 3xkk - SE Vx, byte
		case 5:
			if (chip8->regs[vx] == byte) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// 4xkk - SNE Vx, byte
		case 6:
			if (chip8->regs[vx] != byte) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// 5xy0 - SE Vx, Vy
		case 7:
			if (chip8->regs[vx] == chip8->regs[vy]) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// 6xkk - LD Vx, byte
		case 8:
			chip8->regs[vx] = byte;
			break;

		// 7xkk - ADD Vx, byte
		case 9:
			chip8->regs[vx] = chip8->regs[vx] + byte;
			break;

		// 8xy0 - LD Vx, Vy
		case 10:
			chip8->regs[vx] = chip8->regs[vy];
			break;

		// 8xy1 - OR Vx, Vy
		case 11:
			chip8->regs[vx] = chip8->regs[vx] | chip8->regs[vy];
			break;

		// 8xy2 - AND Vx, Vy
		case 12:
			chip8->regs[vx] = chip8->regs[vx] & chip8->regs[vy];
			break;

		// 8xy3 - XOR Vx, Vy
		case 13:
			chip8->regs[vx] = chip8->regs[vx] ^ chip8->regs[vy];
			break;

		// 8xy4 - ADD Vx, Vy
		case 14:
			if (result > 255) {
				chip8->regs[0xF] = 1;
			} else {
				chip8->regs[0xF] = 0;
			}
			chip8->regs[vx] = (result & 0xFF);
			break;

		// 8xy5 - SUB Vx, Vy
		case 15:
			result = chip8->regs[vx] - chip8->regs[vy];
			if (chip8->regs[vx] > chip8->regs[vy]) {
				chip8->regs[0xF] = 1;

			} else {
				chip8->regs[0xF] = 0;
			}
			chip8->regs[vx] = (result & 0xFF);
			break;

		// 8xy6 - SHR Vx {, Vy}
		case 16:
			result = chip8->regs[vx];
			if (result & 1 == 1) {
				chip8->regs[0xF] = 1;
			} else {
				chip8->regs[0xF] = 0;
			}
			chip8->regs[vx] = result >> 1;
			break;

		// 8xy7 - SUBN Vx, Vy
		case 17:
			result = chip8->regs[vx] - chip8->regs[vy];
			if (chip8->regs[vx] > chip8->regs[vy]) {
				chip8->regs[0xF] = 1;
			} else {
				chip8->regs[0xF] = 0;
			}
			chip8->regs[vx] = (result & 0xFF);
			break;

		// 8xyE - SHL Vx {, Vy}
		case 18:
			result = chip8->regs[vx];
			if (chip8->regs[vx] > 127) {
				chip8->regs[0xF] = 1;
			} else {
				chip8->regs[0xF] = 0;
			}
			chip8->regs[vx] = result << 1;
			break;

		// 9xy0 - SNE Vx, Vy
		case 19:
			if (chip8->regs[vx] != chip8->regs[vy]) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// Annn - LD I, addr
		case 20:
			chip8->reg_I = addr;
			break;

		// Bnnn - JP V0, addr
		case 21:
			chip8->reg_PC = addr + chip8->regs[0];
			break;

		// Cxkk - RND Vx, byte
		case 22:
			result = rand() & 0xFF;
			chip8->regs[vx] = byte & result;
			break;

		// Dxyn - DRW Vx, Vy, nibble
		case 23:
			//TODO draw thing
			break;

		// Ex9E - SKP Vx
		case 24:
			result = chip8->regs[vx];
			if (result < KEY_LIST_SIZE && chip8->keyboard[result] == KEY_PRESSED) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// ExA1 - SKNP Vx
		case 25:
			result = chip8->regs[vx];
			if (result < KEY_LIST_SIZE && chip8->keyboard[result] == KEY_NOT_PRESSED) {
				chip8->reg_PC = (chip8->reg_PC + 2) & 0xFFF;
			}
			break;

		// Fx07 - LD Vx, DT
		case 26:
			chip8->regs[vx] = chip8->reg_delay;
			break;

		// Fx0A - LD Vx, K
		case 27:
			//TODO wait for keypress
			break;

		// Fx15 - LD DT, Vx
		case 28:
			chip8->reg_delay = chip8->regs[vx];
			break;

		// Fx18 - LD ST, Vx
		case 29:
			chip8->reg_sound = chip8->regs[vx];
			break;

		// Fx1E - ADD I, Vx
		case 30:
			chip8->reg_I = chip8->reg_I + chip8->regs[vx];
			break;

		// Fx29 - LD F, Vx
		case 31:
			result = chip8->regs[vx];
			if (result <= 0xF) {
				chip8->reg_I = chip8->memory[result*5];
			}
			break;

		// Fx33 - LD B, Vx
		case 32:
			result = chip8->regs[vx];
			chip8->memory[chip8->reg_I+2] = result % 10;
			result = result / 10;
			chip8->memory[chip8->reg_I+1] = result % 10;
			result = result / 10;
			chip8->memory[chip8->reg_I] = result % 10;
			break;

		// Fx55 - LD [I], Vx
		case 33:
			for (result = 0; result <= vx; result++) {
				chip8->memory[chip8->reg_I + result] = chip8->regs[result];
			}
			break;

		// Fx65 - LD Vx, [I]
		case 34:
			for (result = 0; result <= vx; result++) {
				chip8->regs[result] = chip8->memory[chip8->reg_I + result];
			}
			break;

		default:
			break;
		}
			
	}
}
