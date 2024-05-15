#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    LW,
    SW,
    SUB,
    DIV,
    MUL,
    ADD,
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
    case SUB:
        return "SUB";
    case DIV:
        return "DIV";
    case MUL:
        return "MUL";
    case ADD:
        return "ADD";
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
 *
 * It also stores the clock cycle that it was issued, finished and written in.
 */
typedef struct
{
    Operation operation;
    InstructionType type;
    Instruction_ThreeReg threeReg;
    Instruction_TwoReg twoReg;
    int issuedAt;
    int startAt;
    int finishedAt;
    int writtenAt;
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

/**
 * @brief Print an parser error (with colors UwU), and immediatly stops the program execution with `exit(0)`
 */
void _panicParserError(char *message, char *instruction)
{
    printf("\033[1;31m[ParserError]");
    printf("\033[0m at '\033[0;36m%s'\033[0m", instruction);
    printf("\033[0m %s\n", message);
    exit(0);
}

//@TODO: change this to switch bc it's O(1)
Operation _getOperation(char *opString)
{
    if (strcmp(opString, "SW") == 0)
        return SW;
    else if (strcmp(opString, "LW") == 0)
        return LW;
    else if (strcmp(opString, "SUB") == 0)
        return SUB;
    else if (strcmp(opString, "DIV") == 0)
        return DIV;
    else if (strcmp(opString, "MUL") == 0)
        return MUL;
    else if (strcmp(opString, "ADD") == 0)
        return ADD;

    _panicParserError("Invalid operation", opString);
    return -1; // Unreachable
}

/**
 * @brief Gets an operation and returns his Type (`TwoReg` or `ThreeReg`)
 */
InstructionType getInstructionType(Operation op)
{
    if (op == SUB || op == DIV || op == MUL || op == ADD)
        return ThreeReg;

    return TwoReg;
}

/**
 * @brief "Parses" an threeRegister operation.
 * Follows the syntax: _` R[n] comma R[N] comma R[N]_
 */
Instruction_ThreeReg _parseInstructionThreeReg(char *instructionStr)
{
    int registers[3] = {0};
    int register_count = 0;
    for (int k = 0; k < 30; k++)
    {
        if (instructionStr[k] == '\n' || instructionStr[k] == 0)
            break;

        switch (instructionStr[k])
        {
        case 'R': // Registers
            k += 1;
            int initial = k;
            char tmpStr[10] = {0};
            while (instructionStr[k] >= '0' && instructionStr[k] <= '9')
            {
                tmpStr[k - initial] = instructionStr[k];
                k += 1;
            }
            k -= 1;
            registers[register_count] = atoi(tmpStr);
            register_count++;
            break;
        case ',':
        case ' ':
            break;
        case 0:
        default:
            char message[50];
            sprintf(message, "invalid character at position %d - '%c'", k, instructionStr[k]);
            _panicParserError(message, instructionStr);
        }
    }
    if (register_count != 3)
    {
        char message[50];
        sprintf(message, "Missing registers. Expected 3, received %d", register_count);
        _panicParserError(message, instructionStr);
    }

    Instruction_ThreeReg instruction = {registers[0], registers[1], registers[2]};
    return instruction;
}

/**
 * @brief "Parses" an twoRegister operation.
 * Follows the syntax: _`  R[n]   comma   [n]   (   R[n]    )`_
 */
Instruction_TwoReg _parseInstructionTwoReg(char *instructionStr)
{
    int inputReceived[3] = {0}; // Validates input
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
            inputReceived[0] = 1;
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
            inputReceived[1] = 1;
            break;
        case '(': // sourgeReg1
            k += 1;

            if (instructionStr[k] != 'R')
            {
                char message[50];
                sprintf(message, "Expected 'R' after brackets, but received '%c'", instructionStr[k]);
                _panicParserError(message, instructionStr);
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
            inputReceived[2] = 1;
            k -= 1;
            break;
        case ')': // Success, the ONLY return method here
            if (inputReceived[0] == 0)
                _panicParserError("'target register' is missing ", instructionStr);

            if (inputReceived[1] == 0)
                _panicParserError("'first source register' is missing ", instructionStr);

            if (inputReceived[2] == 0)
                _panicParserError("'second source register' is missing ", instructionStr);

            Instruction_TwoReg returnInstruct = {targetReg, sourceReg1, offset};
            return returnInstruct;
        case ' ':
            break;
        case 0:
        default:
            char message[50];
            sprintf(message, "invalid character at position %d - '%c'", k, instructionStr[k]);
            _panicParserError(message, instructionStr);
        }
    }
    _panicParserError("Ended misteriously. Check if the instructions ends with an ')'", instructionStr);

    Instruction_TwoReg failedInstruct = {0, 0, 0};
    return failedInstruct;
}

/**
 * @brief Identifies an instruction as `Instruction_TwoReg` or `Instruction_ThreeReg`, and parses it;
 */
Instruction _parseFullInstruction(char *instructionStr, Operation op)
{
    Instruction returnInstruction;
    returnInstruction.operation = op;
    if (getInstructionType(op) == TwoReg)
    {
        returnInstruction.type = TwoReg;
        returnInstruction.twoReg = _parseInstructionTwoReg(instructionStr);
        returnInstruction.issuedAt = -1;
        returnInstruction.startAt = -1;
        returnInstruction.finishedAt = -1;
        returnInstruction.writtenAt = -1;
        return returnInstruction;
    }
    returnInstruction.issuedAt = -1;
    returnInstruction.startAt = -1;
    returnInstruction.finishedAt = -1;
    returnInstruction.writtenAt = -1;
    returnInstruction.type = ThreeReg;
    returnInstruction.threeReg = _parseInstructionThreeReg(instructionStr);
    return returnInstruction;
}

/**
 * @brief Prints the instruction data as human readable.
 */
void debugInstruction(Instruction instruct)
{
    printf("\n");
    if (getInstructionType(instruct.operation) == TwoReg)
    {
        printf("[Operation]: '%s' - (TwoReg)\n", getOperationName(instruct.operation));
        printf("[target]: %d\n", instruct.twoReg.targetReg);
        printf("[source]: %d\n", instruct.twoReg.srcReg1);
        printf("[offset]: %d\n", instruct.twoReg.offset);
    }
    else
    {
        printf("[Operation]: '%s' - (ThreeReg)\n", getOperationName(instruct.operation));
        printf("[target]: %d\n", instruct.threeReg.targetReg);
        printf("[source_1]: %d\n", instruct.threeReg.srcReg1);
        printf("[source_2]: %d\n", instruct.threeReg.srcReg2);
    }
    printf("[issuedAt]: %d\n", instruct.issuedAt);
    printf("[finishedAt]: %d\n", instruct.finishedAt);
    printf("[writtenAt]: %d\n", instruct.writtenAt);
}

/**
 * ## Parses a instruction.
 *
 * It decides if it's a twoReg or threeReg and parses it.
 * If an error is detected, the program will PANIC, throwing a exit() non-treatable error!
 */
Instruction parseInstruction(char *instructionStr)
{
    remove_newline(instructionStr);
    char *saveInstr;
    char *token = strtok_r(instructionStr, " ", &saveInstr);
    int operator= _getOperation(token);
    Instruction instruct = _parseFullInstruction(saveInstr, operator);
    return instruct;
}
