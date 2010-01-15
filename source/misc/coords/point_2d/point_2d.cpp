#include "../../../headers/GSC.h"

using namespace gsc;

Point_2d::Point_2d() {
	x = y = 0;
}

Point_2d::Point_2d(double newX, double newY) {
	x = newX; y = newY;
}

Point_2d::~Point_2d() {
}

void Point_2d::set(double newX, double newY) {
	x = newX; y = newY;
}

void Point_2d::set_x(double newX) {
	x = newX;
}

void Point_2d::set_y(double newY) {
	y = newY;
}

double Point_2d::get_x() const {
	return x;
}

double Point_2d::get_y() const {
	return y;
} 
