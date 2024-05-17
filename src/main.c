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

char *inputPath = "./input/input_02.txt";
char *outPath = "./out/sum_693_0.md";

/**
 * @brief Returns the size of the file (lines);
 * 
 * Panics if something goes wrong (like reading the life, ig...)
*/
short readInstructions(const char *filePath, char instructions[][MAX_INSTR_LENGTH])
{
    FILE *fptr;
    fptr = fopen(filePath, "r");

    if (fptr == NULL)
    {
        printf("\033[1;31mError opening file. \033[0m\n");
        exit(0);
    }

    short count = 0;
    while (fgets(instructions[count], MAX_INSTR_LENGTH, fptr) != NULL && count < MAX_INSTRUCTIONS)
    {
        count++;
    }

    fclose(fptr);
    if (count == -1)
    {
        printf("\033[1;31m Failed to read input file.\n");
        exit(0);
    }
    return count;
};

/**
 * @brief Parses CLI argument to initialize `inputPath` and `outPath`!
 *
 * For now, the args are: `./tomasulo.exe <input> <output>`, for simplicity, we are not using flags, but index arg based.
 */
void parseArgs(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("\033[1;31mUsage:\033[0m ./tomasulo.exe <input> <output>\n");
        exit(0);
    };
    inputPath = argv[1];
    outPath = argv[2];
}

int clock = 1;
int main(int argc, char *argv[])
{
    parseArgs(argc, argv);
    char inputInstructions[MAX_INSTRUCTIONS][MAX_INSTR_LENGTH];

    short instructionAmount = readInstructions(inputPath, inputInstructions);

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
        newCicle(clock, outPath);

        /** In-order dispatch */
        Instruction currentInstruction = instructionsList[currentInstructionPos];
        if (currentInstructionPos < instructionAmount)
        {
            short stationIndex = dispatchInstruction(reservationStations, currentInstruction, clock, currentInstructionPos);
            if (stationIndex != -1)
            {
                currentInstructionPos += 1;
                logInstructionStep(0, currentInstructionPos);
            }
            else
            {
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

            /** Start Operations */
            if (reservationStations[i].instruction.startedAt == -1)
            {
                InstructionType type = getInstructionType(reservationStations[i].instruction.operation);
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
                if (!isRegisterFree(registers[associatedRegisters[0]], i))
                {
                    logDependencyRegister(associatedRegisters[0], reservationStations[i].debugInstructionLine);
                    continue;
                }
                if (!isRegisterFree(registers[associatedRegisters[1]], i))
                {
                    logDependencyRegister(associatedRegisters[1], reservationStations[i].debugInstructionLine);
                    continue;
                }

                if (type == ThreeReg && !isRegisterFree(registers[associatedRegisters[2]], i))
                {
                    logDependencyRegister(associatedRegisters[2], reservationStations[i].debugInstructionLine);
                    continue;
                }
                registers[associatedRegisters[0]].busyBy = i;
                logInstructionStep(1, reservationStations[i].debugInstructionLine);
                reservationStations[i].instruction.startedAt = clock;
                continue;
            }

            /** Write Stage */
            if (reservationStations[i].instruction.writtenAt == clock)
            {
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
                logInstructionStep(3, reservationStations[i].debugInstructionLine);
                registers[associatedRegisters[0]].busyBy = -1;
                reservationStations[i].busy = 0;
                continue;
            }

            /** Operation Complete*/
            if ((reservationStations[i].instruction.startedAt + getOperationTime(reservationStations[i].instruction.operation)) <= clock)
            {
                getAssociatedRegisters(associatedRegisters, reservationStations[i].instruction);
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
                reservationStations[i].instruction.finishedAt = clock;
                reservationStations[i].instruction.writtenAt = clock + 1;
                continue;
            }
        }

        logRegisters(registers, reservationStations);
        logStations(reservationStations);
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
