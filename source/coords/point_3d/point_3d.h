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

#ifndef GSC_POINT_3D 
#define GSC_POINT_3D

#include "../../headers/GSC.h"

namespace gsc {
	class Point_3d : public Point_2d {
		protected:
			double z;
		public:
			Point_3d();
			Point_3d(double newX, double newY = 0, double newZ = 0);
			~Point_3d();

			void set(double, double, double);
			void set_z(double);

			void incf_z(double = 1);
			void decf_z(double = 1);

			double get_z() const;

			double get_dist(Point_3d * p2) const;

			bool   in_radius(Point_3d * p2, double radius) const;
			bool   in_rect(Rect_2d * r) const;
			bool   in_rect(double x1, double y1, double w, double h) const;
	};
}

#endif
