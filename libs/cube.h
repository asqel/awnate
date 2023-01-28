#ifndef CUBE_H
#define CUBE_H

#include <SDL2/SDL.h>
#include "2dscreen.h"
#include <math.h>


typedef struct cube{
    uint8_t color[4];
    int x;
    int y;
    int z;
    int size;
    float rotx;
    float roty;
    float rotz;


}cube;


cube new_cube(int x,int y,int z,int size,uint8_t r,uint8_t g,uint8_t b,uint8_t a,float rotx,float roty,float rotz);
extern float POS;
extern float POSy;
extern int SIZE;

void draw_cube(cube c,screen s);

#endif