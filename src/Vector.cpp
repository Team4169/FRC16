#include "Vector.h"
#include <Math.h>

Vector::Vector(float x, float y): x(x), y(y) {};

float Vector::GetAngleRad() {
	return atan2(y, x);
}

float Vector::GetMagnitude(bool sign_based_on_quadrant) {
	float magnitude = sqrt(pow(x, 2) + pow(y, 2));

	if(sign_based_on_quadrant && GetQuadrant() > 2) {
		magnitude *= -1;
	}

	return magnitude;
}

int Vector::GetQuadrant() {
	if(x >= 0 && y >= 0) {
		return 1;
	} else if(x < 0 && y > 0) {
		return 2;
	} else if(x < 0 && y < 0) {
		return 3;
	} else {
		return 4;
	}
}
