linked_list: linked_list.o main.o
	gcc linked_list.o main.o -o linked_list

linked_list.o: linked_list.c linked_list.h
	gcc -Wall -c linked_list.c

main.o: main.c linked_list.h
	gcc -Wall -c main.c

clean:
	rm ./*.o
	rm ./linked_list