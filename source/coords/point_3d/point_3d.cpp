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

Point_3d::Point_3d() { x = y = 0; }
Point_3d::Point_3d(double newX, double newY, double newZ) : Point_2d(newX, newY) { z = newZ; }
Point_3d::~Point_3d() { }

void Point_3d::set(double newX, double newY, double newZ) { x = newX; y = newY; z = newZ; }
void Point_3d::set_z(double newZ) { z = newZ; }

void Point_3d::incf_z(double amount) { z += amount; }

void Point_3d::decf_z(double amount) { z -= amount; }

double Point_3d::get_z() const { return z; }

double Point_3d::get_dist(Point_3d * p2) const {
	double x2 = p2->get_x(), y2 = p2->get_y(), z2 = p2->get_z();
	return sqrt(((x2 - x) * (x2 - x)) + ((y2 - y) * (y2 - y)) + ((z2 - z) * (z2 - z)));
}

bool Point_3d::in_radius(Point_3d * p2, double radius) const {
	return (get_dist(p2) < radius);
}
