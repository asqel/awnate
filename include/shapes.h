#ifndef SHAPES_H
#define SHAPES_H

void draw_mesh3d(mesh3d_t *mesh, camera_t *camera, double fov, double aspect, vec3_t offset, double rotx, double roty);

void new_cube(object_t *obj, vec3_t pos, double size, u8 r, u8 g, u8 b);

void destroy_cube(object_t *obj);

void render_object(object_t *obj, camera_t *camera);
void render_object_with_rot(object_t *obj, camera_t *camera, double rotx, double roty);

#endif