CC = gcc
CFLAGS = -Wall -g -std=c11 -O2
SRCS= CharSource.c  FileReader.c WordCounter.c
HEADERS=CharSource.h FileReader.h WordCounter.h

all: wc wc-list

wc: main-wordCount.c ${HEADERS}
	$(CC) $(CFLAGS) -o wc main-wordCount.c ${SRCS}

wc-list: main-wclist.c ${SRCS} FileListReader.c  ${HEADERS} FileListReader.h
	$(CC) $(CFLAGS) -o wc-list main-wclist.c ${SRCS} FileListReader.c

clean:
	/bin/rm -f *.o  *~ wc wc-list
