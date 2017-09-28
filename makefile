CC = gcc
CFLAGS  = -Wall

default: djhdarts

djhdarts:  djhdarts.o djhdartsfunc.o
	$(CC) $(CFLAGS) -o DJHdarts djhdarts.o djhdartsfunc.o

djhdarts.o:  djhdarts.c  djhdartsfunc.h 
	$(CC) $(CFLAGS) -c djhdarts.c

djhdartsfunc.o:  djhdartsfunc.c  djhdartsfunc.h 
	$(CC) $(CFLAGS) -c djhdartsfunc.c




clean: 
	$(RM) ty *.o *~ DJHdarts

	
