#include <SDL2/SDL.h>
#include <math.h>

#include "graphic.h"
#include "geometry.h"
#include "shapes.h"
#include "vectors.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetRelativeMouseMode(SDL_TRUE);

    init_graphic(SCREEN_WIDTH, SCREEN_HEIGHT);

    camera_t camera;
    camera.pos.x = 0;
    camera.pos.y = 0;
    camera.pos.z = -5;
    camera.rotx = 0;
    camera.roty = 0;

    object_t cube;
    new_cube(&cube, (vec3_t){0, 0, 0}, 1, 255, 0, 0);
    object_t player;
    new_cube(&player, (vec3_t){0, 0, 0}, 0.5, 0, 0, 255);

    vec3_t looking_vector = rotateX(rotateY((vec3_t){0, 0, 1}, camera.roty), camera.rotx);
    vec3_t right_vector = rotateX(rotateY((vec3_t){1, 0, 0}, camera.roty), camera.rotx);
    camera.pos = add_vec3(mul_vec3(looking_vector, -1), camera.pos);
    camera.pos.y += 1.5;

    int running = 1;
    while (running) {
        SDL_Event event;
        vec3_t tmp;

        looking_vector = rotateX(rotateY((vec3_t){0, 0, 1}, camera.roty), camera.rotx);
        right_vector = rotateX(rotateY((vec3_t){1, 0, 0}, camera.roty), camera.rotx);
        camera.pos = add_vec3(mul_vec3(looking_vector, -1), player.pos);
        camera.pos.y += 1.5;
       // printf("%d %d %d | %d %d %d\n", camera.pos.x, camera.pos.y, camera.pos.z, player.pos.x, player.pos.y, player.pos.z);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
                running = 0;
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    player.pos.y += 0.2;
                    break;
                case SDLK_LSHIFT:
                    player.pos.y -= 0.2;
                    break;
                case SDLK_w:
                    tmp = mul_vec3(looking_vector, 0.2), camera.roty;
                    player.pos.x += tmp.x;
                    player.pos.z += tmp.z;
                    break;
                case SDLK_s:
                    tmp = mul_vec3(looking_vector, 0.2), camera.roty;
                    player.pos.x -= tmp.x;
                    player.pos.z -= tmp.z;
                    break;
                case SDLK_d:
                    tmp = mul_vec3(right_vector, 0.2), camera.roty;
                    player.pos.x += tmp.x;
                    player.pos.z += tmp.z;
                    break;
                case SDLK_a:
                    tmp = mul_vec3(right_vector, 0.2), camera.roty;
                    player.pos.x -= tmp.x;
                    player.pos.z -= tmp.z;
                    break;
                }
            }
            else if (event.type == SDL_MOUSEMOTION) {
                int dx = -event.motion.xrel;
                int dy = event.motion.yrel;
                camera.rotx += dy / (float)SCREEN_WIDTH;
                camera.roty += dx / (float)SCREEN_HEIGHT;
                looking_vector = rotateX(rotateY((vec3_t){0, 0, 1}, camera.roty), camera.rotx);
                right_vector = rotateX(rotateY((vec3_t){1, 0, 0}, camera.roty), camera.rotx);
                camera.pos = add_vec3(mul_vec3(looking_vector, -1), player.pos);
                camera.pos.y += 1.5;
            }
        }
        setbackground(0, 0, 0);
        render_object(&cube, &camera);
        render_object_with_rot(&player, &camera, 0, camera.roty);
        update_screen();
    }
    return 0;
}
