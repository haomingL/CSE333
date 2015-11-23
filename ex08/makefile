CXX=g++
CXXFLAGS=-Wall -std=gnu++0x -g
NO_OPT=-fno-elide-constructors
SRCS=main.cc CasedString.cc
HEADERS=CasedString.h
TARGET=ex10

${TARGET}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${NO_OPT} ${SRCS} -o $@

clean:
	rm -f *.o *~ ${TARGET}

