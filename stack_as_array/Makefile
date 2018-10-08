# links stack and main together
#		when either main.o or stack.o are changed
stack: main.o stack.o ../error.o
	gcc main.o stack.o ../error.o -o stack

# compiles main.c file when main.c has changed
main.o: main.c
	gcc -Wall -c main.c

# compiles stack.c when either
#		stack.h or stack.c change
stack.o: stack.c stack.h
	gcc -Wall -c stack.c

# compiles stack.c when either
#		stack.h or stack.c change
error.o: ../error.c ../error.h
	gcc -Wall -c ../error.c

# remove output files and executable
clean:
	rm ./*.o
	rm ./stack