CC = gcc
LD = gcc
OPTIONS = -g -Wall

SRCS = ./romanNumLib_test.c ../src/romanNumLib.c
INCLUDES = -I . -I ../src
LIBS =
ifeq ($(shell lsb_release -rs), 16.04)
TEST_LIBS = -lcheck -lsubunit -lm -lrt -lpthread
else
TEST_LIBS = -lcheck -lm -lrt -lpthread
endif

EXE =
EXE_OBJS =
TEST_EXE = romanNumlib_test
TEST_EXE_OBJS = romanNumLib_test.o romanNumLib.o

.PHONY: all test deps clean clobber

all: test

test: ${TEST_EXE}

${TEST_EXE}: ${TEST_EXE_OBJS}
	${LD} ${OPTIONS} ${INCLUDES} ${TEST_EXE_OBJS} ${TEST_LIBS} -o ${TEST_EXE}

${TEST_EXE_OBJS}: ${SRCS}
	${CC} ${OPTIONS} -c ${SRCS} ${INCLUDES}

deps:
	$(CC) -MM ${INCLUDES} ${SRCS} > Makefile.d

clean:
	rm -f ${TEST_EXE_OBJS}

clobber:
	rm -f ${TEST_EXE_OBJS}
	rm -f ${TEST_EXE}

include Makefile.d

