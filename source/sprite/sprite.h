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

#ifndef GSC_SPRITE
#define GSC_SPRITE

#include "../headers/GSC.h"

namespace gsc {
	class Sprite {
		private:
			Texture * mainTexture;
			char * get_piece (char * data, int startX, int startY, int width, int height);
			void mirror_horizontal();
		public:
			Sprite(std::string location, int flip_vert = 0);
			~Sprite();

			Texture * get_single(int x, int y, int width, int height, int flip_vert = 0);
			std::vector<Texture *> get_all(int sizeX, int sizeY, int flip_vert = 0);

			Texture * get_main_texture() const;
	};
}

#endif
