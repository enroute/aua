LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LUA_SRC_PATH  := lua/src
LUA_SRC_FILES := \
	$(LUA_SRC_PATH)/lapi.c      \
	$(LUA_SRC_PATH)/lauxlib.c   \
	$(LUA_SRC_PATH)/lbaselib.c  \
	$(LUA_SRC_PATH)/lbitlib.c   \
	$(LUA_SRC_PATH)/lcode.c	    \
	$(LUA_SRC_PATH)/lcorolib.c  \
	$(LUA_SRC_PATH)/lctype.c    \
	$(LUA_SRC_PATH)/ldblib.c    \
	$(LUA_SRC_PATH)/ldebug.c    \
	$(LUA_SRC_PATH)/ldo.c	    \
	$(LUA_SRC_PATH)/ldump.c	    \
	$(LUA_SRC_PATH)/lfunc.c	    \
	$(LUA_SRC_PATH)/lgc.c	    \
	$(LUA_SRC_PATH)/linit.c	    \
	$(LUA_SRC_PATH)/liolib.c    \
	$(LUA_SRC_PATH)/llex.c	    \
	$(LUA_SRC_PATH)/lmathlib.c  \
	$(LUA_SRC_PATH)/lmem.c	    \
	$(LUA_SRC_PATH)/loadlib.c   \
	$(LUA_SRC_PATH)/lobject.c   \
	$(LUA_SRC_PATH)/lopcodes.c  \
	$(LUA_SRC_PATH)/loslib.c    \
	$(LUA_SRC_PATH)/lparser.c   \
	$(LUA_SRC_PATH)/lstate.c    \
	$(LUA_SRC_PATH)/lstring.c   \
	$(LUA_SRC_PATH)/lstrlib.c   \
	$(LUA_SRC_PATH)/ltable.c    \
	$(LUA_SRC_PATH)/ltablib.c   \
	$(LUA_SRC_PATH)/ltm.c	    \
	$(LUA_SRC_PATH)/lua.c	    \
	$(LUA_SRC_PATH)/lundump.c   \
	$(LUA_SRC_PATH)/lvm.c	    \
	$(LUA_SRC_PATH)/lzio.c

LOCAL_SRC_FILES := $(LUA_SRC_FILES)\
	com_jws_aua_Jua.c

LOCAL_LDLIBS := \
	-llog \
	-lm

LOCAL_C_INCLUDES += lua/src

LOCAL_MODULE := jua

include $(BUILD_SHARED_LIBRARY)


