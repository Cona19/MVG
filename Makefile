CC = g++

CPPFLAGS = -g -Wall -O0 -Wunused-result 

OBJS = ./src/main.o ./src/batch_add.o
SRCS = ./src/$(OBJS:.o=.cpp)
BIN = ./bin/
INCLUDE = ./src
LIBNAME = -lpthread

CPPFLAGS += -I$(INCLUDE)

all: spp

spp: $(OBJS)
	$(CC) -o $(BIN)spp $(OBJS) $(CPPFLAGS) $(LIBNAME)

clean:
	rm -rf $(OBJS)

allclean:
	rm -rf $(OBJS) $(BIN)*
