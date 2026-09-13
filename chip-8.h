#ifndef CHIP8
#define CHIP8

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t memory[4096];
    uint8_t V[16];
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint8_t sp ;
    uint8_t keyboard[16];
    uint16_t pc;
    uint16_t I;
    uint16_t stack[16];
    
}chip8;

#define START_ADRESS 0x200
#define START_ADRESS_ETI 0x600

#endif