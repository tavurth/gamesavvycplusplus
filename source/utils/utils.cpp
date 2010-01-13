#include "../GSC.h"
#include <fstream>

using namespace gsc;

void utils::fatal (std::string error) {
	if (error != "")
		std::cout << "GSC-FATAL -> " << error << std::endl;
	exit(1);
}

void utils::fatal () {
	exit(1);
}

void * utils::c_malloc(size_t size)
{
	void * p;

	if ((p = malloc(size)) == NULL) {
		std::cout << "malloc failed on size " << size << "." << std::endl;
		fatal();
	}

	return p;
}

char * utils::new_str(int n) {
	return (char *) c_malloc(sizeof(char) * (n + 2));
}
