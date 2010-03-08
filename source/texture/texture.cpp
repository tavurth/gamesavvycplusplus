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

std::vector<Texture *> gsc::textureList;

//Texture options
GLuint gsc::TEXTURE_WRAP_T     = GL_REPEAT;
GLuint gsc::TEXTURE_WRAP_S     = GL_REPEAT;
GLuint gsc::TEXTURE_MIN_FILTER = GL_LINEAR;
GLuint gsc::TEXTURE_MAG_FILTER = GL_LINEAR;

//Set functions
void   Texture::set_data(char * new_data) { if (data != NULL) free(data); data = new_data; }
void   Texture::set_format(int new_format)		 { format   = new_format; }
void   Texture::set_width(short new_width)		 { width    = new_width; }
void   Texture::set_height(short new_height)		 { height   = new_height; }
void   Texture::set_bpp(short new_bpp)			 { bpp      = new_bpp; }
void   Texture::set_location(std::string new_location)   { location = new_location; }
void   Texture::set_id(int new_id) 			 { id       = new_id; }

//Get functions
std::string Texture::get_location()  { return location; }
char * Texture::get_data()	     { return data; }
int    Texture::get_format()	     { return format; }
short  Texture::get_width()	     { return width; }
short  Texture::get_height()	     { return height; }
short  Texture::get_bpp()	     { return bpp; }

int Texture::get_id() { 
	if (!initialised)
		initialise(0);
	return id;
}

//Check texture for errors
void Texture::check () {
	switch (error) {
		case GL_NONE:
			return;
		case GL_INVALID_VALUE:
			utils::fatal("OpenGL Error -> GL_INVALID_VALUE");
		case GL_INVALID_ENUM:
			utils::fatal("OpenGL Error -> GL_INVALID_ENUM");
		case GL_INVALID_OPERATION:
			utils::fatal("OpenGL Error -> GL_INVALID_OPERATION");
		default:
			printf("OpenGL Error -> Unknown %d", error);
			utils::fatal("");
	}
}

//Setup texture parameters for initialisation
void Texture::setup_parameters () {

	//Texture environment
	glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV, GL_BLEND);

	//Texture wrap
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, TEXTURE_WRAP_T);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, TEXTURE_WRAP_S);

	//Texture filters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TEXTURE_MAG_FILTER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TEXTURE_MIN_FILTER);
}

//Initialise a texture (Create OpenGL id etc)
Texture * Texture::initialise(int freeData) {
	glGenTextures(1, (GLuint *) &id);
	glBindTexture(GL_TEXTURE_2D, id);

	//Setup texture parameters
	setup_parameters();

	//Create MipMaps and record any errors
	error = gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, format, GL_UNSIGNED_BYTE, data);
	
	//Check that the texture has been created properly
	this->check();

	if (freeData)
		this->free_data();

	initialised = 1;

	return this;
}

//Free any data that is saved in the texture
void Texture::free_data() {
	free(data);
	data = NULL;
}

//Constructor
Texture::Texture () {
	data = NULL;
	width = height = bpp = id = format = error = initialised = 0;
	textureList.push_back(this);
}

//Constructor
Texture::Texture (int newWidth, int newHeight, int newBpp) {
	data = NULL;
	width 		= newWidth;
	height 		= newHeight;
	bpp 		= newBpp;
	initialised 	= 0;
	textureList.push_back(this);
}

bool Texture::operator==(const Texture &to_find) const {
	return (*this == to_find);
}

//Returns the vector iterator of <t>
void Texture::erase () {
	std::vector<Texture *>::iterator i;

	for (i=textureList.begin(); i < textureList.end(); i++)
		if (*i == this) {
			textureList.erase(i);
			return;
		}
}

//Destructor
Texture::~Texture() {
	//Delte any data that has not been cleaned up earlier
	if (data) 
		free(data);

	//Delete OpenGL texture
	if (id) {
		glDeleteTextures(1, (const GLuint *) &id);
		id = 0;
	}

	//Delete texture from <textureList>
	this->erase();
}

//Return a previously loaded texture
Texture * texture_get (std::string location) {
	std::vector<Texture *>::iterator i;

	for (i=textureList.begin(); i < textureList.end(); i++)
		if ((*i)->get_location().compare(location))
			return *i;
       return NULL;	
}

//Delete all textures and clear the texture list
void gsc::texture_delete_all () {
	std::vector<Texture *>::iterator i;
	for (i = textureList.begin(); i < textureList.end(); i++)
		delete(*i);
	textureList.clear();
}
