#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"

#define MAX_INSTR_LENGTH 25  // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 16        // Number of FP registers
#define STATIONS_AMOUNT 7    // Number of reservation stations - 2 adders, 1 multiplier, 2 load, 2 store

int clock = 0;

typedef enum
{
    Adder,      // 0
    Multiplier, // 1
    Load,       // 2
    Store       // 3
} StationType;

typedef struct
{
    bool ready;
    bool busy;
    StationType type;
    Instruction in;
} Station;

/**
 * Se retornar -1 é por que está busy.
 */
int findNonBusyStation(Station station[STATIONS_AMOUNT], StationType type)
{
    for (int i = 0; i < STATIONS_AMOUNT; i++)
    {
        if (type == station[i].type)
        {
            if (!station[i].busy)
                return i;
        }
    }
    return -1;
}

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

StationType getDispatchTarget(Instruction inst)
{
    switch (inst.operation)
    {
    case ADD:
    case SUB:
        return Adder;
    case LW:
        return Load;
    case SW:
        return Store;
    case MUL:
    case DIV:
        return Multiplier;
    default:
        printf("ERROR - GetDispatchTarget, unreachable!");
        exit(0);
    }
}

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

    int currentInstructionPos = 0;
    while (1)
    {
        if (currentInstructionPos == instructionAmount)
            break;
        Instruction currentInstruction = instructionsList[currentInstructionPos];
        // debugInstruction(currentInstruction);
        StationType stationType = getDispatchTarget(instructionsList[currentInstructionPos++]);
        int targetStationIndex = findNonBusyStation(reservationStations, stationType);

        if (targetStationIndex == -1)
        {
            printf("TODO - Stations are full, but it's not implemented");
            exit(0);
        }

        reservationStations[targetStationIndex].busy = 1;
        reservationStations[targetStationIndex].in = currentInstruction;
        printf("Reservation Station: \n");
        printf("Busy: %d", reservationStations[targetStationIndex].busy);
        debugInstruction(currentInstruction);
        printf("[Index]: %d\n\n", targetStationIndex);
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
