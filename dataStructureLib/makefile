.PHONY : all clean rebuild test

TOP_PATH := $(realpath ..)
THE_PATH := $(notdir  $(realpath .))


SRC_DIR := src
INC_DIR := $(addprefix ../, $(Moudles))
INC_DIR := $(addsuffix /inc,$(INC_DIR))

TYPE_INC := h
TYPE_SRC := cpp
TYPE_OBJ := o
TYPE_DEP := dep

AR := ar
FLAGS_AR := -crs
CC := g++
MKDIR := mkdir

BUILD_DIR := $(TOP_PATH)/build
TARGET_DIR := $(BUILD_DIR)/$(THE_PATH)

DIRS := $(BUILD_DIR) $(TARGET_DIR)

SRCS := $(wildcard $(SRC_DIR)/*.$(TYPE_SRC))
OBJS := $(SRCS:.$(TYPE_SRC)=.$(TYPE_OBJ))
OBJS := $(patsubst $(SRC_DIR)/%,$(TARGET_DIR)/%,$(OBJS))

DEPS := $(OBJS:.$(TYPE_OBJ)=.$(TYPE_DEP))

OUTPUT := $(BUILD_DIR)/$(THE_PATH).a

vpath %.$(TYPE_INC) $(INC_DIR)
vpath %.$(TYPE_SRC) $(SRC_DIR)


FLAGS_CC := -I $(INC_DIR) 
ifeq ($(DEBUG),true)
FLAGS_CC := $(FLAGS_CC) -g 
endif

#include $(DEPS)


all : $(OUTPUT)
	@echo "OUTPUT ==> $(OUTPUT)"

$(DIRS): % :
	$(MKDIR) $@

$(OUTPUT) : $(OBJS)
	$(AR) $(FLAGS_AR) -o $@ $^
$(OBJS) : 
	$(CC) $(FLAGS_CC) -o $@ -c  $(SRC_DIR)/$(notdir $(@:.$(TYPE_OBJ)=.$(TYPE_SRC)))

test : 
	@echo "TOP_PATH ==> $(TOP_PATH)"


$(TARGET_DIR)/%.$(TYPE_DEP) : $(SRC_DIR)/%.$(TYPE_SRC)
	@$(CC) -MM -E $(filter %.$(TYPE_SRC),$^) | sed 's,\(.*\)\.o[:]*,$(TARGET_DIR)/\1.o  $@ \: ,g' > $@

