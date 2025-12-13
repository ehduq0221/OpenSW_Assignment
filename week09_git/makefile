.PHONY: all clean

PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

CC=gcc
LD=ld
LN=ln
CFLAGS=-I$(INC_DIR)
LDFLAGS=-L$(LIB_DIR) -lmyops

APP_SRC=$(SRC_DIR)/myapp.c
SRCS=$(filter-out $(APP_SRC), $(wildcard $(SRC_DIR)/*.c))
OBJS=$(subst $(SRC_DIR),$(OBJ_DIR),$(SRCS:.c=.o))

all: $(LIB_DIR)/libmyops.so.1.0 $(LIB_DIR)/libmyops.so.1 $(LIB_DIR)/libmyops.so $(BIN_DIR)/myapp

$(BIN_DIR)/myapp: $(APP_SRC) $(LIB_DIR)/libmyops.so
	$(CC) $< -o $@ $(LDFLAGS) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB_DIR)/libmyops.so.1.0: $(OBJS)
	$(LD) -shared -soname=libmyops.so.1 -o $@ $^ -lc

$(LIB_DIR)/libmyops.so.1: $(LIB_DIR)/libmyops.so.1.0
	$(LN) -s $< $@

$(LIB_DIR)/libmyops.so: $(LIB_DIR)/libmyops.so.1
	$(LN) -s $< $@

clean:
	rm -rf $(OBJS)
	rm -rf $(LIB_DIR)/libmyops.so*
	rm -rf $(BIN_DIR)/*