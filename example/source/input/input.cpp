#include "input.h"

void input() {
	SDL_PumpEvents();

	if (gsc::keys[SDLK_ESCAPE])
		gsc::IS_RUNNING = 0;
}
