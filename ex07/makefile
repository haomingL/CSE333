C++ = g++
CFLAGS =-Wall -std=c++11 -g -O0 -fno-elide-constructors
SRCS=main.cc Element.cc
HEADERS=Element.h
TARGET=sym


${TARGET}:  ${SRCS} ${HEADERS}
	$(C++) $(CFLAGS) -o ${TARGET} ${SRCS}

clean:
	/bin/rm -f *.o  *~ ${TARGET}
