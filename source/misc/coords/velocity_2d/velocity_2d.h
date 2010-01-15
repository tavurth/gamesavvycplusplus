#ifndef GSC_VELOCITY_2D 
#define GSC_VELOCITY_2D

#include "../../../headers/GSC.h"

namespace gsc {
	class Velocity_2d {
		protected:
			double vX, vY;
		public:
			Velocity_2d();
			Velocity_2d(double newVX, double newVY);
			~Velocity_2d();

			void set(double, double);
			void set_vX(double);
			void set_vY(double);

			double get_vX() const;
			double get_vY() const;
	};
}

#endif
