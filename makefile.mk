CC=gcc
CFLAGS=-I.
DEPS = BidList.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

llista_prova: BidList.o main.o 
	$(CC) -o llista_prova  BidList.o main.o 
clean:
	rm -f *.o llista_prova
