#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <SDL.h>
#include "chip8.h"

struct graphics {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};

int init_graphics(struct graphics *graphics);
void destroy_graphics(struct graphics *graphics);
void render(struct graphics *graphics, struct chip8 *chip8);

#endif

