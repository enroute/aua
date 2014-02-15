#include "com_jws_aua_Angine.h"
#include "angine.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     com_jws_aua_Angine
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_init(JNIEnv *env, jclass thiz)
{
    angine_init();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_start(JNIEnv *env, jclass thiz)
{
    angine_start();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    restart
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_restart(JNIEnv *env, jclass thiz)
{
    angine_restart();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    stop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_stop(JNIEnv *env, jclass thiz)
{
    angine_stop();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    isRunning
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_jws_aua_Angine_isRunning(JNIEnv *env, jclass thiz)
{
    return (jboolean)angine_is_running();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    update
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_jws_aua_Angine_update(JNIEnv *env, jclass thiz)
{
    return (jboolean)angine_update();
}

/*
 * Class:     com_jws_aua_Angine
 * Method:    render
 * Signature: (Landroid/graphics/Canvas;)V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_render(JNIEnv *env, jclass thiz, jobject obj)
{
    angine_render();
}

#ifdef __cplusplus
}
#endif
