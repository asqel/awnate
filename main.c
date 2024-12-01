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

    int running = 1;
    while (running) {
        SDL_Event event;
        vec3_t looking_vector;
        vec3_t right_vector;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
                running = 0;
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    camera.pos.y += 0.2f;
                    break;
                case SDLK_LSHIFT:
                    camera.pos.y -= 0.2f;
                    break;
                case SDLK_w:
                    looking_vector = (vec3_t){0.0f, 0.0f, 0.2f};
                    looking_vector = rotateY(looking_vector, camera.roty);
                    looking_vector = rotateX(looking_vector, camera.rotx);
                    camera.pos.x += looking_vector.x;
                    camera.pos.y += looking_vector.y;
                    camera.pos.z += looking_vector.z;
                    break;
                case SDLK_s:
                    looking_vector = (vec3_t){0.0f, 0.0f, 0.2f};
                    looking_vector = rotateY(looking_vector, camera.roty);
                    looking_vector = rotateX(looking_vector, camera.rotx);
                    camera.pos.x -= looking_vector.x;
                    camera.pos.y -= looking_vector.y;
                    camera.pos.z -= looking_vector.z;
                    break;
                case SDLK_d:
                    right_vector = (vec3_t){0.2f, 0.0f, 0.0f};
                    right_vector = rotateY(right_vector, camera.roty);
                    camera.pos.x += right_vector.x;
                    camera.pos.y += right_vector.y;
                    camera.pos.z += right_vector.z;
                    break;
                case SDLK_a:
                    right_vector = (vec3_t){0.2f, 0.0f, 0.0f};
                    right_vector = rotateY(right_vector, camera.roty);
                    camera.pos.x -= right_vector.x;
                    camera.pos.y -= right_vector.y;
                    camera.pos.z -= right_vector.z;
                    break;
                }
            }
            else if (event.type == SDL_MOUSEMOTION) {
                int dx = -event.motion.xrel;
                int dy = event.motion.yrel;
                camera.rotx += dy / (float)SCREEN_WIDTH;
                camera.roty += dx / (float)SCREEN_HEIGHT;
            }
        }
        setbackground(0, 0, 0);
        render_object(&cube, &camera);
        update_screen();
    }
    return 0;
}
