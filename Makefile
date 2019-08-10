#
# For testing, libcheck testing framework is used
# Please install it before calling `make test` [https://libcheck.github.io/check/web/install.html]
#

CFLAGS = -Wall -c -g
ARFLAGS = rcs

OBJ_DIR = obj
LIB_DIR = lib


all: setup compile make_lib

setup:
	mkdir -p obj lib

compile:
	gcc $(CFLAGS) library.c -o $(OBJ_DIR)/library.o

make_lib:
	ar $(ARFLAGS) $(LIB_DIR)/libncs.a $(OBJ_DIR)/library.o

test: all
	gcc ./tests/check_ncs.c -o ./tests/check_ncs `pkg-config --cflags --libs check` -Llib -lncs
	./tests/check_ncs

clean_test:
	rm ./tests/check_ncs

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

clean_all: clean_test clean
