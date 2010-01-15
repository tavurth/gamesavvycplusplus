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

#include "../../../headers/GSC.h"

using namespace gsc;

Point_2d::Point_2d() {
	x = y = 0;
}

Point_2d::Point_2d(double newX, double newY) {
	x = newX; y = newY;
}

Point_2d::~Point_2d() {
}

void Point_2d::set(double newX, double newY) {
	x = newX; y = newY;
}

void Point_2d::set_x(double newX) {
	x = newX;
}

void Point_2d::set_y(double newY) {
	y = newY;
}

double Point_2d::get_x() const {
	return x;
}

double Point_2d::get_y() const {
	return y;
} 
