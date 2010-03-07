#ifndef GSC_CONFIG
#define GSC_CONFIG

#include "../headers/GSC.h"

namespace gsc {
	double get_double (std::string line);
	int check_var (std::string line, std::string compare);
	void check_vars (std::string line);

	void new_config (std::string location);
	void load_config (const char * location);
	void load_config (std::string location);
}

#endif
