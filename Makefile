CC = g++
CFLAGS = -Wall -Werror -c
WORKER_FLAGS = -O0

workers:  
	${CC} ${CFLAGS} ${WORKER_FLAGS} -o targets/cpu-bound.o src/sample_apps/cpu-bound.cc

all: workers
	${CC} ${CFLAGS} -o targets/spacewhale src/main.cc targets/cpu-bound.o
