CXX=g++
CXXFLAGS=-Wall -std=c++11 -g
SRCS=main.cc Tokenizer.cc TokenCounter.cc
HEADERS=Tokenizer.h TokenCounter.h
TARGET=ex09

${TARGET}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${NO_OPT} ${SRCS} -o $@

clean:
	rm -f *.o *~ ${TARGET}

