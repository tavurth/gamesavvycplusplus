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

#ifndef GSC_VECTOR_2D 
#define GSC_VECTOR_2D

#include "../../headers/GSC.h"

namespace gsc {
	class Vector_2d {
		protected:
			double vX, vY;
		public:
			Vector_2d();
			Vector_2d(double newVX, double newVY);
			~Vector_2d();

			void set(double, double);
			void set_vX(double);
			void set_vY(double);
			
			void incf_vX(double);
			void incf_vY(double);

			void decf_vX(double);
			void decf_vY(double);

			double get_vX() const;
			double get_vY() const;
	};
}

#endif
