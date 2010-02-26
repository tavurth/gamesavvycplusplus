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

Uint8 * gsc::keys;

int gsc::SCREEN_WIDTH;
int gsc::SCREEN_HEIGHT;
int gsc::SCREEN_BPP;
int gsc::SCREEN_FOV;
int gsc::SCREEN_ASPECT_NEAR;
int gsc::SCREEN_ASPECT_FAR;

int gsc::IS_RUNNING;

void gsc::init_globals() {
	gsc::keys = SDL_GetKeyState(NULL);

	gsc::SCREEN_WIDTH		= 1024;
	gsc::SCREEN_HEIGHT		= 512;
	gsc::SCREEN_BPP			= 32;
	gsc::SCREEN_FOV			= 90;
	gsc::SCREEN_ASPECT_NEAR		= 0.1;
	gsc::SCREEN_ASPECT_FAR		= 10000;

	gsc::IS_RUNNING			= 1;
}
