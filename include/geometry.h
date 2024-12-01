#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "vectors.h"
#include "types.h"

typedef struct {
	vec3_t pos;
	double rotx;
	double roty;
} camera_t;

typedef struct {
	vec3_t *vertices;
	u32_pair_t *edges;
	u32 vertices_len;
	u32 edges_len;
} mesh3d_t;

typedef struct {
	vec3_t pos;
	mesh3d_t *mesh;
	vec3_t color;
	u32 type; // optional
	void *data;
} object_t;

enum {
	GEO_TYPE_NONE,
	GEO_TYPE_CUBE,
};

#endif