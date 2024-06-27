mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))
INCLUDE_DIRS = -I/usr/local/include/opencv4

APPL_COBJS +=\
LineTracer.o\

APPL_LIBS += -lm
APPL_LIBS += `pkg-config --libs opencv4`

APPL_DIRS += $(mkfile_path)LineTracer

INCLUDES += \
	-I$(mkfile_path)LineTracer\
