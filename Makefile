CC = gcc
CFLAGS = -Wall -g
LDFLAGS =
OBJFILES = qsort.o quicksort.o
TARGET = qsort

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o qsort $(OBJFILES)

qsort.o: qsort.c quicksort.h
	$(CC) $(CFLAGS) -c qsort.c
quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c quicksort.c

clean:
	rm -f $(OBJFILES) $(TARGET) *~ 
