#include "render.h"

SDL_Window* open_window(){

    SDL_Window* window = NULL;

    if(SDL_Init(SDL_INIT_VIDEO)<0){
        printf("SDL initialization error.\n");
        return NULL;
    }

    int screen_h = 32;
    int screen_w = 64;

    window = SDL_CreateWindow("CHIP-8 SYSTEM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_h*15, screen_w*15, SDL_WINDOW_RESIZABLE);

    if(!window){
        printf("Window initialization error.\n");
        SDL_Quit();
        return NULL;
    }
    return window;
}

SDL_Renderer* initiate_renderer(SDL_Window* window){
    SDL_Renderer* renderer = NULL;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer){
        printf("Rendering initialization error.\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return NULL ;
    }
    return renderer;
}

void handle_key_event(chip8 *cpu, SDL_Keycode key, uint8_t state) {
    switch (key) {

        case SDLK_1: cpu->key[0x1] = state; break;  //KEY 1 -> &
        case SDLK_2: cpu->key[0x2] = state; break;  //KEY 2 -> é
        case SDLK_3: cpu->key[0x3] = state; break;  //KEY 3 -> "
        case SDLK_4: cpu->key[0xC] = state; break;  //KEY C -> '

        case SDLK_a: cpu->key[0x4] = state; break;  //KEY 4 -> a
        case SDLK_z: cpu->key[0x5] = state; break;  //KEY 5 -> z
        case SDLK_e: cpu->key[0x6] = state; break;  //KEY 6 -> e
        case SDLK_r: cpu->key[0xD] = state; break;  //KEY D -> r

        case SDLK_q: cpu->key[0x7] = state; break;  //KEY 7 -> q
        case SDLK_s: cpu->key[0x8] = state; break;  //KEY 8 -> s
        case SDLK_d: cpu->key[0x9] = state; break;  //KEY 9 -> d
        case SDLK_f: cpu->key[0xE] = state; break;  //KEY E -> f

        case SDLK_w: cpu->key[0xA] = state; break;  //KEY A -> w
        case SDLK_x: cpu->key[0x0] = state; break;  //KEY 0 -> x
        case SDLK_c: cpu->key[0xB] = state; break;  //KEY B -> c
        case SDLK_v: cpu->key[0xF] = state; break;  //KEY F -> v

        default: break;
    }
}