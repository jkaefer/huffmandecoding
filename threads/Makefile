OBJS= cellthreads.o coordlist.o
CC=gcc
LDFLAGS= 
CFLAGS=
TARGET= cellbattle


$(TARGET): $(TARGET).c coordlinklist.c celllinklist2.c 
	$(CC) -pthread -o  $(TARGET) $(TARGET).c coordlinklist.c celllinklist2.c -g -lncurses

clean:
	rm -rf cellbattle
