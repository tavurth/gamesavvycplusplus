#include "../GSC.h"

using namespace gsc;

//Texture options
GLuint gsc::TEXTURE_WRAP_T;
GLuint gsc::TEXTURE_WRAP_S;
GLuint gsc::TEXTURE_MIN_FILTER;
GLuint gsc::TEXTURE_MAG_FILTER;

//Set functions
void   Texture::set_data(char * new_data)		 { data     = new_data; }
void   Texture::set_format(int new_format)		 { format   = new_format; }
void   Texture::set_width(short new_width)		 { width    = new_width; }
void   Texture::set_height(short new_height)		 { height   = new_height; }
void   Texture::set_bpp(short new_bpp)			 { bpp      = new_bpp; }
void   Texture::set_location(std::string new_location)   { location = new_location; }
void   Texture::set_id(GLuint new_id) 			 { id       = new_id; }

//Get functions
std::string Texture::get_location()  { return location; }
char * Texture::get_data()	     { return data; }
int    Texture::get_format()	     { return format; }
short  Texture::get_width()	     { return width; }
short  Texture::get_height()	     { return height; }
short  Texture::get_bpp()	     { return bpp; }
GLuint Texture::get_id()	     { return id; }

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
void Texture::initialise() {
	glGenTextures(1, (GLuint *) &id);
	glBindTexture(GL_TEXTURE_2D, id);

	//Setup texture parameters
	setup_parameters();

	//Create MipMaps and record any errors
	error = gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_BGRA, GL_UNSIGNED_BYTE, data);
	
	//Check that the texture has been created properly
	this->check();
}

//Free any data that is saved in the texture
void Texture::free_data() {
	free(data);
	data = NULL;
}

//Constructor
Texture::Texture () {
	data = NULL;
	width = height = bpp = id = format = error = 0;
	textureList.push_back(this);
}

//Destructor
Texture::~Texture() {
	if (data) 
		free(data);
	if (id) {
		glDeleteTextures(1, (const GLuint *) &id);
		id = 0;
	}
}

//Delete all textures and clear the texture list
void gsc::texture_delete_all () {
	std::vector<Texture *>::iterator i;
	for (i = textureList.begin(); i < textureList.end(); i++)
		delete(*i);
	textureList.clear();
}
