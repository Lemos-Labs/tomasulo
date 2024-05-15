#define STATIONS_AMOUNT 7    // Number of reservation stations - 2 adders, 1 multiplier, 2 load, 2 store
#define MAX_INSTRUCTIONS 100 // Maximum number of instructions

#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief All the 4 possible stationsType
 */
typedef enum
{
    Load,       // 0
    Store,      // 1
    Adder,      // 2
    Multiplier, // 3
} StationType;

/**
 * @brief The station were it's going to be stored all the information about it
 */
typedef struct
{
    bool ready;
    bool busy;
    StationType type;
    Instruction instruction;
} Station;

/**
 * @brief Finds in the stationArray a non busy station to do the work.
 * If it can find it, returns the `indexPosition`, otherwhise returns `-1`, meaning there's no left.
 */
int _findNonBusyStation(Station station[STATIONS_AMOUNT], StationType type)
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

/**
 * @brief retrieve the DispatchType target. E.g. The instruction `ADD` needs an `ADDER`
 */
StationType _getDispatchTarget(Instruction inst)
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
        printf("ERROR - _GetDispatchTarget, unreachable!");
        exit(0);
    }
}

/**
 * @brief Just prints the Reservation Station as a human readable string on the terminal.
 */
void debugReservationStation(Station station)
{
    printf("* Reservation Station: \n");
    printf("[Busy]: %d\n", station.busy);
    printf("[Ready]: %d\n", station.ready);
    printf("* Instruction in It:");
    debugInstruction(station.instruction);
}

/**
 * #### Dispatchs the instruction!
 *
 * @brief When a dispatch is made sucessfully, it'll return `true`(1), if not, returns a `false` (0).
 * Usually, a dispatch is not made sucessfully when there is none stations for it.
 *
 * If success, the station will be modified with `busy = 1` and then added on the `runtimeList`.
 * The instruction will be modified with `issueAt = currentClock`.
 *
 * @param reservationStation List of stations
 * @param instruction The instruction to be dispatched
 * @param clock The current clock
 * @param runtimeList Runtime list so that the station can be added on
 *
 */
bool dispatchInstruction(Station reservationStation[STATIONS_AMOUNT], Instruction instruction, int clock, Station runtimeList[MAX_INSTRUCTIONS])
{
    StationType stationType = _getDispatchTarget(instruction);
    int stationIndex = _findNonBusyStation(reservationStation, stationType);

    if (stationIndex == -1)
    {
        printf("TODO - Stations are full, but it's not implemented");
        exit(0);
        return 0;
    }

    reservationStation[stationIndex].busy = 1;
    reservationStation[stationIndex].instruction = instruction;
    reservationStation[stationIndex].instruction.issuedAt = clock;

    for (int i = 0; i < MAX_INSTRUCTIONS; i++)
    {
        if (runtimeList[i].busy == -1)
        {
            runtimeList[i] = reservationStation[stationIndex];
            return 1;
        }
    }
    return 1;
}
