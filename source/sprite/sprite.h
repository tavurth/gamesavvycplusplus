#ifndef GSC_SPRITE
#define GSC_SPRITE

#include "../headers/GSC.h"

namespace gsc {
	class Sprite {
		private:
			Texture * mainTexture;
			char * get_piece (char * data, int startX, int startY, int width, int height);
			void mirror_horizontal();
		public:
			Sprite(std::string location, int flip_vert = 0);
			~Sprite();

			Texture * get_single(int x, int y, int width, int height);
			std::vector<Texture *> get_all(int sizeX, int sizeY);

			Texture * get_main_texture() const;
	};
}

#endif
