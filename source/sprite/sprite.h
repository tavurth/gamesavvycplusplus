#ifndef GSC_SPRITE
#define GSC_SPRITE

#include "../headers/GSC.h"

namespace gsc {
	class Sprite {
		private:
			Texture * mainTexture;
			char * get_piece (char * data, int startX, int startY, int width, int height);
		public:
			Sprite(char * location);
			~Sprite();

			Texture * get_texture(int x, int y, int width, int height);
	};
}

#endif
