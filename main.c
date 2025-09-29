#include <stdio.h>
#include "SDL.h"

static int inputStateUp[18];
static int inputStateDown[18];


void init_SDL(void)
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_EVENTS);
}


void updateInputState(int (*inputState)[], SDL_KeyCode key) // inputState should be and array of length 18
{
  switch(key) {
    case SDLK_w:
      (*inputState)[0] = 1;
      break;
    case SDLK_s:
      (*inputState)[1] = 1;
      break;
    case SDLK_a:
      (*inputState)[2] = 1;
      break;
    case SDLK_d:
      (*inputState)[3] = 1;
      break;
    case SDLK_j:
      (*inputState)[4] = 1;
      break;
    case SDLK_k:
      (*inputState)[5] = 1;
      break;
    case SDLK_h:
      (*inputState)[6] = 1;
      break;
    case SDLK_LSHIFT:
      (*inputState)[7] = 1;
      break;
    case SDLK_1:
      (*inputState)[8] = 1;
      break;
    case SDLK_2:
      (*inputState)[9] = 1;
      break;
    case SDLK_3:
      (*inputState)[10] = 1;
      break;
    case SDLK_4:
      (*inputState)[11] = 1;
      break;
    case SDLK_SPACE:
      (*inputState)[12] = 1;
      break;
    case SDLK_RETURN:
      (*inputState)[13] = 1;
      break;
    case SDLK_UP:
      (*inputState)[14] = 1;
      break;
    case SDLK_DOWN:
      (*inputState)[15] = 1;
      break;
    case SDLK_LEFT:
      (*inputState)[16] = 1;
      break;
    case SDLK_RIGHT:
      (*inputState)[17] = 1;
      break;
  }
}


void handleInput(int *running)
{
  for (int i = 0; i < 18; i++) {
    inputStateUp[i] = 0;
    inputStateDown[i] = 0;
  }

  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      printf("Quiting\n");
      *running = 0;
    }

    if (event.type == SDL_KEYUP) {
      // printf("keyup: %c\n", event.key.keysym.sym);
      updateInputState(&inputStateUp, event.key.keysym.sym);
    } else if (event.type == SDL_KEYDOWN) {
      // printf("keydown: %c\n", event.key.keysym.sym);
      updateInputState(&inputStateDown, event.key.keysym.sym);
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
  window = SDL_CreateWindow("Shooter Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680*2, 480*2, 0);

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
