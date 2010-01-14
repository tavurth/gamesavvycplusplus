#include "../GSC.h"

using namespace gsc;

Texture * load::texture (std::string location) {
	return (* texture_type_find(location))(location);
}
