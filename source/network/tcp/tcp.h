#ifndef GSC_TCP
#define GSC_TCP

#include "../../headers/GSC.h"

namespace gsc {
	namespace tcp {
		class Client;
		class Host;
		class Remote;

		typedef void (*host_function)(Client *);
		extern const int IS_ACTIVE;
	}
}

#endif
