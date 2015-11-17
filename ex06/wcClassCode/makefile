C++ = g++
CFLAGS =-Wall -std=c++11 -g -O2
SRCS=main.cc FileReader.cc WordCounter.cc
HEADERS=FileReader.h WordCounter.h
TARGET=wc


${TARGET}:  ${SRCS} ${HEADERS}
	$(C++) $(CFLAGS) -o ${TARGET} ${SRCS}

clean:
	/bin/rm -f *.o  *~ ${TARGET}
