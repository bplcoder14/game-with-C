#include <stdio.h>
#include "SDL.h"

static uint16_t inputState = 0x0000;

void init_SDL(void)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_EVENTS);
}


void handleInput(int *running)
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        printf("Quiting\n");
        *running = 0;
      }
      
      if (event.type == SDL_KEYUP) {
        printf("keyup: %c\n", event.key.keysym.sym);
      }
      if (event.type == SDL_KEYDOWN) {
        printf("keydown: %c\n", event.key.keysym.sym);
      }
    }
}


int main(void)
{
  // init sdl and other stuff
  init_SDL();
  SDL_Window *window;
  SDL_Surface *window_surface;
  int running = 1;
  
  // ceate the window and get its surface
  window = SDL_CreateWindow("Shooter Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480, 0);

  if(!window) {
    printf("Failed to create window\n");
    return -1;
  }

  window_surface = SDL_GetWindowSurface(window);

  if (!window_surface) {
    printf("Failed to get window surface\n");
    return -1;
  }
  
  while(running) {
    handleInput(&running);
    SDL_UpdateWindowSurface(window);
  }

  // properly shutdown and quit anything that needs it
  SDL_Quit();
  exit(0);
} 
