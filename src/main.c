#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"
#include "Station.h"

#define MAX_INSTR_LENGTH 25  // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 16        // Number of FP registers

int clock = 0;

int readInstructions(const char *filePath, char instructions[][MAX_INSTR_LENGTH])
{
    FILE *fptr;
    fptr = fopen(filePath, "r");

    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    int count = 0;
    while (fgets(instructions[count], MAX_INSTR_LENGTH, fptr) != NULL && count < MAX_INSTRUCTIONS)
    {
        count++;
    }

    fclose(fptr);
    return count;
};

int main(void)
{
    char inputInstructions[MAX_INSTRUCTIONS][MAX_INSTR_LENGTH];
    const char inputPath[] = "./input/input_01.txt"; // Change path if needed.

    int instructionAmount = readInstructions(inputPath, inputInstructions);

    if (instructionAmount == -1)
    {
        printf("\033[1;31m Failed to read input file.\n");
        return 1;
    }

    Instruction instructionsList[instructionAmount];

    for (short i = 0; i < instructionAmount; i++)
    {
        instructionsList[i] = parseInstruction(inputInstructions[i]);
    }

    /** Initialize Structures */
    int registers[REG_AMOUNT] = {0};
    Station reservationStations[STATIONS_AMOUNT] = {
        {0, 0, Adder, 0}, {0, 0, Adder, 0}, {0, 0, Multiplier, 0}, {0, 0, Load, 0}, {0, 0, Load, 0}, {0, 0, Store, 0}, {0, 0, Store, 0}};

    /**
     * Initialized with -1 in all positions to show there are no pos yet.
    */
    Station runtimeList[MAX_INSTRUCTIONS] = {-1};

    int currentInstructionPos = 0;
    while (1)
    {
        if (currentInstructionPos == instructionAmount)
            break;
        Instruction currentInstruction = instructionsList[currentInstructionPos];
        dispatchInstruction(reservationStations, currentInstruction, clock, runtimeList);
        debugReservationStation(reservationStations[5]);
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
