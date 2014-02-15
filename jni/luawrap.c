#include "luawrap.h"
#include "lua.h"
#include "lauxlib.h"

#include <stdlib.h>
#include <android/log.h>

static lua_State *L = NULL;
static int ERROR = EN_LUAW_ERROR_OK;
static int (*FFLUSH_FUNC)( const char *ptr, int size ) = NULL;
static char LUAW_OUTPUT_BUFFER[LUAW_OUTPUT_BUFFER_SIZE] = {0};
static int  LUAW_OUTPUT_BUFFER_TAIL = 0;

int luaw_init( )
{
    if( NULL == L )
    {
        L = luaL_newstate( );
    }

    if( NULL != L )
    {
#ifdef LUAW_TEST
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

void luaw_dostring( char *script )
{
    luaw_set_error( EN_LUAW_ERROR_NONE );

    luaL_dostring( L, script );

    luaw_set_error( EN_LUAW_ERROR_OK );
} 

size_t luaw_fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream )
{
    size_t n = size * nmemb;
    int i;

    if( n + LUAW_OUTPUT_BUFFER_TAIL < LUAW_OUTPUT_BUFFER_SIZE )
    {
        memcpy( &(LUAW_OUTPUT_BUFFER[LUAW_OUTPUT_BUFFER_TAIL]), ptr, n );
        LUAW_OUTPUT_BUFFER_TAIL += nmemb;

        for ( i = 0; i < LUAW_OUTPUT_BUFFER_TAIL; i++ )
        {
            if( '\n' == LUAW_OUTPUT_BUFFER[i] )
            {
                luaw_fflush( stream );
                break;
            }
        }

        return nmemb;
    }
    else
    {
        return 0;
    }
}

int luaw_fflush( FILE *stream )
{
    if( 0 >= LUAW_OUTPUT_BUFFER_TAIL )
    {
        return 0;
    }

    if( NULL != FFLUSH_FUNC )
    {
        FFLUSH_FUNC( LUAW_OUTPUT_BUFFER, LUAW_OUTPUT_BUFFER_TAIL - 1 );
    }
    else
    {
        LOGI( "%s", LUAW_OUTPUT_BUFFER );
    }

    LUAW_OUTPUT_BUFFER_TAIL = 0;
    memset( LUAW_OUTPUT_BUFFER, 0, sizeof( LUAW_OUTPUT_BUFFER ) );
}

int luaw_registerfflush( void *ptr_fflush_func )
{
    FFLUSH_FUNC = ptr_fflush_func;
}

void luaw_test( )
{
    LOGI( "Start luaw_test( )" );
    luaw_set_error( EN_LUAW_ERROR_NONE );

    fputc( 'Z', stdout);
    fputc( 'Y', stdout);
    fputc( 'X', stdout);
    fputc( '\n', stdout);

    printf( "This is from printf( )\r\n" );

    luaL_openlibs ( L );
    lua_pushstring( L, "String pushed to lua from android c" );
    lua_setglobal ( L, "TEST" );
    lua_getglobal ( L, "TEST" );

    const char *res = lua_tostring( L, lua_gettop( L ) );
    LOGI( "Lua TEST is:[%s]", res );
    lua_pop( L, 1 );

    luaL_dostring( L, "print( \"(From LUA)This line has no [NEWLINE]\" )" );
    luaL_dostring( L, "print( \"(From LUA)This is from lua print() with [NEWLINE]\" )" );

    luaL_dostring( L, "\
for i = 1, 10 do\
    print( \"Maybe it's auto immune.\" )\
end\
" );

    luaw_set_error( EN_LUAW_ERROR_OK );
}

