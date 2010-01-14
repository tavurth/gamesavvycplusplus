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

#ifndef GSC_TEXTURE_TYPE
#define GSC_TEXTURE_TYPE

#include "../GSC.h"

namespace gsc {

	typedef Texture * (*textureTypeFunc)(std::string);

	class TextureType { 
		std::string name;
		textureTypeFunc function;

		public:
			TextureType(std::string newName, textureTypeFunc newFunction);
			~TextureType();

			textureTypeFunc get_function() const;
			std::string get_name() const;

			void set_function(textureTypeFunc newFunction);
			void set_name(std::string newName);
	};

	extern std::vector<TextureType *> textureTypeList;
	std::string get_extension (std::string fullName);
	textureTypeFunc texture_type_find (std::string type);
	Texture * no_texture_type (std::string location);
	void texture_type_delete_all();
}

#endif
