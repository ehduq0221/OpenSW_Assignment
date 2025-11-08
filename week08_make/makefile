# === prototype ===

#.PHONY: all basic clean

#all: ./lib/libmybasic.a ./bin/myapp

#basic: ./lib/libmybasic.a

#./obj/add.o: ./src/add.c
#	gcc -c ./src/add.c -o ./obj/add.o -I./include

#./obj/sub.o: ./src/sub.c
#	gcc -c ./src/sub.c -o ./obj/sub.o -I./include

#./obj/mul.o: ./src/mul.c
#	gcc -c ./src/mul.c -o ./obj/mul.o -I./include

#./obj/div.o: ./src/div.c
#	gcc -c ./src/div.c -o ./obj/div.o -I./include

#./obj/myapp.o: ./src/myapp.c
#	gcc -c ./src/myapp.c -o ./obj/myapp.o -I./include

#./lib/libmybasic.a: ./obj/add.o ./obj/sub.o ./obj/mul.o ./obj/div.o
#	ar rv ./lib/libmybasic.a ./obj/add.o ./obj/sub.o ./obj/mul.o ./obj/div.o

#./bin/myapp: ./obj/myapp.o ./lib/libmybasic.a
#	gcc -o ./bin/myapp ./obj/myapp.o -L./lib -lmybasic

#clean:
#	rm -rf ./obj/*.o ./bin/myapp


# === task type ===

PROJ_DIR=$(shell pwd)
SRC_DIR=$(PROJ_DIR)/src
OBJ_DIR=$(PROJ_DIR)/obj
INC_DIR=$(PROJ_DIR)/include
LIB_DIR=$(PROJ_DIR)/lib
BIN_DIR=$(PROJ_DIR)/bin

.PHONY: all basic clean

CC=gcc
AR=ar

SRCS = $(SRC_DIR)/add.c $(SRC_DIR)/sub.c $(SRC_DIR)/mul.c $(SRC_DIR)/div.c
OBJS = $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS:.c=.o))

all: $(LIB_DIR)/libmybasic.a $(BIN_DIR)/myapp

basic: $(LIB_DIR)/libmybasic.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ -I$(INC_DIR)

$(LIB_DIR)/libmybasic.a: $(OBJS)
	$(AR) rc $@ $^

$(BIN_DIR)/myapp: $(OBJ_DIR)/myapp.o $(LIB_DIR)/libmybasic.a
	$(CC) -o $@ $< -L$(LIB_DIR) -lmybasic

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp