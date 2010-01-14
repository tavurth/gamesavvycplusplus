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
//     along with GSC.  If not, see <http:##www.gnu.org/licenses/>.

#ifndef GSC_TEXTURE_TYPE
#define GSC_TEXTURE_TYPE

#include "../GSC.h"

namespace gsc {

	class TextureType { 
		std::string name;
		void (*function)(std::string);

		public:
			TextureType(std::string newName, void (*newFunction)(std::string));
			~TextureType();

			void (*get_function())(std::string) const;
			std::string get_name() const;

			void set_function(void (*newFunction)(std::string));
			void set_name(std::string newName);
	};

	extern std::vector<TextureType *> textureTypeList;
	void (*texture_type_find (std::string type))(std::string);
}

#endif
