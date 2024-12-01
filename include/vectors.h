#ifndef VECTORS_H
#define VECTORS_H

#include "types.h"

typedef struct {
	double x;
	double y;
	double z;
} vec3_t;

typedef struct {
	double x;
	double y;
} vec2_t;

typedef struct {
	double *vals;
	u32 size;
} vecN_t;

vec3_t rotateY(vec3_t point, double angle);
vec3_t rotateX(vec3_t point, double angle);

#endif