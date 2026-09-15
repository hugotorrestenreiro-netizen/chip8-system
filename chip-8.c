#include "chip-8.h"
#include "instructions.h"
#include "render.h"

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

int load_rom(chip8* cpu, const char* filename){
    FILE* rom = fopen(filename,"rb");
    if(rom == NULL){
        printf("Rom initialization error.\n");
        return 0;
    }

    fseek(rom, 0, SEEK_END);
    long rom_size = ftell(rom);
    rewind(rom);

    if(rom_size > (0xFFF - 0X200)){
        printf("ROM size overflow.\n");
        fclose(rom);
        return 0;
    }

    size_t byte_read = fread(&cpu->memory[0x200], sizeof(uint8_t), rom_size, rom);
    if (byte_read != (size_t) rom_size){
        printf("Reading ROM File issue.\n");
        fclose(rom);
        return 0;
    }

    fclose(rom);
    return 1;
}

uint16_t fetch(chip8* cpu){
    uint16_t opcode = ((cpu->memory[cpu->pc] << 8) | cpu->memory[cpu->pc + 1]);
    cpu->pc += 2;
    return opcode;
}

void decode_execute(chip8* cpu, uint16_t opcode){
    uint8_t t = (opcode & 0xF000) >> 12;
    uint8_t x = (opcode & 0x0F00) >> 8;
    uint8_t y = (opcode & 0x00F0) >> 4;
    uint16_t nnn = (opcode & 0x0FFF);
    uint8_t nn = (opcode & 0x00FF);
    uint8_t n = (opcode & 0x000F);

    switch (t)   //0xTXYN
    {
    case 0:
        //0x0nnn
        switch (x){
            
        case 0:
            switch (n) {
        case 0:
            CLS(cpu);
            break;
        case 14:
            RET(cpu);
            break;
        default:
            //0x0nnn
            break;}
        
        break;
        }
    case 1:
        //0x1nnn
        JP_NNN(cpu, nnn);
        break;
    case 2: 
        //0x2nnn
        CALL_NNN(cpu, nnn);

        break;
    case 3:
        //0x3nnn
        SE_Vx_KK(cpu, x, nn);
        break;
    case 4:
        //0x4nnn
        SNE_Vx_KK(cpu, x, nn);
        break;
    case 5:
        //0x5nnn
        SE_Vx_Vy(cpu, x, y);
        break;
    case 6:
        //0x6nnn
        LD_Vx_KK(cpu, x, nn);
        break;
    case 7:
        //0x7nnn
        ADD_Vx_KK(cpu, x, nn);
        break;
    case 8:
        //0x8nnn
        switch (n)
        {
        case 0:
            //0x8xy0
            LD_Vx_Vy(cpu, x, y);
            break;
        case 1:
            //0x8xy0
            OR_Vx_Vy(cpu, x, y);
            break;
        case 2:
            //0x8xy2
            AND_Vx_Vy(cpu, x, y);
            break;
        case 3:
            //0x8xy3
            XOR_Vx_Vy(cpu, x, y);
            break;
        case 4:
            //0x8xy4
            ADD_Vx_Vy(cpu, x, y);
            break;
        case 5:
            //0x8xy5
            SUB_Vx_Vy(cpu, x, y);
            break;
        case 6:
            //0x8xy6
            SHR_Vx(cpu, x);
            break;
        case 7:
            //0x8xy7
            SUBN_Vx_Vy(cpu, x, y);
            break;
        case 14:
            //0x8xyE
            SHL_Vx(cpu, x);
            break;
        }
        break;
    case 9:
        //0x9nnn
        SNE_Vx_Vy(cpu, x, y);
        break;
    case 10:
        //0xAnnn
        LD_I_NNN(cpu, nnn);
        break;
    case 11:
        //0xBnnn
        JP_V0_NNN(cpu, nnn);
        break;
    case 12:
        //0xCnnn
        RND_Vx_KK(cpu, x, nn);
        break;
    case 13:
        //0xDnnn
        DRW_Vx_Vy_N(cpu, x, y, n);
        break;
    case 14:
        //0xEnnn
        switch (y)
        {
        case 9:
            //Ex9E
            SKP_Vx(cpu, x);
            break;
        case 10:
            SKNP_Vx(cpu, x);
            break;
        }
        break;
    case 15:
        //0xFnnn
        switch (y)
        {
        case 0:
            switch (n)
            {
            case 7:
                LD_Vx_DT(cpu, x);
                break;

            case 10:

                for(int i = 0; i < 16; i++){
                    if(cpu->keyboard[i]==1){
                        LD_Vx_K(cpu, x, i);
                        return;
                    }
                }
                cpu->pc-=2;
                break;
                }
            
            break;
        case 1:
            switch (n)
            {
            case 5:
                LD_DT_Vx(cpu, x);
                break;
            case 8:
                LD_ST_Vx(cpu, x);
                break;
            case 14:
                ADD_I_Vx(cpu, x);
                break;
            }
            break;
            
        case 2:
            LD_F_Vx(cpu, x);
            break;
        
        case 3:
            LD_B_Vx(cpu, x);
            break;
        
        case 5:
            LD_I_Vx(cpu, x);
            break;

        case 6:
            LD_Vx_I(cpu, x);
            break;
        }
        break;
    }
return;
}