CC = gcc
CLINK = $(CC)
CFLAGS = -Wall -g -std=c99
OBJS  = grades.o 


libgrades.so: $(OBJS)
	$(CLINK) -shared $(OBJS) -o libgrades.so -llinked-list -L.
	
grades.o: grades.c grades.h linked-list.h
	$(CC) $(CFLAGS) -c -fpic grades.c


clean:
	rm -fr *.o libgrades.so
