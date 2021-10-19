#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <pthread.h>

void *new_thread(int*);

int main(){
	pthread_t th1, th2;
	void *ret1, *ret2;
	int a[] = {0, 1};
	while(1){
		a[0] ++;
		a[1] ++;
		pthread_create(&th1, NULL, new_thread, (void*)&a);
		pthread_create(&th2, NULL, new_thread, (void*)&a);
		pthread_join(th2, NULL);
		pthread_join(th1, NULL);
	}
	return (EXIT_SUCCESS);
}

void* new_thread(int *args){
	printf("thread id = %ld\n", pthread_self());
	printf("args[0] + args[1] = %d\n", args[0] + args[1]);
	sleep(2);
	return NULL;
}
