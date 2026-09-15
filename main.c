#include "chip-8.h"
#include "instructions.h"
#include "render.h"

int main(int argc, char *argv[]){

    (void)argc;
    (void)argv;

    uint32_t START , END, DT = 16;

    SDL_Window* window = open_window();
    SDL_Renderer* renderer = initiate_renderer(window);
    SDL_Event event;

    int running = 1;

    chip8* cpu;
    cpu = initiate_cpu();

    if (!window || !renderer || !cpu) {
    return 1;
    }

    SDL_Texture* texture = SDL_CreateTexture(
    renderer, 
    SDL_PIXELFORMAT_RGBA8888, 
    SDL_TEXTUREACCESS_STREAMING, 
    64, 32
    );

    START = 0;

    while(running){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
            else if (event.type == SDL_KEYDOWN) {
                handle_key_event(cpu, event.key.keysym.sym, 1);
            } 
            else if (event.type == SDL_KEYUP) {
                    handle_key_event(cpu, event.key.keysym.sym, 0);
            }

            }
            
        }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

