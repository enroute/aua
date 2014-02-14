#include "luawrap.h"
#include "lua.h"
#include "lauxlib.h"

#include <stdlib.h>
#include <android/log.h>

static lua_State *L = NULL;
static int ERROR = EN_LUAW_ERROR_OK;

int luaw_init( )
{
    if( NULL == L )
    {
        L = luaL_newstate( );
    }

    if( NULL != L )
    {
#ifdef JUA_TEST
        luaw_test( );
#endif
        return LUAW_SUCCESS;
    }
    else
    {
        return LUAW_FAIL;
    }
}

void luaw_free( )
{
    if( NULL != L )
    {
        lua_close( L );
        L = NULL;
    }
}

int luaw_get_error( )
{
    return ERROR;
}

void luaw_set_error( int error )
{
    ERROR = error;
}

void luaw_test( )
{
    LOGI( "Start luaw_test( )" );
    luaw_set_error( EN_LUAW_ERROR_NONE );

    luaL_openlibs( L );
    lua_pushstring( L, "String pushed to lua from android c" );
    lua_setglobal( L, "TEST" );
    lua_getglobal( L, "TEST" );

    const char *res = lua_tostring( L, lua_gettop( L ) );
    LOGI( "Lua TEST is:[%s]", res );
    lua_pop( L, 1 );

    luaw_set_error( EN_LUAW_ERROR_OK );
}

void luaw_dostring( char *script )
{
    luaw_set_error( EN_LUAW_ERROR_NONE );

    luaL_dostring( L, script );

    luaw_set_error( EN_LUAW_ERROR_OK );
} 
