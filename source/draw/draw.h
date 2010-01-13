#ifndef GSC_DRAW
#define GSC_DRAW

#include "../GSC.h"

namespace gsc {

	namespace draw {
		void rect(float x, float y, float w, float h);
		void texture(Texture * tex, float x, float y, float z, float w, float h);
	}

}

#endif
