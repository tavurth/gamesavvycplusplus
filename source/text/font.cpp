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

Font::Font(std::string location, int newSize) {
	Sprite * temp = new Sprite(location);

	size = newSize;
	letters = temp->get_all(size, size, 1);

	delete(temp);
}

Font::~Font() {
	std::vector<Texture *>::iterator it;

	for (it = letters.begin(); it < letters.end(); it++)
		delete(*it);
	letters.clear();
}

void Font::set_size(double newSize) { size = newSize; }
double Font::get_size() const { return size; }

void Font::write(std::string text, int x, int y, int z) {
	const char * string = text.c_str();

	for (unsigned int i = 0; i < text.length(); i++)
		draw::texture(letters[string[i]], x + i * size * 0.85, y, z, size, size);
}
