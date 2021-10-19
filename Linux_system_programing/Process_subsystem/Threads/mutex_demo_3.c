#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int global = 0;

void* new_thread(void*);

int main(){
	pthread_t th1, th2, th3, th4;

	pthread_create(&th1, NULL, new_thread, NULL);
	pthread_create(&th2, NULL, new_thread, NULL);
	pthread_create(&th3, NULL, new_thread, NULL);
	pthread_create(&th4, NULL, new_thread, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);
	pthread_join(th4, NULL);

	return (EXIT_SUCCESS);
}

void* new_thread(void *args){
	while(1){
		pthread_mutex_lock(&lock);
		printf("thread id = %ld, global = %d\n", (long int)pthread_self(), global);
		global++;
		pthread_mutex_unlock(&lock);
		sleep(1);
	}
	return NULL;
}
