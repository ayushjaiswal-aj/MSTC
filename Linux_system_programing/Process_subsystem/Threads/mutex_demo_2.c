#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void* new_thread(void*);
int global = 0;

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

void* new_thread(void* args){
	while(1){
		printf("thread id = %ld, global = %d\n", (long int)pthread_self(), global);
		global ++;
		sleep(1);
	}
	return NULL;
}
