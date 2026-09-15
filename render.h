#ifndef RENDER
#define RENDER
#include <SDL2/SDL.h>

typedef chip8;

SDL_Window* open_window();
SDL_Renderer* initiate_renderer(SDL_Window* window);
void handle_key_event(chip8 *cpu, SDL_Keycode key, uint8_t state);

#endif