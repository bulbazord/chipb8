#include <stdint.h>
#ifndef _CHIP8_H
#define _CHIP8_H

/**
 * The Chip-8 has around 4K of memory to work with.
 * Programs generally start at 0x200, or memory location 512
 */
#define MEM_SIZE		4096
#define PROGRAM_START		512

/* There are 16 general purpose registers, each 8-bit */
#define REGISTER_LIST_SIZE	16

/* The stack is an array of 16 16-bit values */
#define STACK_SIZE		16

/* The Chip-8 has a 16-key hexadecimal keyboard */
#define KEY_LIST_SIZE		16

/* The Chip-8 has 36 instructions */
#define INSTRUCTIONS_SIZE	35

#define KEY_PRESSED		1
#define KEY_NOT_PRESSED		0

#define SCREEN_WIDTH		64
#define SCREEN_HEIGHT		32

/* Structure representing the state of the Chip8 CPU */
struct chip8 {
    uint8_t		memory[MEM_SIZE];
    uint8_t		regs[REGISTER_LIST_SIZE];
    uint16_t	reg_I;
    uint16_t	reg_PC;
    uint8_t		reg_delay;
    uint8_t		reg_sound;
    uint8_t		reg_SP;
    uint16_t	stack[STACK_SIZE];
    uint8_t		keyboard[KEY_LIST_SIZE];
    uint16_t	instr[INSTRUCTIONS_SIZE];
    uint16_t	instr_masks[INSTRUCTIONS_SIZE];

    uint8_t screen[SCREEN_WIDTH * SCREEN_HEIGHT];
    int wait_key;
};

void init_chip8(struct chip8 *chip8);
void init_font(struct chip8 *chip8);
void init_instructions(struct chip8 *chip8);
void step(struct chip8 *chip8);

#endif

