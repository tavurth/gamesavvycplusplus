#include "headers/main.h"

int main(int argc, char ** argv) {
	gsc::init(argc, argv);

	while (gsc::IS_RUNNING) {
		input();
		update();
		draw();
		SDL_Delay(50);
	}
}
