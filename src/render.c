#include "geometry.h"
#include <math.h>
#include "graphic.h"
#include "vectors.h"
vec2_t project(vec3_t point, double fov, double aspect, double znear) {
    double scale = fov / point.z;
    return (vec2_t){
        .x = point.x * scale * aspect + SCREEN_WIDTH / 2,
        .y = -point.y * scale + SCREEN_HEIGHT / 2};
}

vec3_t translate(vec3_t point, vec3_t cameraPos) {
    return (vec3_t){
        .x = point.x - cameraPos.x,
        .y = point.y - cameraPos.y,
        .z = point.z - cameraPos.z};
}

void draw_mesh3d(mesh3d_t *mesh, camera_t *camera, double fov, double aspect) {
	for (uint32_t i = 0; i < mesh->edges_len; i++) {
		u32_pair_t edge = mesh->edges[i];

		if (edge.a == edge.b) continue;
		if (edge.a >= mesh->vertices_len || edge.b >= mesh->vertices_len) continue;

		vec3_t p1 = translate(mesh->vertices[edge.a], camera->pos);
        vec3_t p2 = translate(mesh->vertices[edge.b], camera->pos);

        // Appliquer les rotations de la caméra
        p1 = rotateX(rotateY(p1, -camera->roty), -camera->rotx);
        p2 = rotateX(rotateY(p2, -camera->roty), -camera->rotx);

        if (p1.z > 0 && p2.z > 0) { // Éviter les points derrière la caméra
            vec2_t proj1 = project(p1, fov, aspect, 0.1f);
            vec2_t proj2 = project(p2, fov, aspect, 0.1f);
            DRAW_LINE_FAST((int)proj1.x, (int)proj1.y, (int)proj2.x, (int)proj2.y);
        }
	}
}

void render_object(object_t *obj, camera_t *camera) {
    SET_COLOR_FAST(obj->color.x, obj->color.y, obj->color.z);
    draw_mesh3d(obj->mesh, camera, 200, 1);
}