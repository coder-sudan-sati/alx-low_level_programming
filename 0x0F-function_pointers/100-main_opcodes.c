#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint8_t getBits(uint8_t *bits, uint8_t size, uint32_t *index)
{
    uint8_t value = 0;
    *index -= size; // decrement index to the starting point
    for(uint32_t i=0; i<size; i++)
        value = (value<<1) | bits[*index+i];
    return value;
}

int main()
{
    // sample program
    uint8_t array[] = {0x00,0x03,0x02,0x01,0x42,0x82,0x86,0x04,0x10,0x45};
    
    // program with zero padding
    // uint8_t array[] = {0xE8,0x39,0x06,0xA0,0xC4,0x16,0x82,0x90,0x4A,0x08,0x41};
    
    uint32_t array_size = sizeof(array)/sizeof(*array); // 10 bytes
    uint32_t bits_size = 8*array_size; // 80 bytes
    uint8_t* bits = malloc(bits_size);
    
    for(uint32_t a=0;a<array_size;a++)
        for(uint32_t b=0;b<8;b++)
            bits[a*8+b] = (array[a] >> (7-b)) & 1;
    
    puts("Binary program file:");
    for(uint32_t i=0;i<bits_size;i++)
        printf("%s%d",(i%8?"":" "),bits[i]);
    puts("");
    
    enum                    {  MOV,  CAL,  RET,  REF,  ADD,  PRINT,  NOT,  EQU};
    uint8_t params[]      = {    2,    1,    0,    2,    2,      1,    1,    1};
    const char *opcodes[] = {"MOV","CAL","RET","REF","ADD","PRINT","NOT","EQU"};

    enum                    {  VAL,  REG,  STK,  PTR};
    uint8_t value_size[]  = {    8,    3,    5,    5};
    const char *types[]   = {"VAL","REG","STK","PTR"};

    uint32_t index = bits_size; // start at end
    
    // minimum program size is function(3) + opcode(3) + size(5)
    // if there are less than that number of bits then it must be padding
    while(index>10)
    {
        uint8_t size = getBits(bits,5,&index);
        printf("\nsize=%d\n",size);
        if (size > 0)
        {
            for(int o=0; o<size; o++)
            {
                uint8_t opcode = getBits(bits,3,&index);
                printf("opcode=%s",opcodes[opcode]);
                
                for(int p=0; p<params[opcode]; p++)
                {
                    //printf("%c ",p?',':':');
                    
                    uint8_t type = getBits(bits,2,&index);
                    _putchar("type= ");
                    _putchar(types[type]);
                    
                    uint8_t value = getBits(bits,value_size[type],&index);
                    _putchar("value");
                        _putchar(value);
                }
                
                puts("");
            }
        
            uint8_t function = getBits(bits,3,&index);
            _putchar("function");
            _putchar("\0");
                _putchar(function);
        }
    }
    return 0;
}
