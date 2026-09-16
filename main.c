#include "chip-8.h"
#include "instructions.h"
#include "render.h"

int main(int argc, char *argv[]){

    (void)argc;
    (void)argv;

    uint32_t START ,DT = 16;

    SDL_Window* window = open_window();
    SDL_Renderer* renderer = initiate_renderer(window);
    SDL_Event event;

    int running = 1;

    chip8* cpu;
    cpu = initiate_cpu();

    if (!window || !renderer || !cpu) {
    return 1;
    }

    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, 64, 32);

    load_rom(cpu, "rom.ch8");

    START = 0;

    while(running){

        uint32_t pixel_buffer[64 * 32];
        START = SDL_GetTicks();

        while(SDL_PollEvent(&event)){
            //Inputs
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

            //Fetch Decode Execute

            for (int i = 0; i < 10; i++) {
            uint16_t opcode = fetch(cpu);
            decode_execute(cpu, opcode);
        }
            //Update register timers

            if (cpu->delay_timer > 0) cpu->delay_timer--;
            if (cpu->sound_timer > 0) cpu->sound_timer--;

            //Update Display

            for (int i = 0; i < 64 * 32; i++) {
            pixel_buffer[i] = (cpu->display[i] == 1) ? 0xFFFFFFFF : 0x000000FF;
        }
    
            SDL_UpdateTexture(texture, NULL, pixel_buffer, 64 * sizeof(uint32_t));
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
            
            uint32_t elapsed_time = SDL_GetTicks() - START;

            if(elapsed_time < DT){
            SDL_Delay(DT - elapsed_time); //Sleeps until DT (here 16ms) has passed

        }
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

