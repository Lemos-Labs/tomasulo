#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
 * When the `instructionType` is `threeReg`, the programmer should use ONLY the threeReg field.
 * In the other side, if the `instructionType` is `twoReg`, the programmer should use twoReg field.
 */

typedef struct
{
    Operation operation;
    InstructionType type;
    Instruction_ThreeReg threeReg;
    Instruction_TwoReg twoReg;
} Instruction;

void remove_newline(char *str)
{
    int length = strlen(str);

    // Check if the last character is a newline
    if (length > 0 && str[length - 1] == '\n')
    {
        // Replace the newline character with the null terminator
        str[length - 1] = '\0';
    }
}
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
    printf("%s:\n", instructionStr);
    int sourceReg1 = 0;
    int targetReg = 0;
    int offset = 0;
    for (int k = 0; k < 30; k++)
    {
        if (instructionStr[k] == '\n' || instructionStr[k] == 0)
            break;

        switch (instructionStr[k])
        {
        case 'R': // targetReg
            k += 1;
            int initial = k;
            char tmpStr[10] = {0};
            while (instructionStr[k] >= '0' && instructionStr[k] <= '9')
            {
                tmpStr[k - initial] = instructionStr[k];
                k += 1;
            }
            k -= 1;
            targetReg = atoi(tmpStr);
            break;
        case ',': // Offset
            k += 1;
            initial = k;
            char offsetTmp[10] = {0};
            while (instructionStr[k] >= '0' && instructionStr[k] <= '9')
            {
                offsetTmp[k - initial] = instructionStr[k];
                k += 1;
            }
            offset = atoi(offsetTmp);
            k -= 1;
            break;
        case '(': // sourgeReg1
            k += 1;
            if (instructionStr[k] != 'R')
            {
                printf("[ParserError] Instruction '%s' - Expected 'R' after brackets, but received '%c'", instructionStr, instructionStr[k]);
                exit(0);
            }
            k += 1;
            initial = k;
            char srgRegTmp[10] = {0};
            while (instructionStr[k] >= '0' && instructionStr[k] <= '9')
            {
                srgRegTmp[k - initial] = instructionStr[k];
                k += 1;
            }
            srgRegTmp[k] = 0;
            sourceReg1 = atoi(srgRegTmp);
            k -= 1;
            break;
        case ')': // Success, the ONLY return method here
            Instruction_TwoReg returnInstruct = {targetReg, sourceReg1, offset};
            return returnInstruct;
        case ' ':
            break;
        case 0:
        default:
            printf("[ParserError] Instruction '%s' has a invalid character at position %d - '%c'", instructionStr, k, instructionStr[k]);
            exit(0);
        }
    }
    printf("[ParserError] Instruction '%s' ended misteriously. Check if the instruction ends with an ')'", instructionStr);
    exit(0);

    Instruction_TwoReg failedInstruct = {0, 0, 0};
    return failedInstruct;
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
        return;
    }
    return;
    printf("ThreeReg\n");
    printf("--------\n");
    printf("* targetReg: %d\n", instruct.threeReg.targetReg);
    printf("* srcReg1: %d\n", instruct.threeReg.srcReg1);
    printf("* srcReg2: %d\n", instruct.threeReg.srcReg2);
}

/**
 * ## [WARNING] Does not validate syntax.
 * If the syntax is misswritten, it won't return an error, but it'll execute wrongly.
 * trash-in trash-out
 *
 */
bool parseInstruction(char *instructionStr)
{
    remove_newline(instructionStr);
    char *saveInstr;
    char *token = strtok_r(instructionStr, " ", &saveInstr);
    int operator= getOperation(token);
    if (operator== - 1) // Invalid token
        return false;
    Instruction instruct = parseFullInstruction(saveInstr, operator);
    debugInstruction(instruct);
    return true;
}
