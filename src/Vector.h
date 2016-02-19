
#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

struct Vector {
	float x;
	float y;

	Vector(float x, float y);

	float GetAngleRad();
	float GetMagnitude(bool sign_based_on_quadrant);
	int GetQuadrant();
};

#endif
