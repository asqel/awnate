#ifndef SCREEN2D_H
#define SCREEN2D_H


#include <SDL2/SDL.h>

typedef struct screen{
    SDL_Renderer*renderer;
    SDL_Window* window;
    char*title;
    int x;
    int y;
    int w;
    int h;
    uint32_t flags;
}screen;



screen new_screen(char*title,int x,int y,int w,int h,uint32_t flags);
void show_screen(screen s);
void draw_at(screen s,int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void draw_line(screen s,int x1,int y1,int x2,int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

void update_screen(screen s);
void fill(screen s ,uint8_t r,uint8_t g,uint8_t b,uint8_t a);

void draw_triangle(screen s,int x1,int y1,int x2,int y2,int x3,int y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

// x y z coordonne du point a projetr
//view_x view_y view_z coordonne de l'observateur
//focus_x focus_y focus_z point de fuite donc direction dans la quelle il regarde
//return array x y projeté 
float*project_point(float x,float y,float z,float view_x,float view_y,float view_z,float focus_x,float focus_y,float focus_z);




#endif
