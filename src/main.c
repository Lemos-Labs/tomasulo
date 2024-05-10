#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"

#define MAX_INSTR_LENGTH 25 // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions

int readInstructions(const char* filePath, char instructions[][MAX_INSTR_LENGTH]) {
    FILE *fptr;
    fptr = fopen(filePath, "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(0);
    }

    int count = 0;
    while(fgets(instructions[count], MAX_INSTR_LENGTH, fptr) != NULL && count < MAX_INSTRUCTIONS) { count++; }

    fclose(fptr);
    return count;
};

int main(void) {
    char inputInstructions[MAX_INSTRUCTIONS][MAX_INSTR_LENGTH];
    const char inputPath[] = "./input/input_01.txt"; // Change path if needed.

    int instructionAmount = readInstructions(inputPath, inputInstructions);      

    if (instructionAmount == -1) {
        printf("Failed to read input file.\n");
        return 1;
    }

    // Print instructions for debugging
    for (int i = 0; i < instructionAmount; i++) {
        printf("Instruction %d: %s", i + 1, inputInstructions[i]);
    }

    Instruction instructions[MAX_INSTRUCTIONS];

    for (short i = 0; i < instructionAmount; i++) {
        if (!parseInstruction(inputInstructions[i])) {
            printf("Error at parsing instruction at line %d\n", i + 1);
            return 1;
        }
    }

    return 0;
}

/**
 * Temos 2 tipos de estacao de reserva:
 * 1. 4x de operacao inteira
 * 2. 2x de ponto flutuante
 * 
 * Eles armazenam instrucoes 
*/
