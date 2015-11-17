CC=gcc
CFLAGS=-Wall -std=c11 -g
SRCS=main-test.c unit-tests.c Stack.c
HEADERS=Stack.h
TARGET=ex04

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} ${SRCS} -o ${TARGET}

clean:
	rm -f ${TARGET} *.o *~ 
