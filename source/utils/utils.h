#ifndef GSC_UTILS
#define GSC_UTILS

#include "../GSC.h"

namespace gsc {

	namespace utils {
		FILE * openBinaryFile(std::string location);
		void   fatal(std::string error);
		void   fatal();
		void * c_malloc(size_t size);
		char * new_str(int size);
	}

	void quit(int quitCode = 0);

}

#endif
