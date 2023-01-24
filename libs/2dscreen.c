#include <SDL2/SDL.h>
#include "matrix.h"
#include "2dscreen.h"



screen new_screen(char*title,int x,int y,int w,int h,uint32_t flags){
    SDL_Window*wi=SDL_CreateWindow(title,x,y,w,h,flags);
    SDL_Renderer*r=SDL_CreateRenderer(wi,-1,0);
    screen s;
    s.renderer=r;
    s.window=wi;
    s.flags=flags;
    s.h=h;
    s.w=w;
    s.x=x;
    s.y=y;
    s.title=title;
    return s;
}
void show_screen(screen s){
    SDL_ShowWindow(s.window);
}
void draw_at(screen s,int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    SDL_SetRenderDrawColor(s.renderer,r,g,b,a);
    SDL_RenderDrawPoint(s.renderer,x,y);
}

void draw_line(screen s,int x1,int y1,int x2,int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    SDL_SetRenderDrawColor(s.renderer,r,g,b,a);
    SDL_RenderDrawLine(s.renderer,x1,y1,x2,y2);
}

void update_screen(screen s){
    SDL_RenderPresent(s.renderer);
}
void fill(screen s ,uint8_t r,uint8_t g,uint8_t b,uint8_t a){
    SDL_SetRenderDrawColor(s.renderer,r,g,b,a);
    SDL_RenderClear(s.renderer);
}

void draw_triangle(screen s,int x1,int y1,int x2,int y2,int x3,int y3, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    draw_line(s,x1,y1,x2,y2,r,g,b,a);
    draw_line(s,x3,y3,x2,y2,r,g,b,a);
    draw_line(s,x1,y1,x3,y3,r,g,b,a);
}
// x y z coordonne du point a projetr
//view_x view_y view_z coordonne de l'observateur
//focus_x focus_y focus_z point de fuite donc direction dans la quelle il regarde
//return array x y projeté 
 float*project_point(float x,float y,float z,float view_x,float view_y,float view_z,float focus_x,float focus_y,float focus_z){
    float*l=malloc(sizeof(float)*2);
    //float nx=x-view_x;
    //float ny=y-view_y;
    //float nz=z-view_z;
    //polar_vector z_axe=to_polar(new_vector(0,0,1));
    //polar_vector view_v=to_polar(new_vector(view_x,view_y,view_z));
    //float fuite=sqrt(view_x*view_x+view_y*view_y+view_z*view_z);
    //float angle1=view_v.ph-z_axe.ph;
    //float angle2=view_v.th-z_axe.th;
    //polar_vector newpoint=to_polar(new_vector(x,y,z));
    //newpoint.th+=angle2;
    //newpoint.ph+=angle1;
    //vector point=from_polar(newpoint);//point pivoter quand l'obeservateur est pivoter pour etre aligner a z+
    l[0]= (x-view_x)*(focus_z-view_z)/((z-view_z)+view_x*view_y)+view_x;
    l[1]= (y-view_y)*(focus_z-view_z)/((z-view_z)+view_x*view_y)+view_y;
    return l;
}