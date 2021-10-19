#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>

void* new_thread(void*);

int main(void){
	pthread_t th1, th2, th3, th4, th5;
	
	pthread_create(&th1, NULL, new_thread, NULL);
	pthread_create(&th2, NULL, new_thread, NULL);
	pthread_create(&th3, NULL, new_thread, NULL);
	pthread_create(&th4, NULL, new_thread, NULL);
	pthread_create(&th5, NULL, new_thread, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_join(th3, NULL);
	pthread_join(th4, NULL);
	pthread_join(th5, NULL);

	exit(EXIT_SUCCESS);
}

void* new_thread(void *args){
	int local = 0;
	while(1){
		printf("thread id = %ld local = %d\n", (long int)pthread_self(), local);
		local ++;
		sleep(rand() % 3);
	}
	return NULL;
}
