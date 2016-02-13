#include "chip8.h"
#include "input.h"

uint8_t keys[] = {
    SDL_SCANCODE_X, // 0
    SDL_SCANCODE_1, // 1
    SDL_SCANCODE_2,	// 2
    SDL_SCANCODE_3,	// 3
    SDL_SCANCODE_Q,	// 4
    SDL_SCANCODE_W,	// 5
    SDL_SCANCODE_E,	// 6
    SDL_SCANCODE_A,	// 7
    SDL_SCANCODE_S, // 8
    SDL_SCANCODE_D, // 9
    SDL_SCANCODE_Z, // A
    SDL_SCANCODE_C, // B
    SDL_SCANCODE_4, // C
    SDL_SCANCODE_R, // D
    SDL_SCANCODE_F, // E
    SDL_SCANCODE_V  // F
};

/**
 * Function to detect if a specific key is being pressed down.
 *
 * @param key The key you want to check the status of.
 * @return 1 if it is being pressed down. 0 otherwise.
 */
int keydown(int key)
{
    const Uint8 *sdl_keys = SDL_GetKeyboardState(NULL);
    return sdl_keys[keys[key]];
}

