#ifndef INSTRUCTIONS
#define INSTRUCTIONS
#include <stdint.h>
#include <stdlib.h>
#include "chip-8.h"

/*
uint8_t find_T(uint16_t value);
uint8_t find_X(uint16_t value);
uint8_t find_Y(uint16_t value);
uint8_t find_N(uint16_t value);
uint8_t find_KK(uint16_t value);
uint16_t find_NNN(uint16_t value);
*/

void JP_NNN (chip8 *cpu, uint16_t NNN);
void CALL_NNN (chip8 *cpu , uint16_t NNN);
void RET (chip8 *cpu);
void JP_V0_NNN (chip8 *cpu, uint16_t NNN);
void SE_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void SNE_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void SE_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK);
void SNE_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK);
void LD_Vx_KK(chip8 *cpu, uint8_t x, uint8_t KK);
void LD_I_NNN(chip8 *cpu, uint16_t NNN);
void LD_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void ADD_Vx_KK(chip8* cpu, uint8_t x, uint8_t KK);
void OR_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void AND_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void XOR_Vx_Vy(chip8 *cpu, uint8_t x, uint8_t y);
void ADD_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y);
void SUB_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y);
void SUBN_Vx_Vy(chip8* cpu, uint8_t x, uint8_t y);
void SHR_Vx(chip8* cpu, uint8_t x);
void SHL_Vx(chip8* cpu, uint8_t x);
void CLS(chip8* cpu);
void DRW_Vx_Vy_N(chip8* cpu, uint8_t x, uint8_t y, uint8_t N);
void SKP_Vx(chip8* cpu, uint8_t x);
void SKNP_Vx(chip8* cpu, uint8_t x);
void LD_Vx_K(chip8* cpu, uint8_t x, uint8_t K);
void RND_Vx_KK(chip8* cpu, uint8_t x, uint8_t KK);
void LD_Vx_DT(chip8 *cpu, uint8_t x);
void LD_DT_Vx(chip8 *cpu, uint8_t x);
void LD_ST_Vx(chip8 *cpu, uint8_t x);
void ADD_I_Vx(chip8* cpu, uint8_t x);
void LD_F_Vx(chip8* cpu, uint8_t x);
void LD_B_Vx(chip8* cpu, uint8_t x);
void LD_Vx_I(chip8* cpu, uint8_t x);
void LD_I_Vx(chip8* cpu, uint8_t x);


#endif