/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jws_aua_Angine */

#ifndef _Included_com_jws_aua_Angine
#define _Included_com_jws_aua_Angine
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jws_aua_Angine
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_init
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    start
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_start
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    restart
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_restart
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    stop
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_stop
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    isRunning
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_jws_aua_Angine_isRunning
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    update
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_jws_aua_Angine_update
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    render
 * Signature: (Landroid/graphics/Canvas;)V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_render
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_jws_aua_Angine
 * Method:    surfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_surfaceCreated
  (JNIEnv *, jclass);

/*
 * Class:     com_jws_aua_Angine
 * Method:    surfaceChanged
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_surfaceChanged
  (JNIEnv *, jclass, jint, jint, jint);

/*
 * Class:     com_jws_aua_Angine
 * Method:    surfaceDestroyed
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jws_aua_Angine_surfaceDestroyed
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
