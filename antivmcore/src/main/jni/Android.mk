LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=permission.cpp


LOCAL_LDLIBS    := -llog

LOCAL_MODULE:= antivm

include $(BUILD_SHARED_LIBRARY)
