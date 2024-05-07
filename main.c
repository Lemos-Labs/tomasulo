#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_INSTR_LENGTH 100 // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions

bool readInstructions(const char* filePath, char instructions[][MAX_INSTR_LENGTH]) {
    FILE *fptr;
    fptr = fopen(filePath, "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    while(fgets(instructions[count], MAX_INSTR_LENGTH, fptr) != NULL && count < MAX_INSTRUCTIONS) { count++; }

    fclose(fptr);
    return count;
};


int main(void) {
    
    char input[MAX_INSTRUCTIONS][MAX_INSTR_LENGTH];
    const char[] inputPath = "./input/input_01.txt" // Change path if needed.

    int readFileInput = readInstructions(inputPath, instructions);      

    if (instructionCount == -1) {
        printf("Failed to read input file.\n");
        return 1;
    }

    printf("Read %d instructions from the file:\n", instructionCount);
}