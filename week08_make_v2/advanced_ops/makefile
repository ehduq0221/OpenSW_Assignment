.PHONY: all clean

PROJ_DIR=$(abspath ..)

BASIC_DIR=$(PROJ_DIR)/basic_ops
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin
INC_DIR=$(PROJ_DIR)/include

ADVAN_DIR=$(PROJ_DIR)/advanced_ops
ADVAN_SRC_DIR=$(ADVAN_DIR)/src
ADVAN_OBJ_DIR=$(ADVAN_DIR)/obj

CC=gcc
AR=ar
CFLAGS=-I$(INC_DIR)

SRCS=$(wildcard $(ADVAN_SRC_DIR)/*.c)
OBJS=$(subst $(ADVAN_SRC_DIR), $(ADVAN_OBJ_DIR), $(SRCS:.c=.o))

all: $(LIB_DIR)/libmyadvanced.a

$(ADVAN_OBJ_DIR)/%.o: $(ADVAN_SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB_DIR)/libmyadvanced.a: $(OBJS)
	$(AR) rc $@ $^

clean:
	rm -rf $(OBJS)
	rm -rf $(LIB_DIR)/libmyadvanced.a
