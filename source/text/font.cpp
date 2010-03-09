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
