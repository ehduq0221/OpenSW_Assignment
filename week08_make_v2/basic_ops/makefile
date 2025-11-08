.PHONY: all clean

PROJ_DIR=$(abspath ..)

ADVAN_DIR=$(PROJ_DIR)/advanced_ops
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin
INC_DIR=$(PROJ_DIR)/include

BASIC_DIR=$(PROJ_DIR)/basic_ops
BASIC_SRC_DIR=$(BASIC_DIR)/src
BASIC_OBJ_DIR=$(BASIC_DIR)/obj

CC=gcc
AR=ar
CFLAGS=-I$(INC_DIR)

SRCS=$(wildcard $(BASIC_SRC_DIR)/*.c)
OBJS=$(subst $(BASIC_SRC_DIR), $(BASIC_OBJ_DIR), $(SRCS:.c=.o))

all: $(LIB_DIR)/libmybasic.a

$(BASIC_OBJ_DIR)/%.o: $(BASIC_SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB_DIR)/libmybasic.a: $(OBJS)
	$(AR) rc $@ $^

clean:
	rm -rf $(OBJS)
	rm -rf $(LIB_DIR)/libmybasic.a


