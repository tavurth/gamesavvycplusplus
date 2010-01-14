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

Texture * load::tga (std::string location) {
	#ifdef GSC_DEBUG
		std::cout << "Loading TGA data from file: " << loc << " . . . " << endl;
	#endif

	//Temporary variables
	int size;
	unsigned short width, height, bpp;
	char * data;

	size = width = height = bpp = 0;

	//Open the tga file
	std::ifstream file (location.c_str(), std::ios::binary);
	if (!file) {
		std::cout << "Could not open file " << location << " for read." << std::endl;
		utils::fatal();
	}

	//Load width, height and bpp into temporary variables.
	file.seekg(12);
	file.read((char *) &width,  2);
	file.read((char *) &height, 2);
	file.read((char *) &bpp,    1);
	file.seekg(18, std::ios::beg);

	//Calculate size required for <data>
	bpp /= 8;
	size = width * height * bpp;

	//Allocate memory for <data>
	data = utils::new_str(size);

	//Read data from tga file into <data>
	file.read(data, size);

	if (file.gcount() < size) {
		free(data);
		std::cout << "Could not read all of data from file: " << location << 
		   		". Make sure you have saved the Image without RLE compression." << std::endl;
		utils::fatal();
	}
	file.close();
	
	//Copying all data into the texture
	Texture * texture = new Texture();
	texture->set_width(width);
	texture->set_height(height);
	texture->set_location(location);
	texture->set_data(data);
	texture->set_format(GL_BGRA);

	//Intialise the texture (Create OpenGL ID etc)
	texture->initialise();

	//Freeing our texture data as we no longer require it.
	texture->free_data();

	#ifdef GSC_DEBUG
		std::cout << "Done.\n" << endl;
	#endif

	return texture;
}
