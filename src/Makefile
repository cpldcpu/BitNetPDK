# ----------------------------------------------------------------
# Generic makefile for the Padauk open source toolchain
# 
# Usage:
#
# make					- build project
# make flash			- flash binary to microcontroller
# make start			- start program on microcontroller	
# make clean			- clean
# make compileandrun	- compile, flash and start
#
# Requires the SDCC compiler and the easypdkprog programmer
#
# ----------------------------------------------------------------
# History:
#
# Sep 1th, 2019/cpldcpu		First version
# Sep 6th, 2020/cpldcpu 	Adopted for new include structure
# ----------------------------------------------------------------

# Define your processor settings here

# DEVICE	= PMS150C
# ARCH	= pdk13
# SOURCES = main.c 

DEVICE	= PFS154
ARCH	= pdk14
SOURCES = main.c PDK_softuart.c

F_CPU	= 8000000
TARGET	= main.ihx
TARGET_VDD_MV = 5000

# Toolchain settings. Usually does not need to be changed

INCLUDE = ../include
SDCC	= sdcc
SDLD	= sdld
SDAS	= sdaspdk14
OBJCOPY	= sdobjcopy
PROGRAMMER	= easypdkprog
BUILD_DIR	= .build
OUTPUT_DIR  = .objects

# Compiler flags

ASFLAGS	= -lo
LDFLAGS	= -m$(ARCH) --out-fmt-ihx 
CFLAGS 	= -m$(ARCH) -D$(DEVICE) -DF_CPU=$(F_CPU) --std-sdcc11 --opt-code-size
CFLAGS += -DTARGET_VDD_MV=$(TARGET_VDD_MV)
CFLAGS += -I. -I$(INCLUDE) 

# SOURCES    := $(wildcard *.c) # $(LIBRARY)/*.c)
# ASRC   := $(wildcard *.s) # $(LIBRARY)/*.s)

#OBJS     = $(SRCS:.c=.rel)
#OBJS 	+= $(ASRCS:.s=.rel)

OBJECTS =  $(patsubst %.c,$(BUILD_DIR)/%.rel,$(SOURCES))
OBJECTS += $(patsubst %.s,$(BUILD_DIR)/%.rel,$(ASCR))

all: $(OUTPUT_DIR)/$(TARGET) size 

$(OUTPUT_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $(OUTPUT_DIR)/$(TARGET))
	$(SDCC) $(LDFLAGS) $(OBJECTS) -o $@

$(BUILD_DIR)/%.rel: %.s
	@mkdir -p $(dir $@)
	$(SDAS) $(ASFLAGS) $<

$(BUILD_DIR)/%.rel: %.c
	@mkdir -p $(dir $@)
	$(SDCC) $(CFLAGS) -c $< -o $@

flash: all
	$(PROGRAMMER) -n $(DEVICE) write $(OUTPUT_DIR)/$(TARGET) --allowsecfuse

start: 
	$(PROGRAMMER) -n $(DEVICE) start

compileandrun: all flash start

size:
	$(OBJCOPY) -I ihex -O binary $(OUTPUT_DIR)/$(TARGET) $(OUTPUT_DIR)/$(TARGET).bin
	@echo ===============
	@echo Size of binary:
	@stat -L -c %s $(OUTPUT_DIR)/$(TARGET).bin
	@echo  bytes 
	@echo ===============

clean:
	rm -r -f $(BUILD_DIR) $(OUTPUT_DIR)
	
.PHONY: all clean flash
