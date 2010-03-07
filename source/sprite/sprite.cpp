#include "../headers/GSC.h"

using namespace gsc;

Sprite::Sprite(char * location) {
	mainTexture = load::texture(location, 0);
}

Sprite::~Sprite() {
	delete(mainTexture);
}

//Return peice <startX, startY> <width, height> of texture <data>
char * Sprite::get_piece (char * data, int startX, int startY, int width, int height) {
	int textureWidth = mainTexture->get_width(), textureHeight = mainTexture->get_height(), textureBpp = mainTexture->get_bpp();

	char * start = data + (startX * textureBpp + startY * textureWidth);
	char * temp = utils::new_str(width * height * textureBpp);

	for (int y = startY; y < textureHeight; y++) {
		for (int x = startX * textureBpp; x < textureWidth * textureBpp; x++) 
			*(temp)++ = *(start)++;
		start += width * textureBpp;
	}

	return temp;
}

Texture * Sprite::get_texture(int x, int y, int width, int height) {
	Texture * temp = new Texture(width, height, mainTexture->get_bpp());

	temp->set_data(get_piece(mainTexture->get_data(), x, y, width, height));
	return temp->initialise();
}
