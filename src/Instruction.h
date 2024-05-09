#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    LW,
    SW,
    SUBD,
    DIVD,
    MULD,
    ADDD,
} Operation;

typedef enum
{
    TwoReg,
    ThreeReg,
} InstructionType;

const char *getOperationName(Operation op)
{
    switch (op)
    {
    case LW:
        return "LW";
    case SW:
        return "SW";
    case SUBD:
        return "SUBD";
    case DIVD:
        return "DIVD";
    case MULD:
        return "MULD";
    case ADDD:
        return "ADDD";
    }
}

/**
 * Represents a instruction that follows: `OP R0,0(R1)`
 * Where `OP` -> operation | `R0` -> targetReg | `0` -> offset | `R1` -> srcReg1
 */
typedef struct
{
    int targetReg;
    int srcReg1;
    int offset;
} Instruction_TwoReg;

/**
 * Represents a instruction that follows: `OP R1,R2,R3`
 * Where `OP` -> operation | `R1` -> targetReg | `R2` -> srcReg1 | `R3` -> srcReg2
 */
typedef struct
{
    int targetReg;
    int srcReg1;
    int srcReg2;
} Instruction_ThreeReg;

/**
 * Instruction Wrapper, because there is no Polymorphism ~in this fucking~ language.
 */
typedef struct
{
    Operation operation;
    InstructionType type;
    Instruction_ThreeReg threeReg;
    Instruction_TwoReg twoReg;
} Instruction;

//@TODO: change this to switch bc it's O(1)
Operation getOperation(char *opString)
{
    if (strcmp(opString, "SW") == 0)
        return SW;
    else if (strcmp(opString, "LW") == 0)
        return LW;
    else if (strcmp(opString, "SUBD") == 0)
        return SUBD;
    else if (strcmp(opString, "DIVD") == 0)
        return DIVD;
    else if (strcmp(opString, "MULD") == 0)
        return MULD;
    else if (strcmp(opString, "ADDD") == 0)
        return ADDD;

    return -1; // Unknown operation
}

/**
 * Gets an operation and returns his Type (`TwoReg` or `ThreeReg`)
 */
InstructionType getInstructionType(Operation op)
{
    if (op == SUBD || op == DIVD || op == MULD || op == ADDD)
        return ThreeReg;

    return TwoReg;
}

/**
 * "Parses" an threeRegister operation.
 * Follows the syntax: _` R[n] comma R[N] comma R[N]_
 */
Instruction_ThreeReg _parseInstructionThreeReg(char *instructionStr)
{
    // JUMP FIRST_SPACE
    int j;
    for (int i = 0; i < 30; i++)
        if (instructionStr[i] == ' ' && instructionStr[i + 1] == 'R')
        {
            j = i + 1;
            break;
        }

    // PARSE FIRST_REGISTER
    char targetRegStr[10];
    int i = 0;
    for (j = j + 1; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        targetRegStr[i] = instructionStr[j];
        i++;
    }
    targetRegStr[i] = '\0';
    int targetReg = atoi(targetRegStr);

    // Jump after comma
    for (j = j + 1; instructionStr[j] == ',' || instructionStr[j] == ' '; j++)
        ;

    // PARSE SECOND_REGISTER
    char srcReg1Str[10];
    i = 0;
    for (j = j + 1; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        srcReg1Str[i] = instructionStr[j];
        i++;
    }
    srcReg1Str[i] = '\0';
    int srcReg1 = atoi(srcReg1Str);

    // Jump after comma
    for (j = j + 1; instructionStr[j] == ',' || instructionStr[j] == ' '; j++)
        ;

    // PARSE THIRD_REGISTER
    char srcReg2Str[10];
    i = 0;
    for (j = j + 1; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        srcReg2Str[i] = instructionStr[j];
        i++;
    }
    srcReg2Str[i] = '\0';
    int srcReg2 = atoi(srcReg2Str);

    Instruction_ThreeReg returnInstruct = {targetReg, srcReg1, srcReg2};

    return returnInstruct;
}

/**
 * "Parses" an twoRegister operation.
 * Follows the syntax: _`  R[n]   comma   [n]   (   R[n]    )`_
 */
Instruction_TwoReg _parseInstructionTwoReg(char *instructionStr)
{
    // `SPACE` R[n] `comma` [n] `(` R[n] `)`

    // JUMP FIRST_SPACE
    int j;
    for (int i = 0; i < 30; i++)
        if (instructionStr[i] == ' ' && instructionStr[i + 1] == 'R')
        {
            j = i + 1;
            break;
        }

    // PARSE FIRST_REGISTER
    char targetRegStr[10];
    int i = 0;
    for (j = j + 1; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        targetRegStr[i] = instructionStr[j];
        i++;
    }
    targetRegStr[i] = '\0';
    int targetReg = atoi(targetRegStr);

    // Jump after comma
    for (j = j + 1; instructionStr[j] == ',' || instructionStr[j] == ' '; j++)
        ;

    // PARSE OFFSET
    char offsetStr[10];
    i = 0;
    for (j = j; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        offsetStr[i] = instructionStr[j];
        i++;
    }
    int offset = atoi(offsetStr);

    // Jump after '('
    for (j = j; instructionStr[j] == '(' || instructionStr[j] == ' '; j++)
        ;

    // PARSE srcReg1;
    char srcReg1Str[10];
    i = 0;
    for (j = j + 1; instructionStr[j] >= 48 && instructionStr[j] <= 57; j++)
    {
        srcReg1Str[i] = instructionStr[j];
        i++;
    }
    int srcReg1 = atoi(srcReg1Str);

    Instruction_TwoReg returnInstruct = {targetReg, srcReg1, offset};

    return returnInstruct;
}

/**
 * Identifies an instructiong as `Instruction_TwoReg` or `Instruction_ThreeReg`, and parses it;
 */
Instruction parseFullInstruction(char *instructionStr, Operation op)
{
    Instruction returnInstruction;
    returnInstruction.operation = op;
    if (getInstructionType(op) == TwoReg)
    {
        returnInstruction.type = TwoReg;
        returnInstruction.twoReg = _parseInstructionTwoReg(instructionStr);
        return returnInstruction;
    }

    returnInstruction.type = ThreeReg;
    returnInstruction.threeReg = _parseInstructionThreeReg(instructionStr);
    return returnInstruction;
}

void debugInstruction(Instruction instruct)
{
    printf("-- Instruction Debug --");
    printf("\n[Operation] = %s", getOperationName(instruct.operation));
    printf("\n[Type] = ");
    if (getInstructionType(instruct.operation) == TwoReg)
    {
        printf("TwoReg\n");
        printf("--------\n");
        printf("* targetReg: %d\n", instruct.twoReg.targetReg);
        printf("* srcReg1: %d\n", instruct.twoReg.srcReg1);
        printf("* offset: %d\n", instruct.twoReg.offset);
    }
    else
    {
        printf("ThreeReg\n");
        printf("--------\n");
        printf("* targetReg: %d\n", instruct.threeReg.targetReg);
        printf("* srcReg1: %d\n", instruct.threeReg.srcReg1);
        printf("* srcReg2: %d\n", instruct.threeReg.srcReg2);
    }
}

bool parseInstruction(char *instructionStr, Instruction *in)
{
    char *token = strtok(instructionStr, " ");
    int operator= getOperation(token);
    if (operator== - 1) // Invalid token
        return false;

    Instruction instruct = parseFullInstruction(instructionStr, operator);

    printf("\n\n\n");
    debugInstruction(instruct);
    return true;
}
