# links stack and main together
#		when either main.o or stack.o are changed
stack_as_array: main.o stack_as_array.o ../error.o
	gcc main.o stack_as_array.o ../error.o -o stack_as_array

# compiles main.c file when main.c has changed
main.o: main.c
	gcc -Wall -c main.c

# compiles stack.c when either
#		stack.h or stack.c change
stack_as_array.o: stack_as_array.c stack_as_array.h
	gcc -Wall -c stack_as_array.c

# compiles stack.c when either
#		stack.h or stack.c change
error.o: ../error.c ../error.h
	gcc -Wall -c ../error.c

# remove output files and executable
clean:
	rm ./*.o
	rm ./stack_as_array