#include "assembler_functions.h"
//EN Assembler primary functions to keep maximum fidelity
//FR Ici je recode les fonctions de base de l'Assembler afin que le comportement de la simulation soit la plus fidèle à la réalité.

/*
uint8_t find_T(uint16_t value){
    return((value & 0xF000) >> 12);
}

uint8_t find_X(uint16_t value){
    return((value & 0x0F00) >> 8);
}

uint8_t find_Y(uint16_t value){
    return((value & 0x00F0) >> 4);
}

uint8_t find_N(uint16_t value){
    return((value & 0x000F));
}


uint8_t find_KK(uint16_t value){
    return((value & 0x00FF));
}


uint16_t find_NNN(uint16_t value){
    return ((value & 0x0FFF));
}
*/

//Jump and Calls (control flow)

void JP_NNN (chip8 *cpu, uint16_t NNN){
    cpu->pc = NNN;
    return;
}

void CALL_NNN (chip8 *cpu , uint16_t NNN){
    cpu->stack[cpu->sp] = cpu->pc ;
    cpu->sp++ ;
    cpu->pc = NNN;
    return;
}

void RET (chip8 *cpu){
    cpu->sp-- ;
    cpu->pc = cpu->stack[cpu->sp] ;
    return;
}

void JP_V0_NNN (chip8 *cpu, uint16_t NNN){
    cpu->pc = NNN + cpu->V[0];
    return;
}

//Conditionnal Jump

void SE_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    if(cpu->V[x] == cpu->V[y]){
        cpu->pc += 2;
    }
    return;
}

void SNE_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    if(cpu->V[x] != cpu->V[y]){
        cpu->pc += 2;
    }
    return;
}

void SE_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK){
    if(cpu->V[x] == KK){
        cpu->pc += 2;
    }
    return;
}

void SNE_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK){
    if(cpu->V[x] != KK){
        cpu->pc += 2;
    }
    return;
}






