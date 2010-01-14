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

#include "../GSC.h"

using namespace gsc;

std::vector<TextureType *> gsc::textureTypeList;

TextureType::TextureType(std::string newName, textureTypeFunc newFunction) {
	name = newName;
	function = newFunction;

	textureTypeList.push_back(this);
}

TextureType::~TextureType () {
	std::vector<TextureType *>::iterator i;

	for (i=textureTypeList.begin(); i < textureTypeList.end(); i++)
		if (*i == this) {
			textureTypeList.erase(i);
			return;
		}
}

textureTypeFunc TextureType::get_function () const {
	return function;
}

std::string TextureType::get_name () const {
	return name;
}

void TextureType::set_function (textureTypeFunc newFunction) {
	function = newFunction;
}

void TextureType::set_name (std::string newName) {
	name = newName;
}

std::string gsc::get_extension (std::string fullName) {
	return fullName.substr(fullName.find_last_of(".")+1);
}

Texture * gsc::no_texture_type (std::string location) {
	std::cout << "Sorry, no texture type available for loading texture: " << location << std::endl;
	return NULL;
}

//This function returns the correct function for loading a texture <type>
//Pass in "example.tga" and this function might return 'Texture * (* gsc::load::tga)(std::string location)'
textureTypeFunc gsc::texture_type_find (std::string fullName) {
	std::string extension = get_extension(fullName);

	std::vector<TextureType *>::iterator i;

	for (i=textureTypeList.begin(); i < textureTypeList.end(); i++)
		if (!((*i)->get_name().compare(extension)))
			return ((*i)->get_function());
	return &no_texture_type;
}
