LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := valord.rc
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)/init
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_MODULE := valor.db
LOCAL_MODULE_CLASS := ETC
LOCAL_MODULE_PATH := $(TARGET_OUT_ETC)
LOCAL_SRC_FILES := $(LOCAL_MODULE)
include $(BUILD_PREBUILT)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := \
	src/valord/process.c \
	src/valord/util.c \
	src/valord/checksum.c \
	src/valord/aassert.c \
	src/valord/valor.c \
	src/valord/db/db.c \
	src/valord/crc32/crc32.c \
	src/valord/crc32/crc_poly.c

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/src/valord

LOCAL_SEPOLICY_DIRS := $(LOCAL_PATH)/sepolicy

LOCAL_MODULE := valord
LOCAL_CFLAGS := -O1 -g -W -Wall # TODO: Pre-release: Change to -O2 -W -Wall
LOCAL_SHARED_LIBRARIES := liblog

LOCAL_REQUIRED_MODULES := \
	valor.db \
	valord.rc	

include $(BUILD_EXECUTABLE)

