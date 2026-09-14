#include "instructions.h"
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

//Assignment

void LD_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK){
    cpu->V[x] = KK;
    return;
}

void LD_I_NNN(chip8 *cpu, uint16_t NNN){
    cpu->I = NNN;
    return;
}

void LD_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    cpu->V[x] = cpu->V[y];
    return;
}

//Arithmetic and Logic

void ADD_Vx_KK(chip8* cpu, uint8_t x, uint8_t KK){
    cpu->V[x] += KK ;
    return;
}

void OR_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    cpu->V[x] |= cpu->V[y];
    return;
}

void AND_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    cpu->V[x] &= cpu->V[y];
    return;
}

void XOR_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y){
    cpu->V[x] ^= cpu->V[y];
    return;
}

void ADD_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y){
    if(cpu->V[x] + cpu->V[y]>255){
        cpu->V[x] += cpu->V[y];
        cpu->V[0xF] = 1;
        return;
    }
    else{
        cpu->V[x] += cpu->V[y];
        cpu->V[0x0F] = 0;
        return;
    }
}

void SUB_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y){
    if(cpu->V[x]<cpu->V[y]){
        cpu->V[x] = cpu->V[x] - cpu->V[y];
        cpu->V[0xF] = 0;
        return;
    }
    else{
        cpu->V[x] = cpu->V[x] - cpu->V[y];
        cpu->V[0xF] = 1;
        return;
    }
}

void SUBN_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y){
    if(cpu->V[x] <= cpu->V[y]){
        cpu->V[x] = cpu->V[y] - cpu->V[x] ;
        cpu->V[0xF] = 1;
        return;
    }
    else{
        cpu->V[x] = cpu->V[y] - cpu->V[x];
        cpu->V[0xF] = 0;
        return;
    }
}

void SHR_Vx(chip8* cpu, uint8_t x){
    cpu->V[0xF] = cpu->V[x] & 0x01;
    cpu->V[x]= cpu->V[x] >> 1;
    return;
}

void SHL_Vx(chip8* cpu, uint8_t x){
    cpu->V[0xF] = (cpu->V[x] >> 7);
    cpu->V[x]= cpu->V[x] << 1;
    return;
}

//Rendering and Graphism

void CLS(chip8* cpu)  //Effacer l'écran
{}

void DRW_Vx_Vy_N(chip8* cpu, uint8_t x, uint8_t y, uint8_t N)  //dessinner un sprite à N octet à la coordonnée (Vx, Vy) en appliquant XOR et lève V[0x0F] si collision
{}

//Keyboard and entry

void SKP_Vx(chip8* cpu, uint8_t x){

    uint8_t key = cpu->V[x];

    if(key <= 0x0F && cpu->keyboard[key] == 1){
        cpu->pc += 2;
        return;
    }
}

void SKNP_Vx(chip8* cpu, uint8_t x){

    uint8_t key = cpu->V[x];

    if(key <= 0x0F && cpu->keyboard[key] == 0){
        cpu->pc += 2;
        return;
    }
}

void LD_Vx_K(chip8* cpu, uint8_t x, uint8_t K){

    for (uint8_t i = 0; i < 16; i++) {
        if (cpu->keyboard[i] == 1) {
            cpu->V[x] = i;
            return;
        }
    }
    cpu->pc-=2;
}

//Timers and Random

void RND_Vx_KK(chip8* cpu, uint8_t x, uint8_t KK){
    cpu->V[x] = rand() & KK;
    return;
}

void LD_Vx_DT(chip8 *cpu, uint8_t x){
    cpu->V[x] = cpu->delay_timer;
    return;
}

void LD_DT_Vx(chip8 *cpu, uint8_t x){
    cpu->delay_timer = cpu->V[x];
    return;
}

void LD_ST_Vx(chip8 *cpu, uint8_t x){
    cpu->sound_timer = cpu->V[x];
    return;
}