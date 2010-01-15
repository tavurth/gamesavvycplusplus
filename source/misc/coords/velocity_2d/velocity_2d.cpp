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
