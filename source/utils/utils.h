//		Copyright (c) William Whitty 2010
//
//     This file is part of GSC. 
//
//     GSC is free software: you can redistribute it and/or modify
//     it under the terms of the GNU Lesser General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     GSC is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU Lesser General Public License for more details.
//
//     You should have received a copy of the GNU Lesser General Public License
//     along with GSC.  If not, see <http://www.gnu.org/licenses/>.

#ifndef GSC_UTILS
#define GSC_UTILS

#include "../headers/GSC.h"
#include "init.h"

namespace gsc {

	namespace utils {
		FILE * openBinaryFile(std::string location);
		void fatal(std::string error);
		void fatal();
		void * c_malloc(size_t size);
		char * new_str(int size);

		std::vector<std::string> get_file_text (const std::string location);
		std::vector<std::string> get_file_text (const char * location);

		double to_degrees(double radians);
		double to_radians(double degrees);
	}

}

#endif
