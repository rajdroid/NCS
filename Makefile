CFLAGS = -Wall -c -g
ARFLAGS = rcs

OBJ_DIR = obj
LIB_DIR = lib


all: setup compile make_lib

setup:
	mkdir obj lib

compile:
	gcc $(CFLAGS) library.c -o $(OBJ_DIR)/library.o

make_lib:
	ar $(ARFLAGS) $(LIB_DIR)/libncs.a $(OBJ_DIR)/library.o

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)
