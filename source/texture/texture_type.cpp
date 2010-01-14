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

#include "../GSC.h"

using namespace gsc;

std::vector<TextureType *> gsc::textureTypeList;

TextureType::TextureType(std::string newName, void (*newFunction)(std::string)) {
	name = newName;
	function = newFunction;

	textureTypeList.push_back(this);
}

TextureType::~TextureType() {
	std::vector<TextureType *>::iterator i;

	for (i=textureTypeList.begin(); i < textureTypeList.end(); i++)
		if (*i == this) {
			textureTypeList.erase(i);
			return;
		}
}

void (*TextureType::get_function())(std::string) const {
	return function;
}

std::string TextureType::get_name() const {
	return name;
}

void TextureType::set_function(void (*newFunction)(std::string)) {
	function = newFunction;
}

void TextureType::set_name(std::string newName) {
	name = newName;
}

//This function returns the correct function for loading a texture <type>
//Pass in "example.tga" and this function might return 'Texture * (* gsc::load::tga)(std::string location)'
void (*gsc::texture_type_find (std::string type))(std::string) {
	std::vector<TextureType *>::iterator i;

	for (i=textureTypeList.begin(); i < textureTypeList.end(); i++)
		if ((*i)->get_name().compare(type)) {
			return (*i)->get_function();
		}

	return NULL;
}
