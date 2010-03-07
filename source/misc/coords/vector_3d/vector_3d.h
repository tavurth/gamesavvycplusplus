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

#ifndef GSC_VECTOR_3D 
#define GSC_VECTOR_3D

#include "../../../headers/GSC.h"

namespace gsc {
	class Vector_3d : public Vector_2d {
		protected:
			double vZ;
		public:
			Vector_3d();
			Vector_3d(double newVX, double newVY, double newVZ);
			~Vector_3d();

			void set(double, double, double);
			void set_vZ(double);

			void incf_vZ(double);
			void decf_vZ(double);

			double get_vZ() const;
	};
}

#endif
