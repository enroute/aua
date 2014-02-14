#ifndef _LUAWRAP_H_
#define _LUAWRAP_H_

#define LUAW_TEST

#define LUAW_INFO_TAG "LUA"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LUAW_INFO_TAG, __VA_ARGS__)

#define LUAW_SUCCESS 1
#define LUAW_FAIL    0

enum
{
    EN_LUAW_ERROR_OK,
    EN_LUAW_ERROR_NONE,
    EN_LUAW_ERROR_UNKNOWN_ERROR
};

int  luaw_init( );
void luaw_free( );
void luaw_test( );
void luaw_set_error( int error );
int  luaw_get_error( );
void luaw_dostring( );

#endif /* _LUAWRAP_H_ */
