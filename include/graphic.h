#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SDL2/SDL.h>

extern SDL_Renderer *RENDERER;
extern SDL_Window *window;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

void init_graphic(int width, int height);
void close_graphic();
void update_screen();
void setbackground(int r, int g, int b);
void draw_line(int x1, int y1, int x2, int y2);

#define SET_COLOR_FAST(R, G, B) SDL_SetRenderDrawColor(RENDERER, R, G, B, 255);
#define DRAW_LINE_FAST(X1, Y1, X2, Y2) SDL_RenderDrawLine(RENDERER, X1, Y1, X2, Y2);

#endif