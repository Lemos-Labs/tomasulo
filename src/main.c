#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"
#include "Station.h"
#include "Register.h"

#define MAX_INSTR_LENGTH 25  // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 32        // Number of FP registers

#define LOAD_STORE_CTIME 2
#define ADD_SUB_CTIME 3
#define MULT_DIV_CTIME 8

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
    Station reservationStations[STATIONS_AMOUNT] = {
        {0, 0, Adder, 0}, {0, 0, Adder, 0}, {0, 0, Multiplier, 0}, {0, 0, Load, 0}, {0, 0, Load, 0}, {0, 0, Store, 0}, {0, 0, Store, 0}};
    Register registers[REG_AMOUNT];
    for (int i = 0; i < REG_AMOUNT; i++)
        registers[i] = (Register){-1, 0};

    /**
     * Initialized with -1 in all positions to show there are no pos yet.
     */
    Station runtimeList[MAX_INSTRUCTIONS];
    for (int i = 0; i < MAX_INSTRUCTIONS; i++)
        runtimeList[i] = (Station){-1, -1, 0, 0};

    int currentInstructionPos = 0;
    while (1)
    {
        /** Dispatch */
        Instruction currentInstruction = instructionsList[currentInstructionPos];
        if (currentInstructionPos < instructionAmount && dispatchInstruction(reservationStations, currentInstruction, clock, runtimeList))
            currentInstructionPos += 1;

        // Essa operacao deve ser feita antes do novo dispatch
        /** Searches the runtimeList */
        for (int i = 0; i < MAX_INSTRUCTIONS; i++)
        {
            if (runtimeList[i].busy == -1)
                break;

            if(runtimeList[i].instruction.startAt == -1) {
                runtimeList[i].instruction.startAt = clock;
                break;
            }
            // 1. Checar Operacao. 
            // 2. Se nao tiver started:
            //// - Coloca started
            // 3. Se started + tempo_operacao >= clock
            //// - Se target estiver busy (de outro) entao BREAK
            //// - Se target nao estiver busy coloca como busy.
            //// - Se source(s) = busy entao BREAK.
            //// - Se source(s) nao estiverem busy, faz operacao e armazena no registrador target.
            //// - WriteTime = started+tempo_operacao + 1 (proxima operacao)
            // 4. Se WriteTime = clock
            //// - Libera os registradores
            //// - Remove do runtimelist
            //// - realinha o  runtimelist (faz um shitleft pra tirar o -1)
        }

        // debugReservationStation(reservationStations[5]);
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
