#include "../headers/GSC.h"

using namespace gsc;

void copy_line(char * copyTo, char * copyFrom, int size) {
	//Copy a single line from <copyFrom> into <copyTo> of length <size>;
	//The reason this function exists is that strcpy stops on "\0";
	for (int i=0; i < size; i++)
		*(copyTo)++ = *(copyFrom)++;
}

//Flip a sprite vertically
void flip_vertically (Texture * t) {
	int width  = t->get_width();
	int height = t->get_height();
	int bpp    = t->get_bpp();

	char * pointer, * pointer2, * tempData, * data = t->get_data();
       
	pointer = tempData = utils::new_str(width * bpp * t->get_height());

	for (int y = height; y > 0; y--) {
		pointer2 = data + (y * width * bpp);
		copy_line(pointer, pointer2, width * bpp);
		pointer += width * bpp;
	}
	
	t->set_data(tempData);
}

Sprite::Sprite(std::string location, int flip_vert) {
	mainTexture = load::texture(location, 0);

	if (flip_vert)
		flip_vertically(mainTexture);
}

Sprite::~Sprite() {
	delete(mainTexture);
}

Texture * Sprite::get_main_texture() const {
	return mainTexture;
}

//Return peice <startX, startY> <width, height> of texture <data>
char * Sprite::get_piece (char * data, int startX, int startY, int width, int height) {
	int textureWidth = mainTexture->get_width(), textureBpp = mainTexture->get_bpp();

	char * newPosition, * oldPosition, * newData;

	int squareSizeX = width		* textureBpp;
	int parentSizeX = textureWidth  * textureBpp;

	oldPosition = data + (startY * parentSizeX) + (startX * textureBpp);
	newPosition = newData = utils::new_str(width * height * textureBpp);

	for (int i = 0; i < height; i++) {
		copy_line(newPosition, oldPosition, squareSizeX);

		oldPosition += parentSizeX;
		newPosition += squareSizeX;
	}

	return newData;
}

Texture * Sprite::get_single(int x, int y, int width, int height) {

	Texture * temp = new Texture(width, height, mainTexture->get_bpp());

	temp->set_data(get_piece(mainTexture->get_data(), x, y, width, height));
	temp->set_format(mainTexture->get_format());
	temp->set_location(mainTexture->get_location());

	return temp->initialise(0);
}

std::vector<Texture *> Sprite::get_all(int sizeX, int sizeY) {
	std::vector<Texture *> textures;

	for (int y = 0; y < sizeY; y++)
		for (int x = 0; x < sizeX; x++)
			textures.push_back(get_single(x * sizeX, y * sizeY, sizeX, sizeY));

	return textures;
}
