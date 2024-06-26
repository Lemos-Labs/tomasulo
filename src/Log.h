#include <stdio.h>

#define STATIONS_AMOUNT 7 // Number of stations
#define REG_AMOUNT 32     // Number of FP registers

char *LOG_PATH = "./out/sum_69_0.md";
void newCicle(int cicle, char *path)
{
    LOG_PATH = path;
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        printf("\n\033[0;36m# Cicle %d\033[0m\n", cicle);
        fprintf(file, "# CICLE %d\n## Log\n", cicle);
    }
    fclose(file);
}

/**
 * @brief TODOBRIEF
 *
 * @param step Current step 0..3; Where it means (in order): `Dispatch`, `Started`, `Completed` and `Wrote in Memory`
 */
void logInstructionStep(int step, int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        switch (step)
        {
        case 0:
            printf("* \033[32m[%d]\033[0m Dispatched\n", line);
            fprintf(file, "* [%d] Dispatched\n", line);
            break;
        case 1:
            printf("* \033[32m[%d]\033[0m Started\n", line);
            fprintf(file, "* [%d] Started\n", line);
            break;
        case 2:
            printf("* \033[32m[%d]\033[0m Completed\n", line);
            fprintf(file, "* [%d] Completed\n", line);
            break;
        case 3:
            printf("* \033[32m[%d]\033[0m Wrote in memory\n", line);
            fprintf(file, "* [%d] Wrote in memory\n", line);
            break;
        default:
            printf("* \033[32m[%d]\033[0m Unknown\n", line);
            fprintf(file, "* [%d] Unknown\n", line);
            break;
        }
    }
    fclose(file);
}

void logDependencyRegister(int dependency, int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        fprintf(file, "* [%d] Cannot start, it's waiting for Register %d\n", line, dependency);
        printf("* \033[32m[%d]\033[31m Cannot start\033[0m - Waiting for register %d\n", line, dependency);
    }
    fclose(file);
}

void logDependecy(int line)
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        printf("* \033[32m[%d]\033[31m Cannot be dispatched\033[0m - Waiting for a station to be free\n", line);
        fprintf(file, "* [%d] Cannot be dispatched, waiting for a station to be free\n", line);
    }
    fclose(file);
}

void logRegisters(Register registers[REG_AMOUNT], Station stations[STATIONS_AMOUNT])
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        fprintf(file, "\n## Registers\n```json\n[\n");
        printf("\n");
        for (int i = 0; i < REG_AMOUNT; i++)
        {
            if (i % 4 != 3)
            {
                printf("\x1b[33m[R%02d]: %s \x1b[0m    ", i, registers[i].busyBy == -1 ? "\x1b[32mfree" : "\x1b[31mbusy");
            }
            else
            {
                printf("\x1b[33m[R%02d]: %s \x1b[0m   \n", i, registers[i].busyBy == -1 ? "\x1b[32mfree" : "\x1b[31mbusy");
            }

            if (registers[i].busyBy != -1)
            {
                fprintf(file, "{\"id\": %d, \"busyByStation\": %d, \"busyByInst\": %d, \"v\": %d},\n", i, registers[i].busyBy, stations[registers[i].busyBy].debugInstructionLine, registers[i].value);
            }
        }
        fprintf(file, "]\n```\n");
    }
    fclose(file);
}

void logStations(Station stations[STATIONS_AMOUNT])
{
    FILE *file = fopen(LOG_PATH, "a");
    if (file == NULL)
    {
        printf("[LogError] Invalid log path! - fn newCicle()");
    }
    else
    {
        fprintf(file, "\n## Stations\n```json\n[\n");
        for (int i = 0; i < STATIONS_AMOUNT; i++)
        {
            if (stations[i].busy == 0)
                continue;
            switch (stations[i].type)
            {
            case ADD:
            case SUB:
                fprintf(file, "    {\"type\": \"ADDER (%d)\", \"Instruction\": {\n", i);
                break;
            case LW:
                fprintf(file, "    {\"type\": \"LOAD (%d)\", \"Instruction\": {\n", i);
                break;
            case SW:
                fprintf(file, "    {\"type\": \"STORE (%d)\", \"Instruction\": {\n", i);
                break;
            case MUL:
            case DIV:
                fprintf(file, "    {\"type\": \"MULTIPLIER (%d)\", \"Instruction\": {\n", i);
                break;
            default:
                fprintf(file, "    {\"type\": \"MULTIPLIER (%d)\", \"Instruction\": {\n", i);
                break;
            }

            switch (stations[i].instruction.operation)
            {
            case LW:
                fprintf(file, "        \"operation\": \"LW\",\n");
                break;
            case SW:
                fprintf(file, "        \"operation\": \"SW\",\n");
                break;
            case ADD:
                fprintf(file, "        \"operation\": \"ADD\",\n");
                break;
            case SUB:
                fprintf(file, "        \"operation\": \"SUB\",\n");
                break;
            case MUL:
                fprintf(file, "        \"operation\": \"MUL\",\n");
                break;
            case DIV:
                fprintf(file, "        \"operation\": \"DIV\",\n");
                break;
            default:
                fprintf(file, "        \"operation\": \"unknown\",\n");
                break;
            }

            fprintf(file, "        \"issuedAt\": %d,\n", stations[i].instruction.issuedAt);
            fprintf(file, "        \"startedAt\": %d,\n", stations[i].instruction.startedAt);
            fprintf(file, "        \"finishedAt\": %d,\n", stations[i].instruction.finishedAt);
            fprintf(file, "        \"writtenAt\": %d\n", stations[i].instruction.writtenAt);
            fprintf(file, "    }},\n");
        }
        fprintf(file, "]\n```\n");
        fprintf(file, "---\n\n");
    }
    fclose(file);
}
