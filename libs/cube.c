#include <SDL2/SDL.h>
#include "2dscreen.h"
#include <math.h>
#include "cube.h"





cube new_cube(int x,int y,int z,int size,uint8_t r,uint8_t g,uint8_t b,uint8_t a,float rotx,float roty,float rotz){
    cube c={{r,g,b,a},x,y,z,size,rotx,roty,rotz};
    return c;
}
float POS=0;
float POSy=0;
float POSz=0;
int SIZE=1;
float vecx=0;
float vecz=100;

void draw_cube(cube c,screen s){
    float l[][3]={
        {0,0,0},
        {0,1,0},//face avant  1 2
        {1,1,0},//            0 3
        {1,0,0},
        
        {0,0,1},// face arrier
        {0,1,1},
        {1,1,1},
        {1,0,1}
    };
    for(int i=0;i<8;i++){
        l[i][0]-=0.5;
    }
    for(int i=0;i<8;i++){
        float x=l[i][0];
        float y=l[i][1];
        float z=l[i][2];
        l[i][0]=cos(c.rotz)*cos(c.roty)*x+(cos(c.rotz)*sin(c.roty)-sin(c.rotz)*cos(c.rotx))*y+(cos(c.rotz)*sin(c.roty)*cos(c.rotx)+sin(c.rotz)*sin(c.rotx))*z;
        l[i][1]=sin(c.rotz)*cos(c.roty)*x+(cos(c.rotz)*cos(c.rotx)+sin(c.rotz)*sin(c.roty)*sin(c.rotx))*y+(sin(c.rotz)*sin(c.roty)*cos(c.rotx)-cos(c.rotz)*sin(c.rotx))*z;
        l[i][2]=-sin(c.roty)*x+cos(c.roty)*sin(c.rotx)*y+cos(c.roty)*cos(c.rotx)*z;
    }
    for(int i=0;i<8;i++){
        l[i][0]+=c.x+0.5;
        l[i][1]+=c.y+0.5;
        l[i][2]+=c.z+0.5;
    }
    //for(int i=0;i<8;i++){
    //    l[i][0]=l[i][0]/l[i][2]*SIZE*c.size;
    //    l[i][1]=l[i][1]/l[i][2]*SIZE*c.size;
    //}
    int FUITE=100;
    for(int i=0;i<8;i++){
      float*proj= project_point(l[i][0],l[i][1],l[i][2],0+POS,0+POSy,0+POSz,vecx,0,vecz);
        l[i][0]=proj[0]*c.size*SIZE;
        l[i][1]=proj[1]*c.size*SIZE;
        free(proj);
    }
    
    //face avant haut gauche
    draw_triangle(s,l[0][0]+s.w/2,l[0][1]+s.h/2,l[1][0]+s.w/2,l[1][1]+s.h/2,l[2][0]+s.w/2,l[2][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    //face avant bas droite
    draw_triangle(s,l[0][0]+s.w/2,l[0][1]+s.h/2,l[3][0]+s.w/2,l[3][1]+s.h/2,l[2][0]+s.w/2,l[2][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);

    draw_triangle(s,l[1][0]+s.w/2,l[1][1]+s.h/2,l[5][0]+s.w/2,l[5][1]+s.h/2,l[6][0]+s.w/2,l[6][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[6][0]+s.w/2,l[1][1]+s.h/2,l[2][0]+s.w/2,l[2][1]+s.h/2,l[1][0]+s.w/2,l[1][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[0][0]+s.w/2,l[0][1]+s.h/2,l[4][0]+s.w/2,l[4][1]+s.h/2,l[7][0]+s.w/2,l[7][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[7][0]+s.w/2,l[7][1]+s.h/2,l[3][0]+s.w/2,l[3][1]+s.h/2,l[0][0]+s.w/2,l[0][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[3][0]+s.w/2,l[3][1]+s.h/2,l[2][0]+s.w/2,l[2][1]+s.h/2,l[6][0]+s.w/2,l[6][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[6][0]+s.w/2,l[6][1]+s.h/2,l[7][0]+s.w/2,l[7][1]+s.h/2,l[3][0]+s.w/2,l[3][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[0][0]+s.w/2,l[0][1]+s.h/2,l[1][0]+s.w/2,l[1][1]+s.h/2,l[5][0]+s.w/2,l[5][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    draw_triangle(s,l[5][0]+s.w/2,l[5][1]+s.h/2,l[4][0]+s.w/2,l[4][1]+s.h/2,l[0][0]+s.w/2,l[0][1]+s.h/2,c.color[0],c.color[1],c.color[2],c.color[3]);
    for(int i=0;i<8;i++){
        
        draw_at(s,l[i][0]+s.w/2,l[i][1]+s.h/2,255,0,0,255);
        draw_at(s,l[i][0]+s.w/2+1,l[i][1]+s.h/2,255,0,0,255);
        draw_at(s,l[i][0]+s.w/2+2,l[i][1]+s.h/2+1,255,0,0,255);
        draw_at(s,l[i][0]+s.w/2,l[i][1]+s.h/2+2,255,0,0,255);
    }


    
    
}