default: main_deque main_bag

cirListDeque: cirListDeque.c cirListDeque.h type.h 
	gcc -Wall -ansi -c cirListDeque.c

list: listbag.h list.c listbag.c
	gcc -Wall -ansi listbag.h
	gcc -Wall -ansi -c list.c
	gcc -Wall -ansi -c listbag.c

main_deque: cirListDeque.o main_deque.c
	gcc -Wall -ansi -o main_deque cirListDeque.o main_deque.c

main_bag: main_bag.c list.o listbag.o
	gcc -Wall -ansi -o main_bag list.o listbag.o main_bag.c

clean:
	rm *.o
	rm main_bag main_deque

	

