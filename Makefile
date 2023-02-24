TARGET = PSPDemo
OBJS =	  $(patsubst %.o,source/%.o,main.o gfx_def.o mathlib.o file_util.o)

INCDIR = 
CFLAGS = -O2 -G0 -Wall -lm
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBS += -lm

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = PSP 3D Tech Demo

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
