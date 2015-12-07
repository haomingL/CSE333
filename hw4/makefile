C++ = g++
CFLAGS =-Wall -std=c++11 -g -O0 -fno-elide-constructors
SRCS=main.cc State.cc SentenceMatcher.cc
HEADERS=SentenceMatcher.h State.h
TARGET=regexp


${TARGET}:  ${SRCS} ${HEADERS}
	$(C++) $(CFLAGS) -o ${TARGET} ${SRCS}

clean:
	/bin/rm -f *.o  *~ ${TARGET}
