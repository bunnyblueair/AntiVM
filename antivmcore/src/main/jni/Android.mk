LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:=antivm.cpp \
        mapinfo.cpp \
        io_github_vmBoy_Who.cpp


LOCAL_LDLIBS    := -llog

LOCAL_MODULE:= antivm
LOCAL_CFLAGS := -DVMDEBUG
LOCAL_CFLAGS += -O2 -O3 -DUSE_MMAP -fvisibility=hidden
LOCAL_CPPFLAGS += -ffunction-sections -fdata-sections -fvisibility=hidden

LOCAL_CFLAGS += -ffunction-sections -fdata-sections
LOCAL_LDFLAGS += -Wl,--gc-sections
include $(BUILD_SHARED_LIBRARY)
