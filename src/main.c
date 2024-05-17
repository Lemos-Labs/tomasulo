#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"
#include "Station.h"
#include "Register.h"
#include "Log.h"

#define MAX_INSTR_LENGTH 25  // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 32        // Number of FP registers
#define ADDR_REG_AMOUNT 16   // Number of address registers
#define STATIONS_AMOUNT 7    // Number of stations

const char inputPath[] = "./input/sum_69_0.txt"; // Change path if needed.

int clock = 1;
short readInstructions(const char *filePath, char instructions[][MAX_INSTR_LENGTH])
{
    FILE *fptr;
    fptr = fopen(filePath, "r");

    if (fptr == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    short count = 0;
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

    short instructionAmount = readInstructions(inputPath, inputInstructions);

    if (instructionAmount == -1)
    {
        printf("\033[1;31m Failed to read input file.\n");
        return 1;
    }

    Instruction instructionsList[instructionAmount];

    for (short i = 0; i < instructionAmount; i++)
        instructionsList[i] = parseInstruction(inputInstructions[i]);

    /** Initialize Registers */
    Register registers[REG_AMOUNT];
    for (short i = 0; i < REG_AMOUNT; i++)
        registers[i] = (Register){-1, i};

    /** Initialize Structures */
    Station reservationStations[STATIONS_AMOUNT] = {
        {0, Adder, 0, 0},
        {0, Adder, 0, 0},
        {0, Multiplier, 0, 0},
        {0, Load, 0, 0},
        {0, Load, 0, 0},
        {0, Store, 0, 0},
        {0, Store, 0, 0}};

    int currentInstructionPos = 0;
    while (1)
    {
        newCicle(clock);

        /** In-order dispatch */
        Instruction currentInstruction = instructionsList[currentInstructionPos];

        if (currentInstructionPos < instructionAmount)
        {
            short stationIndex = dispatchInstruction(reservationStations, currentInstruction, clock, currentInstructionPos);
            if (stationIndex != -1)
            {
                currentInstructionPos += 1;
                printf("\n[{%d}] Instrucao numero %d(%d) foi dispachada\n", clock, currentInstructionPos, stationIndex);
                logInstructionStep(0, currentInstructionPos);
            }
            else
            {
                printf("[{%d}] Instrucao numero %d tentou entrar, mas ta full", clock, currentInstructionPos + 1);
                logDependecy(currentInstructionPos + 1);
            }
        }

        /** Executes all the reservationsStations */
        for (int i = 0; i < STATIONS_AMOUNT; i++)
        {
            if (reservationStations[i].busy == 0)
                continue;

            short associatedRegisters[3] = {-1};

            if (reservationStations[i].instruction.issuedAt == clock)
                continue;
            // Acabou de ir para o banco de registrador
            if (reservationStations[i].instruction.startedAt == -1)
            {
                printf("\n[{%d}] (%d) Entrou no startedAt -1\n", clock, reservationStations[i].debugInstructionLine);
                InstructionType type = getInstructionType(reservationStations[i].instruction.operation);
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
                if (!isRegisterFree(registers[associatedRegisters[0]], i))
                {
                    printf("\n[{%d}] (%d) Registrador %d ta busy, vou esperar", clock, reservationStations[i].debugInstructionLine, associatedRegisters[0]);
                    logDependencyRegister(associatedRegisters[0], reservationStations[i].debugInstructionLine);
                    continue;
                }
                if (!isRegisterFree(registers[associatedRegisters[1]], i))
                {
                    printf("\n[{%d}] (%d) Registrador %d ta busy, vou esperar", clock, reservationStations[i].debugInstructionLine, associatedRegisters[1]);
                    logDependencyRegister(associatedRegisters[1], reservationStations[i].debugInstructionLine);
                    continue;
                }

                if (type == ThreeReg)
                {
                    if (!isRegisterFree(registers[associatedRegisters[2]], i))
                    {
                        logDependencyRegister(associatedRegisters[2], reservationStations[i].debugInstructionLine);
                        printf("\n[{%d}] (%d) Registrador %d ta busy, vou esperar", clock, reservationStations[i].debugInstructionLine, associatedRegisters[2]);
                        continue;
                    }
                    // registers[associatedRegisters[2]].busyBy = i;
                }
                registers[associatedRegisters[0]].busyBy = i;
                // registers[associatedRegisters[1]].busyBy = i;
                printf("\n[{%d}] (%d) Saiu do startedAt -1\n", clock, reservationStations[i].debugInstructionLine);
                logInstructionStep(1, reservationStations[i].debugInstructionLine);
                reservationStations[i].instruction.startedAt = clock;
                continue;
            }

            // Escrever no registrador
            if (reservationStations[i].instruction.writtenAt == clock)
            {
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
                printf("\n[{%d}] (%d) Entrou no write stage!\n", clock, reservationStations[i].debugInstructionLine);
                logInstructionStep(3, reservationStations[i].debugInstructionLine);
                registers[associatedRegisters[0]].busyBy = -1;
                // registers[associatedRegisters[1]].busyBy = -1;
                // registers[associatedRegisters[2]].busyBy = -1;

                reservationStations[i].busy = 0;
                printf("\n[{%d}] (%d) Finalizou o write stage!\n", clock, reservationStations[i].debugInstructionLine);
                continue;
            }

            // Se ainda nao terminou...
            if ((reservationStations[i].instruction.startedAt + getOperationTime(reservationStations[i].instruction.operation)) <= clock)
            {
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
                printf("\n[{%d}] (%d) Entrou no final do seu clock!\n", clock, reservationStations[i].debugInstructionLine);
                logInstructionStep(2, reservationStations[i].debugInstructionLine);
                Operation operationType = reservationStations[i].instruction.operation;
                int result = 0;

                switch (operationType)
                {
                case ADD:
                    result = registers[associatedRegisters[1]].value + registers[associatedRegisters[2]].value;
                    registers[associatedRegisters[0]].value = result;
                    break;
                case SUB:
                    result = registers[associatedRegisters[1]].value - registers[associatedRegisters[2]].value;
                    registers[associatedRegisters[0]].value = result;
                    break;
                case MUL:
                    result = registers[associatedRegisters[1]].value * registers[associatedRegisters[2]].value;
                    registers[associatedRegisters[0]].value = result;
                    break;
                case DIV:
                    if (registers[associatedRegisters[2]].value == 0)
                    {
                        result = registers[associatedRegisters[1]].value / 1;
                        registers[associatedRegisters[0]].value = result;
                    }
                    else
                    {
                        result = registers[associatedRegisters[1]].value / registers[associatedRegisters[2]].value;
                        registers[associatedRegisters[0]].value = result;
                    }
                    break;
                case SW:
                case LW:
                    registers[associatedRegisters[0]].value = registers[associatedRegisters[1]].value;
                    break;
                default:
                    printf("Unreachable code.");
                    exit(0);
                }
                printf("\n[{%d}] (%d) Saiu do final do seu clock!\n", clock, reservationStations[i].debugInstructionLine);
                reservationStations[i].instruction.finishedAt = clock;
                reservationStations[i].instruction.writtenAt = clock + 1;
                continue;
            }
        }

        logRegisters(registers, reservationStations);
        logStations(reservationStations);
        printf("\n == fim do clock %d == ", clock);
        clock += 1;

        if (clock >= 10)
        {
            int allDone = 1;
            for (int i = 0; i < STATIONS_AMOUNT; i++)
            {
                if (reservationStations[i].busy == 1)
                    allDone = 0;
            }
            if (allDone == 1)
                return 0;
        }

        /** Prevent infinity loop*/
        if (clock >= 1000)
            return 0;
    }
}
