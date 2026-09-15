#include "chip-8.h"
#include "instructions.h"
#include "render.h"

int main(int argc, char *argv[]){

    (void)argc;
    (void)argv;

    uint32_t START = 0 , END, DT = 16;
    
    

    SDL_Window* window = open_window();
    SDL_Renderer* renderer = initiate_renderer(window);
    SDL_Event event;

    chip8* cpu = initiate_cpu();

}