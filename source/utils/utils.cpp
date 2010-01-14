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
//     along with GSC.  If not, see <http:##www.gnu.org/licenses/>.

#include "../GSC.h"

using namespace gsc;

void gsc::quit (int quitCode) {
	texture_delete_all();

	exit(quitCode);
}

void utils::fatal (std::string error) {
	if (error != "")
		std::cout << "GSC-FATAL -> " << error << std::endl;
	quit(1);
}

void utils::fatal () {
	std::cout << "GSC-FATAL" << std::endl;
	quit(1);
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
