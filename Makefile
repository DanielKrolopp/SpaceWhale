CC = g++
CFLAGS = -Wall -Werror
WORKER_FLAGS = -O0 -c
PIPELINE_FLAGS = -c

all: workers pipeline
	${CC} ${CFLAGS} -o targets/start src/start.cc targets/cpu-bound.o targets/sendmsg.o targets/receivemsg.o 
	${CC} ${CFLAGS} -o targets/middle src/middle.cc targets/cpu-bound.o targets/sendmsg.o targets/receivemsg.o
	${CC} ${CFLAGS} -o targets/end src/end.cc targets/cpu-bound.o targets/sendmsg.o targets/receivemsg.o 
	${CC} ${CFLAGS} -o targets/cpu-bound targets/cpu-bound.o targets/cpu-bound-driver.o

pipeline:
	${CC} ${CFLAGS} ${PIPELINE_FLAGS} -o targets/sendmsg.o src/pipeline/sendmsg.cc 
	${CC} ${CFLAGS} ${PIPELINE_FLAGS} -o targets/receivemsg.o src/pipeline/receivemsg.cc 

workers:  
	${CC} ${CFLAGS} ${WORKER_FLAGS} -o targets/cpu-bound.o src/sample_apps/cpu-bound.cc
	${CC} ${CFLAGS} ${WORKER_FLAGS} -o targets/cpu-bound-driver.o src/sample_apps/driver.cc

clean:
	@rm targets/* > /dev/null ||:
	@echo "Removed targets/*" ||:

