# === task type ===
.PHONY: all basic_ops advanced_ops clean

PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

STATIC_LIBS=$(LIB_DIR)/libmybasic.a $(LIB_DIR)/libmyadvanced.a

CC=gcc
AR=ar
CFLAGS=-I$(INC_DIR) -lm
LDFLAGS=-L$(LIB_DIR) -lmybasic -lmyadvanced

all: basic_ops advanced_ops $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(SRC_DIR)/myapp.c $(STATIC_LIBS)
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops


clean:
	rm -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	$(MAKE) -C basic_ops clean
	$(MAKE) -C advanced_ops clean