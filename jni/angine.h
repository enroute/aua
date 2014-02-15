#ifndef _ANGINE_H_
#define _ANGINE_H_

#include "auatypes.h"

#define ANGINE_STATE_STOP    0
#define ANGINE_STATE_RUNNING 1

void angine_init(void);
void angine_start(void);
void angine_restart(void);
void angine_stop(void);
BOOL angine_is_running(void);
BOOL angine_update(void);
void angine_render(void);


#endif /* _ANGINE_H_ */
