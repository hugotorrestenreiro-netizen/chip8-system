#include "chip-8.h"

chip8* initiate_cpu(){

    chip8* cpu = calloc(1,sizeof(chip8));

    if(cpu == NULL){
        return NULL;
    }

    initiate_digits(cpu);

    cpu->pc = START_ADDRESS; //START_ADDRESS = 0x200
    cpu->delay_timer = 60;
    cpu->sound_timer = 60;

    return cpu;
}

void initiate_digits(chip8* cpu){

    //0
    cpu->memory[0] = 0xF0;
    cpu->memory[1] = 0x90;
    cpu->memory[2] = 0x90;
    cpu->memory[3] = 0x90;
    cpu->memory[4] = 0xF0;

    //1
    cpu->memory[5] = 0x20;
    cpu->memory[6] = 0x60;
    cpu->memory[7] = 0x20;
    cpu->memory[8] = 0x20;
    cpu->memory[9] = 0x70;

    //2
    cpu->memory[10] = 0xF0;
    cpu->memory[11] = 0x10;
    cpu->memory[12] = 0xF0;
    cpu->memory[13] = 0x80;
    cpu->memory[14] = 0xF0;

    //3
    cpu->memory[15] = 0xF0;
    cpu->memory[16] = 0x10;
    cpu->memory[17] = 0xF0;
    cpu->memory[18] = 0x10;
    cpu->memory[19] = 0xF0;
    
    //4
    cpu->memory[20] = 0x90;
    cpu->memory[21] = 0x90;
    cpu->memory[22] = 0xF0;
    cpu->memory[23] = 0x10;
    cpu->memory[24] = 0x10;

    //5
    cpu->memory[25] = 0xF0;
    cpu->memory[26] = 0x80;
    cpu->memory[27] = 0xF0;
    cpu->memory[28] = 0x10;
    cpu->memory[29] = 0xF0;

    //6
    cpu->memory[30] = 0xF0;
    cpu->memory[31] = 0x80;
    cpu->memory[32] = 0xF0;
    cpu->memory[33] = 0x90;
    cpu->memory[34] = 0xF0;

    //7
    cpu->memory[35] = 0xF0;
    cpu->memory[36] = 0x10;
    cpu->memory[37] = 0x20;
    cpu->memory[38] = 0x40;
    cpu->memory[39] = 0x40;

    //8
    cpu->memory[40] = 0xF0;
    cpu->memory[41] = 0x90;
    cpu->memory[42] = 0xF0;
    cpu->memory[43] = 0x90;
    cpu->memory[44] = 0xF0;

    //9
    cpu->memory[45] = 0xF0;
    cpu->memory[46] = 0x90;
    cpu->memory[47] = 0xF0;
    cpu->memory[48] = 0x10;
    cpu->memory[49] = 0xF0;

    //A
    cpu->memory[50] = 0xF0;
    cpu->memory[51] = 0x90;
    cpu->memory[52] = 0xF0;
    cpu->memory[53] = 0x90;
    cpu->memory[54] = 0x90;

    //B
    cpu->memory[55] = 0xE0;
    cpu->memory[56] = 0x90;
    cpu->memory[57] = 0xE0;
    cpu->memory[58] = 0x90;
    cpu->memory[59] = 0xE0;

    //C
    cpu->memory[60] = 0xF0;
    cpu->memory[61] = 0x80;
    cpu->memory[62] = 0x80;
    cpu->memory[63] = 0x80;
    cpu->memory[64] = 0xF0;

    //D
    cpu->memory[65] = 0xE0;
    cpu->memory[66] = 0x90;
    cpu->memory[67] = 0x90;
    cpu->memory[68] = 0x90;
    cpu->memory[69] = 0xE0;

    //E
    cpu->memory[70] = 0xF0;
    cpu->memory[71] = 0x80;
    cpu->memory[72] = 0xF0;
    cpu->memory[73] = 0x80;
    cpu->memory[74] = 0xF0;

    //F
    cpu->memory[75] = 0xF0;
    cpu->memory[76] = 0x80;
    cpu->memory[77] = 0xF0;
    cpu->memory[78] = 0x80;
    cpu->memory[79] = 0x80;

    return;
}
