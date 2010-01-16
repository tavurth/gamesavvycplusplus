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

#ifndef GSC_POINT_2D 
#define GSC_POINT_2D

#include "../../../headers/GSC.h"

namespace gsc {
	class Point_2d {
		protected:
			double x, y;
		public:
			Point_2d();
			Point_2d(double newX, double newY);
			~Point_2d();

			void set(double, double);
			void set_x(double);
			void set_y(double);

			double get_x() const;
			double get_y() const;

			double get_dist(Point_2d * p2) const;
	};
}

#endif
