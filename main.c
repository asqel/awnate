#include <SDL2/SDL.h>
#include <math.h>
#include "libs/cube.h"
#include "libs/2dscreen.h"


const int WIDTH = 1000;
const int HEIGHT = 800;
const int FPS = 2000;
SDL_Renderer*RENDERER;
SDL_Window* window;


int WinMain(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    screen window=new_screen("hi",20,20,WIDTH,HEIGHT,0);
    //float a=5.89;
    //printf("%d",*(int*)&a);
    //convertir jjuste le type sans changer la valeur

    show_screen(window);
    float k=0;
    float j=1;
    while(1){
        Uint32 t=SDL_GetTicks();
        SDL_Event event;
        fill(window,0,0,0,255);
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return 0;
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym==SDLK_q){
                        POS-=0.02;
                    }
                    if(event.key.keysym.sym==SDLK_d){
                        POS+=0.02;
                    }
                    if(event.key.keysym.sym==SDLK_z){
                        POSy-=0.02;
                    }
                    if(event.key.keysym.sym==SDLK_s){
                        POSy+=0.02;
                    }

                default:
                    break;
            }
        }
        cube c =new_cube(10,10,20,10,255,0,255,255,0,0,0);
        cube c2 =new_cube(10,11,20,10,255,0,255,255,0,0,0);
        draw_cube(c,window);
        draw_cube(c2,window);
        for(int i=0;i<20;i++){
            for(int k=0;k<20;k++){
                draw_cube(new_cube(i,k,10,10,255/20*i,0,255-255/20*k,255,0,0,0),window);
            }
        }

        //ca  ca marche pas 
        //for(int i=0;i<4;i++){
        //    for(int u=0;i<4;u++){
        //        for(int y=0;y<4;y++){
        //            draw_cube(new_cube(i,u,y+10,10,0,0,255,255,0,0,0),window);
        //        }
        //    } 
        //}
        draw_cube(new_cube(0,0,10,10,0,255,0,0,0,0+k,0+j),window);
        update_screen(window);
        Uint32 delay=SDL_GetTicks()-t;
        char*ti=malloc(sizeof(char)*4);
        k+=0.01;
        j+=0.0024;

        snprintf(ti,sizeof(int32_t),"%d",(int)1000*(SDL_GetTicks()-t));
        SDL_SetWindowTitle(window.window,ti);
    }
    return 0;
}
