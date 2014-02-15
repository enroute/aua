#include "auatypes.h"
#include <sys/time.h>

u32 get_time_millis()
{
    struct timeval  tv;
    gettimeofday( &tv,  NULL);

    return (u32)(tv.tv_sec) * 1000 + (u32)(tv.tv_usec) / 1000;
}

