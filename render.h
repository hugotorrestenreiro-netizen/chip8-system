#ifndef RENDER
#define RENDER
#include <SDL2/SDL.h>
#include "chip-8.h"

SDL_Window* open_window();
SDL_Renderer* initiate_renderer(SDL_Window* window);
void handle_key_event(chip8 *cpu, SDL_Keycode key, uint8_t state);
uint16_t fetch(chip8* cpu);
void decode_execute(chip8* cpu, uint16_t opcode);

#endif