# links queue and main together
#		when either error.o, main.o or queue.o are changed
queue: main.o queue.o ../error.o
	gcc main.o queue.o ../error.o -o queue

# compiles main.c file when main.c has changed
main.o: main.c
	gcc -Wall -c main.c

# compiles queue.c when either
#		queue.h or queue.c change
queue.o: queue.c queue.h
	gcc -Wall -c queue.c

error.o: ../error.c ../error.h
	gcc -Wall -c ../error.c -o ../error.o

# remove output files and executable
clean:
	rm ./*.o
	rm ./queue