#include <stdio.h>
#include <stdlib.h>

typedef enum { ADDD, SUBD, MULTD, DIVD, LOAD, STORE, BNE, BEQ } Opcode;

typedef struct InstructionStatus {
    short issued;
    short executionStart;
    short executionEnd;
    short writeback;
};

typedef struct Instruction {
    Opcode opcode;
    
}