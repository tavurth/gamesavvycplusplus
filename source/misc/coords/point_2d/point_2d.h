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
	};
}

#endif
