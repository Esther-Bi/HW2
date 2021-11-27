CC = gcc
AR = ar
ACTIONS = my_mat.o
FLAGS = -g -Wall
LM = -lm
HEADER = my_mat.h
MAIN = main.o


all: my_mat.a connections

#creat libraries
my_mat.a: $(ACTIONS)
	$(AR) -rcs my_mat.a $(ACTIONS)

actions.o: my_mat.c $(HEADER)
	$(CC) $(FLAGS) -c my_mat.c

#creat main
connections: $(MAIN) my_mat.a
	$(CC) $(FLAGS) -o connections $(MAIN) my_mat.a $(LM)


main.o: main.c $(HEADER)
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a connections