//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

#include "../headers/GSC.h"

using namespace gsc;

void gsc::init_texture_types () {
	new TextureType("tga", &tga::load);
}

void init_perspective () {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(gsc::SCREEN_FOV, gsc::SCREEN_WIDTH/gsc::SCREEN_HEIGHT, gsc::SCREEN_ASPECT_NEAR, gsc::SCREEN_ASPECT_FAR);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int gsc::init (int argc, char ** argv) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	init_globals();

	if (SDL_SetVideoMode(gsc::SCREEN_WIDTH, gsc::SCREEN_HEIGHT, gsc::SCREEN_BPP, SDL_OPENGL) == NULL)
		return 1;

	init_perspective();
	init_texture_types();
	glEnable(GL_BLEND);
	glEnable(GL_TEXTURE_2D);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	timeline::init();
	
	return 0;
}

int gsc::init () {
	return init(0, NULL);
}

void gsc::quit (int quitCode) {
	texture_delete_all();
	texture_type_delete_all();
	network_delete_all();

	exit(quitCode);
}

void gsc::net_error() {
	std::cout << "SDLNet error: " << SDLNet_GetError();
	gsc::quit();
}

void gsc::thread_error() {
	std::cout << "SDL thread error: " << SDL_GetError();
	gsc::quit();
}
