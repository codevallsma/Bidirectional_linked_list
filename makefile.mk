C = gcc
CC_FLAGS = -g -Wall -std=c11
all: link main.o bidlist.o 

main.o: main.c
	$(CC) $(CC_FLAGS) -c main.c
bidlist.o: BidList.c BidList.h
	$(CC) $(CC_FLAGS) -c BidList.c 
link: main.o bidlist.o
	$(CC) $(CC_FLAGS) -o makegen main.o bidlist.o 
clean:
	rm -f *.o makegen
