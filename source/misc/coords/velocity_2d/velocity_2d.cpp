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

Velocity_2d::Velocity_2d() {
	vX = vY = 0;
}

Velocity_2d::Velocity_2d(double newVX, double newVY) {
	vX = newVX; vY = newVY;
}

Velocity_2d::~Velocity_2d() {
}

void Velocity_2d::set(double newVX, double newVY) {
	vX = newVX; vY = newVY;
}

void Velocity_2d::set_vX(double newVX) {
	vX = newVX;
}

void Velocity_2d::set_vY(double newVY) {
	vY = newVY;
}

double Velocity_2d::get_vX() const {
	return vX;
}

double Velocity_2d::get_vY() const {
	return vY;
} 
