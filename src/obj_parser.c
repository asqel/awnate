#include "geometry.h"
#include "types.h"
#include <stdlib.h>


vec3_t parse_vertex(const char *text, u32 *p) {
	char *endptr;
	vec3_t res = (vec3_t){0, 0, 0};
	// get x (float)
	res.x = strtod(&text[*p], &endptr);
	*p += endptr - &text[*p];
	// get y (float)
	res.y = strtod(&text[*p], &endptr);
	*p += endptr - &text[*p];
	// get z (float)
	res.z = strtod(&text[*p], &endptr);
	*p += endptr - &text[*p];
	return res;
}

object_t *read_obj(const char *text) {
	u32 p = 0;
	object_t *res = malloc(sizeof(object_t));
	res->color = (vec3_t){255, 255, 255};
	res->data = NULL;
	res->pos = (vec3_t){0, 0, 0};
	res->type = GEO_TYPE_NONE;
	res->mesh = malloc(sizeof(mesh3d_t));
	res->mesh->edges_len = 0;
	res->mesh->vertices_len = 0;
	res->mesh->edges = NULL;
	res->mesh->vertices = NULL;
	u32 edges_alloc_size = 0;
	u32 vertices_alloc_size = 0;

	while (text[p] != '\0') {
		if (text[p] == '\n' || text[p] == '\r')
			p++;
		else if (text[p] == '#') {
			while (text[p] != '\n' && text[p] != '\0') {
				p++;
			}
		}
		else if (text[p] == 'v') {
			if (text[p + 1] == ' ') {
				p += 2;
				res->mesh->vertices_len++;
				if (res->mesh->vertices_len > vertices_alloc_size) {
					vertices_alloc_size += 32;
					res->mesh->vertices = realloc(res->mesh->vertices, vertices_alloc_size * sizeof(vec3_t));
				}
				res->mesh->vertices[res->mesh->vertices_len - 1] = parse_vertex(text, &p);
			}
		}

	}
}