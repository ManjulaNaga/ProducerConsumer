all:output

output:
	gcc -g -Wall main.c insertRemove.c functions.h producerConsumer.c timer.c -lpthread -o output.o

clean:
	rm output.o

