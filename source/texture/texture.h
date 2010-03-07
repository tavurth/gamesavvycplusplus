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

#ifndef GSC_TEXTURE
#define GSC_TEXTURE

#include "../headers/GSC.h"

namespace gsc {

	class Texture { 
		char * data;
		std::string location;
		short width, height, bpp;
		int id, format, error;

		void check();
		void setup_parameters();

		public:
			Texture();
			Texture (int newWidth, int newHeight, int newBpp);
			~Texture();
			Texture * initialise();
			void free_data();
			void erase();

			bool operator==(const Texture &to_find) const;

			void set_data(char *);
			void set_location(std::string);
			void set_width(short);
			void set_height(short);
			void set_bpp(short);
			void set_format(int);
			void set_id(int);

			char * get_data();
			int    get_format();
			short  get_width();
			short  get_height();
			short  get_bpp();
			int    get_id();
			std::string get_location();
	};

	extern GLuint TEXTURE_WRAP_T;
	extern GLuint TEXTURE_WRAP_S;
	extern GLuint TEXTURE_MIN_FILTER;
	extern GLuint TEXTURE_MAG_FILTER;

	void texture_delete_all();
	Texture * texture_get(std::string location);
	
	extern std::vector<Texture *> textureList;

}

#endif
