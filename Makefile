CC = g++
CFLAGS = -Wall -Werror

workers:  
	${CC} ${CFLAGS} -O0 -o targets/cpu-bound src/sample_apps/cpu-bound.cc
