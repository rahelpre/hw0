CC     = gcc
CLINK=$(CC)
CFLAGS = -Wall -g -std=c99
OBJS   = grades.o libgrades.so


prog.exe: $(OBJS)
	$(CLINK) grades.o -o -llinked-list -lgrades -L.

libgrades.so: grades.o liblinked-list.so
	$(CLINK) -shared grades.o -o libgrades.so
	
grades.o: grades.c grades.h linked-list.h
	$(CC) $(CFLAGS) -fpic -c grades.c


clean:
	rm -fr $(OBJS)
