#ifndef ASSEMBLER_F
#define ASSEMBLER_F
#include <stdint.h>
typedef chip8;

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

#endif