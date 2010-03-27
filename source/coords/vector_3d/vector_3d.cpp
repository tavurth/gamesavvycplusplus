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

#include "../../headers/GSC.h"

using namespace gsc;

Vector_3d::Vector_3d() : Vector_2d() {
	vZ = 0;
}

Vector_3d::Vector_3d(double newVX, double newVY, double newVZ) : Vector_2d(newVX, newVY) {
	vZ = newVZ;
}

Vector_3d::~Vector_3d() {
}

void Vector_3d::set(double newVX, double newVY, double newVZ) {
	vX = newVX; vY = newVY; vZ = newVZ;
}

void Vector_3d::set_vZ(double newVZ) {
	vZ = newVZ;
}

void Vector_3d::incf_vZ(double amount) {
	vZ += amount;
}

void Vector_3d::decf_vZ(double amount) {
	vZ -= amount;
}

double Vector_3d::get_vZ() const {
	return vZ;
} 
