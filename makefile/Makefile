

SRC = $(wildcard *.c) 
TARGET = $(basename ${SRC})


CCFLAGS = -DTEST

all: ${TARGET}

${TARGET}: ${SRC}
	gcc $^ ${CCFLAGS} -o $@
	

clean:
	rm -rf ${TARGET}


.PHONY: all

