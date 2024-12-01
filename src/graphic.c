#include <SDL2/SDL.h>


SDL_Renderer *RENDERER;
SDL_Window *window;

void init_graphic(int width, int height) {
	window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	RENDERER = SDL_CreateRenderer(window, -1, 0);
}

void close_graphic() {
	SDL_DestroyRenderer(RENDERER);
	SDL_DestroyWindow(window);
}

void update_screen() {
	SDL_RenderPresent(RENDERER);
}

void setbackground(int r, int g, int b) {
	SDL_SetRenderDrawColor(RENDERER, r, g, b, 255);
	SDL_RenderClear(RENDERER);
}

void draw_line(int x1, int y1, int x2, int y2) {
	SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255);
	SDL_RenderDrawLine(RENDERER, x1, y1, x2, y2);
}
