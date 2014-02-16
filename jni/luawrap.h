#ifndef _LUAWRAP_H_
#define _LUAWRAP_H_

#define LUAW_TEST

#include <android/log.h>
#define LUAW_INFO_TAG "LUA"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LUAW_INFO_TAG, __VA_ARGS__)

#include <stdio.h>              /* for size_t and FILE */
#include "lua.h"
#include "lauxlib.h"

#define LUAW_SUCCESS 1
#define LUAW_FAIL    0

#define LUAW_OUTPUT_BUFFER_SIZE 512

enum
{
    EN_LUAW_ERROR_OK,
    EN_LUAW_ERROR_NONE,
    EN_LUAW_ERROR_UNKNOWN_ERROR
};

int  luaw_init( );
void luaw_free( );
void luaw_set_error( int error );
int  luaw_get_error( );
void luaw_dostring( );

/* redirect "print" */
size_t luaw_fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream );
int    luaw_fflush( FILE *stream );

/* test function */
void luaw_test( );
int  luaw_test_exportadd( lua_State *L );

#endif /* _LUAWRAP_H_ */
