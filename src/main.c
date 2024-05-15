#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Instruction.h"
#include "Station.h"
#include "Register.h"

#define MAX_INSTR_LENGTH 25  // Maximum length of each instruction
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions
#define REG_AMOUNT 32        // Number of FP registers
#define ADDR_REG_AMOUNT 16 // Number of address registers 

int clock = 0;

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
    const char inputPath[] = "./input/input_01.txt"; // Change path if needed.

    short instructionAmount = readInstructions(inputPath, inputInstructions);

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

    /** Initialize Registers */
    Register registers[REG_AMOUNT];
    for (short i = 0; i < REG_AMOUNT; i++)
        registers[i] = (Register){-1, 0};

    /** Initialize Structures */
    Station reservationStations[STATIONS_AMOUNT] = {
        {0, Adder, 0},
        {0, Adder, 0},
        {0, Multiplier, 0},
        {0, Load, 0},
        {0, Load, 0},
        {0, Store, 0},
        {0, Store, 0}
    };

    /**
     * Initialized with 0 in all positions to show there are no pos yet.
     */
    Station runtimeList[MAX_INSTRUCTIONS];
    for (short i = 0; i < MAX_INSTRUCTIONS; i++)
        runtimeList[i] = (Station){0, 0, 0};

    int currentInstructionPos = 0;
    while (1)
    {
        /** In-order dispatch */
        Instruction currentInstruction = instructionsList[currentInstructionPos];

        short stationIndex = dispatchInstruction(reservationStations, currentInstruction, clock, runtimeList);

        if (currentInstructionPos < instructionAmount && stationIndex != -1)
            currentInstructionPos += 1;

        // Essa operacao deve ser feita antes do novo dispatch
        /** Searches the runtimeList */
        for (int i = 0; i < MAX_INSTRUCTIONS; i++)
        {
            if (runtimeList[i].busy == -1)
                continue;
            
            // The maximum value of registers a operation contains is 3, if it's a `TwoReg`, [2] is -1
                short associatedRegisters[3] = {-1}; 

            if(runtimeList[i].instruction.startedAt == -1) { 

                // Fetch source and target registers from operation
                InstructionType type = getInstructionType(runtimeList[i].instruction.operation); 

                if(type == TwoReg) {
                    associatedRegisters[0] = runtimeList[i].instruction.twoReg.targetReg;
                    associatedRegisters[1] = runtimeList[i].instruction.twoReg.srcReg1;
                    associatedRegisters[2] = runtimeList[i].instruction.twoReg.srcReg1;   
                } else {
                    associatedRegisters[0] = runtimeList[i].instruction.threeReg.targetReg;
                    associatedRegisters[1] = runtimeList[i].instruction.threeReg.srcReg1;
                    associatedRegisters[2] = runtimeList[i].instruction.threeReg.srcReg2;
                }

                if(registers[associatedRegisters[0]].busyBy == -1)
                    registers[associatedRegisters[0]].busyBy = stationIndex;
                
                if(registers[associatedRegisters[0]].busyBy != stationIndex)
                    continue;

                if(type == TwoReg) {
                    if(registers[associatedRegisters[1]].busyBy == -1)
                    registers[associatedRegisters[1]].busyBy = stationIndex;
                
                    if(registers[associatedRegisters[1]].busyBy != stationIndex)
                        continue;
                } else {
                    if(registers[associatedRegisters[1]].busyBy == -1)
                    registers[associatedRegisters[1]].busyBy = stationIndex;
                
                    if(registers[associatedRegisters[1]].busyBy != stationIndex)
                        continue;
                    
                    if(registers[associatedRegisters[2]].busyBy == -1)
                    registers[associatedRegisters[2]].busyBy = stationIndex;
                
                    if(registers[associatedRegisters[2]].busyBy != stationIndex)
                        continue;
                }

                runtimeList[i].instruction.startedAt = clock;
                continue;
            }

            short opTime = getOperationTime(runtimeList[i].instruction.operation); 

            if(runtimeList[i].instruction.startedAt + opTime >= clock) {
                Operation operationType = runtimeList[i].instruction.operation;
                int result = 0;

                switch(operationType) 
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
                        result = registers[associatedRegisters[1]].value / registers[associatedRegisters[2]].value;
                        registers[associatedRegisters[0]].value = result;
                        break;
                    case SW:
                    case LW:
                        registers[associatedRegisters[0]].value = registers[associatedRegisters[1]].value;
                        break;
                    default:
                        printf("Unreachable code.");
                        exit(0);
                }
                
                runtimeList[i].instruction.finishedAt = clock;
                runtimeList[i].instruction.writtenAt = clock + 1;
                continue;
            }
            
            if(runtimeList[i].instruction.writtenAt == clock) {
                registers[associatedRegisters[0]].busyBy = -1;
                registers[associatedRegisters[1]].busyBy = -1;
                registers[associatedRegisters[2]].busyBy = -1;

                runtimeList[i] = (Station){0, 0, 0};
                reservationStations[stationIndex] = (Station){0,0,0};
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
