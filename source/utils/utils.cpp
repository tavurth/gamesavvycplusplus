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

#include "../headers/GSC.h"

using namespace gsc;

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

std::vector<std::string> utils::get_file_text (const char * location) {
	std::ifstream in (location);
	std::vector<std::string> lines;
	char temp[2048];

	if (in.is_open())
		while (!in.eof()) {
			in.getline(temp, 2048, '\n');
			lines.push_back(temp);
		}
	else
		std::cout << "Could not open file " << location << "." << std::endl;

	return lines;
}

std::vector<std::string> utils::get_file_text (const std::string location) {
	return get_file_text(location.c_str());
}

#define twoPI (M_PI * 2)

double utils::to_degrees(double radians) {
	return (radians / twoPI) * 360.0;
}

double utils::to_radians(double degrees) {
	return (degrees / 360.0) * twoPI;
}
