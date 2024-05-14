#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"

#define MAX_INSTR_LENGTH 25 // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 16 // Number of FP registers
#define STATIONS_AMOUNT 5 // Number of reservation stations - 3 adders and 2 multipliers
#define BUFFERS_AMOUNT 4 // Number of load/store buffers - 2 for each

int clock = 0;

typedef enum {
    Adder,
    Multiplier
} StationType;

typedef struct {
    bool busy;
    bool ready;
    StationType type;
    Instruction in;
} ReservationStation;

typedef enum {
    Load,
    Store
} BufferType;

typedef struct {
    bool busy;
    BufferType type;
    Instruction in;
} LoadStoreBuffer; static es(int registers[REG_AMOUNT], ReservationStation stations[STATIONS_AMOUNT], LoadStoreBuffer buffers[BUFFERS_AMOUNT]) {
    int register[REGISTER_AMOUT] = {0}

    for (int i = 0; i < STATIONS_AMOUNT; i++) {
        if (i <= 2) {
            stations[i] = { 0,0,Adder,0 };       
        } else {
            stations[i] = { 0,0,Multiplier,0 };       
        }
    }

    for (int i = 0; i < BUFFERS_AMOUNT; i++) {
        if (i <= 1) {
            buffers[i] = { 0,Load,0 }
        } else {
            buffers[i] = { 0,Store,0 }
        }        
    }
};

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
        printf("\033[1;31m Failed to read input file.\n");
        return 1;
    }

    Instruction instructionsList[instructionAmount];

    for (short i = 0; i < instructionAmount; i++) {
        instructionsList[i] = parseInstruction(inputInstructions[i]);
    }

    int registers[REG_AMOUNT];
    ReservationStation reservationStations[STATIONS_AMOUNT];
    LoadStoreBuffer loadStoreBuffers[BUFFERS_AMOUNT];

    initializeStructures(registers, reservationStations, LoadStoreBuffer);

    int i = 0;

    while(1) {
        debugInstruction(instructionsList[i++]);

        if (i == instructionAmount) {
            break;
        }

        clock += 1;
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
