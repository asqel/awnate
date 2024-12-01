#include "geometry.h"
#include <stdlib.h>

void new_cube(object_t *obj, vec3_t pos, double size, u8 r, u8 g, u8 b) {
	obj->pos = pos;
	obj->color.x = r;
	obj->color.y = g;
	obj->color.z = b;
	obj->data = NULL;
	obj->type = GEO_TYPE_CUBE;
	obj->mesh = malloc(sizeof(mesh3d_t));
	obj->mesh->vertices_len = 8;
	obj->mesh->vertices = malloc(obj->mesh->vertices_len * sizeof(vec3_t));
	obj->mesh->edges_len = 12;
	obj->mesh->edges = malloc(obj->mesh->edges_len * sizeof(u32_pair_t));
	obj->mesh->vertices[0] = (vec3_t){-size, -size, -size};
	obj->mesh->vertices[1] = (vec3_t){size, -size, -size};
	obj->mesh->vertices[2] = (vec3_t){size, size, -size};
	obj->mesh->vertices[3] = (vec3_t){-size, size, -size};
	obj->mesh->vertices[4] = (vec3_t){-size, -size, size};
	obj->mesh->vertices[5] = (vec3_t){size, -size, size};
	obj->mesh->vertices[6] = (vec3_t){size, size, size};
	obj->mesh->vertices[7] = (vec3_t){-size, size, size};
	obj->mesh->edges[0] = (u32_pair_t){0, 1};
	obj->mesh->edges[1] = (u32_pair_t){1, 2};
	obj->mesh->edges[2] = (u32_pair_t){2, 3};
	obj->mesh->edges[3] = (u32_pair_t){3, 0};
	obj->mesh->edges[4] = (u32_pair_t){4, 5};
	obj->mesh->edges[5] = (u32_pair_t){5, 6};
	obj->mesh->edges[6] = (u32_pair_t){6, 7};
	obj->mesh->edges[7] = (u32_pair_t){7, 4};
	obj->mesh->edges[8] = (u32_pair_t){0, 4};
	obj->mesh->edges[9] = (u32_pair_t){1, 5};
	obj->mesh->edges[10] = (u32_pair_t){2, 6};
	obj->mesh->edges[11] = (u32_pair_t){3, 7};
}

void destroy_object(object_t *obj) {
	free(obj->mesh->vertices);
	free(obj->mesh->edges);
	free(obj->mesh);
}