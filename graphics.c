#include "graphics.h"
/**
 * Initializes the graphics. Probably could use some gotos here for cleanup. 
 */
int init_graphics(struct graphics *graphics)
{
	graphics->window = SDL_CreateWindow("Chip-b8",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						SCREEN_WIDTH * 10,
						SCREEN_HEIGHT * 10,
						0);
	if (graphics->window == NULL) {
		return 1;
	}

	graphics->renderer = SDL_CreateRenderer(graphics->window, 
						-1, 
						SDL_RENDERER_ACCELERATED);
	if (graphics->renderer == NULL) {
		SDL_DestroyWindow(graphics->window);
		return 1;
	}

	graphics->texture = SDL_CreateTexture(graphics->renderer,
						SDL_PIXELFORMAT_RGBA8888,
						SDL_TEXTUREACCESS_STREAMING,
						SCREEN_WIDTH,
						SCREEN_HEIGHT);
	if (graphics->texture == NULL) {
		SDL_DestroyRenderer(graphics->renderer);
		SDL_DestroyWindow(graphics->window);
		return 1;
	}

	return 0;
						
}

/**
 * Cleanup function for graphics object.
 */
void destroy_graphics(struct graphics *graphics)
{
	SDL_DestroyTexture(graphics->texture);
	SDL_DestroyRenderer(graphics->renderer);
	SDL_DestroyWindow(graphics->window);
}

/**
 * Renders whatever is on the chip8 screen.
 */
void render(struct graphics *graphics, struct chip8 *chip8)
{
	int i;
	void *pixels;
	int pitch;

	SDL_LockTexture(graphics->texture,
			NULL,
			&pixels,
			&pitch);
	uint32_t *pix = pixels;
	for (i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); i++) {
		if (chip8->screen[i] == 0) {
			pix[i] = 0;
		} else {
			pix[i] = -1;
		}
	}
	SDL_UnlockTexture(graphics->texture);

	SDL_RenderClear(graphics->renderer);
	SDL_RenderCopy(graphics->renderer, graphics->texture, NULL, NULL);
	SDL_RenderPresent(graphics->renderer);
}
