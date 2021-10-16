#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <errno.h>

void* thread_entry(void*);

int main(void){
	pthread_t th1;
	pthread_create(&th1, NULL, thread_entry, NULL);
	pthread_join(th1, NULL);

	return (EXIT_SUCCESS);
}

void* thread_entry(void *args){
	while(1){
		printf("thread id = %lx\n", (unsigned long int)pthread_self());
		sleep(2);
	}
}
