#ifndef MATH_HPP_INCLUDED
#define MATH_HPP_INCLUDED

#include <cmath>

void symmetryHorizontal(float *x, float *y);

void symmetryVertical(float *x, float *y);

void negative(float *x, float *y);

void rotation(float *x, float *y, float angle);

void normalize(float *x, float *y);

float vecNorm(float x, float y);

#endif