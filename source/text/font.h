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

#ifndef GSC_TEXT
#define GSC_TEXT

#include "../headers/GSC.h"

namespace gsc {
	class Font {
		private:
			std::vector<Texture *> letters;
			double size;
			double gap;

		public:
			Font(std::string location, int newSize = 16);
			~Font();

			void set_size(double newSize);
			double get_size() const;

			void write(std::string text, int x, int y, int z = 0);
	};
}

#endif
