#include "angine.h"
#include "utils.h"

static u32 m_dwLastUpdateMillis = 0;
static u32 m_dwFrameMillis      = 20;
static u8  m_bState             = ANGINE_STATE_STOP;

void angine_init()
{
    /* todo */
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
    m_bState = ANGINE_STATE_STOP;
}

BOOL angine_is_running()
{
    return ANGINE_STATE_RUNNING == m_bState;
}

/* update one frame */
void angine_do_update()
{
    /* todo */
}

BOOL angine_update()
{
    if(m_dwFrameMillis > get_time_millis() - m_dwLastUpdateMillis)
    {
        return FALSE;
    }

    while(m_dwFrameMillis <= get_time_millis() - m_dwLastUpdateMillis)
    {
        angine_do_update();
        m_dwLastUpdateMillis += m_dwFrameMillis;
    }

    return TRUE;    
}

void angine_render()
{
    /* todo */
}

void angine_press(int x, int y)
{
    /* todo */
}

void angine_long_press(int x, int y)
{
    /* todo */
}
