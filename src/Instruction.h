#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { ADDD, SUBD, MULTD, DIVD, LOAD, STORE, BNE, BEQ } Operation;

typedef struct {
    short issued;
    short executionStart;
    short executionEnd;
    short writeback;
} InstructionStatus;

typedef struct {
    Operation op;
    int dest;
    int src1;
    int src2;
} Instruction;

//@TODO: change this to switch bc it's O(1)
Operation getOperation(const char* opString) {
    if (strcmp(opString, "ADD") == 0) return ADDD;
    else if (strcmp(opString, "SUB") == 0) return SUBD;
    else if (strcmp(opString, "MULT") == 0) return MULTD;
    else if (strcmp(opString, "DIV") == 0) return DIVD;
    else if (strcmp(opString, "LOAD") == 0) return LOAD;
    else if (strcmp(opString, "STORE") == 0) return STORE;
    else if (strcmp(opString, "BEQ") == 0) return BEQ;
    else if (strcmp(opString, "BNE") == 0) return BNE;
    else return -1; // Unknown operation
}

bool parseInstruction(const char* instructionStr, Instruction* in) {
    char opString[10];
    int itemsScanned = sscanf(instructionStr, "%s %d %d %d", opString, &in->dest, &in->src1, &in->src2);

    if (itemsScanned < 2) return false; // Parsing error

    in->op = getOperation(opString);

    if (*&in->op == -1) return false; // Invalid operation

    return true;
}




