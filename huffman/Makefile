OBJS= cellthreads.o 
CC=gcc
LDFLAGS= 
CFLAGS=
TARGET= cellthreads


$(TARGET): $(TARGET).c coordlinklist.c celllinklist.c 
	$(CC) -pthread -o  $(TARGET) $(TARGET).c coordlinklist.c celllinklist.c -g -lncurses

clean:
	rm -rf cellthreads
