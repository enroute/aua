#include "auatypes.h"
#include "utils.h"

static u32 m_dwLastUpdateMillis = 0;
static u32 m_dwFrameMillis = 20;
static u8  m_bState = ANGINE_STATE_STOP;

void angine_init()
{

}

void angine_start()
{
    m_dwLastUpdateMillis = get_time_millis();
}

void angine_restart()
{
    angine_start();
}

void angine_stop()
{

}

BOOL angine_is_running()
{
    return ANGINE_STATE_RUNNING == m_bState;
}

BOOL angine_update()
{
    if(m_dwFrameMillis <= get_time_millis() - m_dwLastUpdateMillis)
    {
        return FALSE;
    }

    
}

/* update one frame */
void angine_do_update()
{

}

void angine_render()
{

}
