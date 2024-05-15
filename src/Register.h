#include <stdlib.h>
/**
 * @brief
 *  @param value->Register number
 *  @param busyBy->Shows which reservation station is using this register. If -1, then it's free.
 */
typedef struct
{
    short busyBy;
    short value;
} Register;

bool isRegisterFree(Register reg, short stationIndex)
{
    return (reg.busyBy == -1 || reg.busyBy == stationIndex);
}
