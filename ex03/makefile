CC=gcc
CFLAGS=-Wall -std=c11 -g
SRCS=main-test.c unit-tests.c DumpHex.c
HEADERS=DumpHex.h
TARGET=ex03

${TARGET}: ${SRCS} ${HEADERS}
	${CC} ${CFLAGS} ${SRCS} -o ${TARGET}

clean:
	rm -f ${TARGET} *.o *~ 
