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

#ifndef GSC_RECT_2D
#define GSC_RECT_2D

#include "../../headers/GSC.h"

namespace gsc {
	class Rect_2d {
		protected:
			Point_2d * p1, * p2;
			double width, height;

		public:
			Rect_2d (double newX, double newY, double newW, double newH);
			~Rect_2d ();

			void set_p1(Point_2d * newP);
			void set_p2(Point_2d * newP);
			void set_width(double newWidth);
			void set_height(double newHeight);

			Point_2d * get_p1() const;
			Point_2d * get_p2() const;
			double     get_x() const;
			double     get_x2() const;
			double     get_y() const;
			double     get_y2() const;
			double	   get_width() const;
			double	   get_height() const;
	};
}

#endif
