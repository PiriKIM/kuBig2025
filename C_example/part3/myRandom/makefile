TARGET = random

all : ${TARGET}

random : main.o random.o
	cc -o random main.o random.o

main.o : main.c random.h
	cc -c main.c

random.o : random.c random.h
	cc -c random.c

clean :
	rm ${TARGET} main.o random.o
