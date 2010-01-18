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

Rect_2d::Rect_2d (double newX, double newY, double newW, double newH) {
	p1 = new Point_2d(newX, 	newY);
	p2 = new Point_2d(newX + newW,  newY + newH);

	width  = newW;
	height = newH;
}

Rect_2d::~Rect_2d () {
	delete p1;
	delete p2;
}

void	   Rect_2d::set_p1(Point_2d * newP) { p1 = newP; }
void	   Rect_2d::set_p2(Point_2d * newP) { p2 = newP; }
void	   Rect_2d::set_width(double newWidth) { width = newWidth; p2->set_x(p1->get_x() + width); }
void	   Rect_2d::set_height(double newHeight) { height = newHeight; p2->set_y(p1->get_y() + height); }

double        Rect_2d::get_x() const { return p1->get_x(); }
double        Rect_2d::get_x2() const { return p2->get_x(); }
double        Rect_2d::get_y() const { return p1->get_y(); }
double        Rect_2d::get_y2() const { return p2->get_y(); }

Point_2d * Rect_2d::get_p1() const { return p1; }
Point_2d * Rect_2d::get_p2() const { return p2; }
double	   Rect_2d::get_width() const { return width; }
double	   Rect_2d::get_height() const { return height; }
