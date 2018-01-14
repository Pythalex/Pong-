#include "math.hpp"

void symmetryHorizontal(float *x, float *y) {
	*x = -(*x);
}

void symmetryVertical(float *x, float *y) {
	*y = -(*y);
}

void negative(float *x, float *y) {
	*x = -(*x);
	*y = -(*y);
}

void rotation(float *x, float *y, float angle) {
	float newX = (*x * cos(angle) - *y * sin(angle));
	float newY = (*x * sin(angle) + *y * cos(angle));
}

void normalize(float *x, float *y) {
	float norm = vecNorm(*x, *y);
	*x = *x / norm;
	*y = *y / norm;
}

float vecNorm(float x, float y) {
	return sqrt(x * x + y * y);
}