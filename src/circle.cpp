#include <cstdint>
#include <cmath>
#include "circle.h"

Circle::Circle(double r) : radius(0.0), ference(0.0), area(0.0) {
	setRadius(r);
}

void Circle::setRadius(double r) {
	if (r >= 0) {
		radius = r;
		updateFerence();
		updateArea();
	}
}

void Circle::setFerence(double f) {
	if (f >= 0) {
		ference = f;
		radius = f / (2 * pi);
		updateArea();
	}
}

void Circle::setArea(double a) {
	if (a >= 0) {
		area = a;
		radius = sqrt(a / pi);
		updateFerence();
	}
}

double Circle::getRadius() const {
	return radius;
}

double Circle::getFerence() const {
	return ference;
}

double Circle::getArea() const {
	return area;
}

void Circle::updateFerence() {
	ference = 2 * pi * radius;
}

void Circle::updateArea() {
	area = pi * radius * radius;
}
