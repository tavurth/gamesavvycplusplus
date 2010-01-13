#include "../GSC.h"

using namespace gsc;

GLuint gsc::TEXTURE_WRAP_T;
GLuint gsc::TEXTURE_WRAP_S;
GLuint gsc::TEXTURE_MIN_FILTER;
GLuint gsc::TEXTURE_MAG_FILTER;

void   Texture::set_data(char * new_data)		 { data     = new_data; }
void   Texture::set_format(int new_format)		 { format   = new_format; }
void   Texture::set_width(short new_width)		 { width    = new_width; }
void   Texture::set_height(short new_height)		 { height   = new_height; }
void   Texture::set_bpp(short new_bpp)			 { bpp      = new_bpp; }
void   Texture::set_location(std::string new_location)   { location = new_location; }
void   Texture::set_id(GLuint new_id) 			 { id       = new_id; }

std::string Texture::get_location()  { return location; }
char * Texture::get_data()	     { return data; }
int    Texture::get_format()	     { return format; }
short  Texture::get_width()	     { return width; }
short  Texture::get_height()	     { return height; }
short  Texture::get_bpp()	     { return bpp; }
GLuint Texture::get_id()	     { return id; }

void Texture::check_texture(int error) {
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

void Texture::initialise() {
	glGenTextures(1, (GLuint *) &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexEnvf(GL_TEXTURE_2D, GL_TEXTURE_ENV, GL_BLEND);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, TEXTURE_WRAP_T);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, TEXTURE_WRAP_S);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, TEXTURE_MAG_FILTER);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, TEXTURE_MIN_FILTER);

	check_texture(gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, width, height, GL_BGRA, GL_UNSIGNED_BYTE, data));
}

void Texture::free_data() {
	free(data);
	data = NULL;
}

Texture::Texture () {
	data = NULL;
	width = height = bpp = id = format = 0;
	textureList.push_back(this);
}

Texture::~Texture() {
	if (data) 
		free(data);
	if (id) {
		glDeleteTextures(1, (const GLuint *) &id);
		id = 0;
	}
}
