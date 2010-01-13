#ifndef GSC_UTILS
#define GSC_UTILS

#include "../GSC.h"

namespace gsc {

	namespace utils {
		FILE * openBinaryFile(std::string);
		void   fatal(std::string error);
		void   fatal();
		void * c_malloc(size_t);
		char * new_str(int);
	}

}

#endif
