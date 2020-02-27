#include <stdio.h>
#include <pthread.h>

// Compile with -pthread
// Create a mutex this ready to be locked!
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;

void *countgold(void *param) {
    int i;
    
    // Same thread that locks the mutex must unlock it
    // Critical section is just 'sum += 1'
    // However locking and unlocking a million times
    // has significant overhead in this simple answer
    
    pthread_mutex_lock(&m);

    // Other threads that call lock will have to wait until we call unlock

    for (i = 0; i < 10000000; i++) {
	sum += 1;
    }
    pthread_mutex_unlock(&m);
    return NULL;
}

int main() {
    int count=0;

    pthread_t tid[9];
    for(int j=0;j<3;j++){
	    for(int i=0;i<3;i++){
	        pthread_create(&tid[count], NULL, countgold, NULL);
 		count++;
	    }
    }

    count=0;
    //Wait for both threads to finish:
    for(int j=0;j<3;j++){
	    for(int i=0;i<3;i++){
	    	pthread_join(tid[count], NULL);
                count++;
	    }
    }

    printf("ARG sum is %d\n", sum);
    return 0;
}
