#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 

int total=0;

struct arg_struct {
    int arg1;
    int arg2;
    int threadInd;
};
// Let us create a global variable to change it in threads 
int g = 0; 

// The function to be executed by all threads 
void *myThreadFun(void *arguments) 
{ 
        struct arg_struct *args = arguments;

	total++;

	// Print the argument, static and global variables 
	printf("Total: %d\n", total); 
} 

int main() 
{ 
	int i; 
	pthread_t tid; 

        struct arg_struct args;

	// Let us create three threads 
	for (i = 0; i < 500; i++) {
                //int rows=9;
                //int columns=9;
                //args.arg1=rows;
                //args.arg2=columns;
                //args.threadInd=i;
                
		pthread_create(&tid, NULL, myThreadFun, (void *)&args); 
        }

	pthread_exit(NULL); 
	return 0; 
} 

