#include <stdlib.h>
/**
 * @brief 
 *  @param value->Register number
 *  @param busyBy->Shows which reservation station is using this register. If -1, then it's free.
 */
typedef struct {
    short value;
    short busyBy;    
} Register;
