all: isall.o main.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o
	make stack_as_linked_list
	make isall

debug:
	make stack_as_linked_list_debug
	make isall_debug

# links stack_as_linked_list, linked_list, error and main together
#		when either main.o or stack_as_linked_list.o are changed
stack_as_linked_list: main.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o
	gcc main.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o -o stack_as_linked_list

stack_as_linked_list_debug: main.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o
	gcc -g ../linked_list/linked_list.c stack_as_linked_list.c ../error.c main.c -o stack_as_linked_list_debug 

isall: isall.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o
	gcc isall.o stack_as_linked_list.o ../error.o ../linked_list/linked_list.o -o isall

# mainly used to debug the programs
isall_debug:
	gcc -g ../linked_list/linked_list.c stack_as_linked_list.c ../error.c isall.c -o isall_debug 

# compiles main.c file when main.c has changed
main.o: main.c
	gcc -Wall -c main.c

# compiles stack_as_linked_list.c when either
#		stack_as_linked_list.h or stack_as_linked_list.c change
stack_as_linked_list.o: stack_as_linked_list.c stack_as_linked_list.h
	gcc -Wall -c stack_as_linked_list.c

# compiles stack_as_linked_list.c when either
#		stack_as_linked_list.h or stack_as_linked_list.c change
error.o: ../error.c ../error.h
	gcc -Wall -c ../error.c

# compiles linked_list.c when either
#		linked_list.h or linked_list.c change
linked_list.o: ../linked_list/linked_list.c ../linked_list/linked_list.h
	gcc -Wall -c ../linked_list/linked_list.c

isall.o: isall.c
	gcc -Wall -c isall.c

# remove output files and executable
clean:
	rm -f *.o
	rm -f stack_as_linked_list stack_as_linked_list_debug stack_as_linked_list_debug isall isall_debug