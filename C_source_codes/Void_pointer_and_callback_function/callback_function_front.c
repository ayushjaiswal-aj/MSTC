#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define FAILURE	0

int register_callback(int(*pfn)(int));

int handler_1(int);
int handler_2(int);

void trigger_event(int data);
int get_result();

int main(void){
	int ret;
	int i;
	int result;

	unsigned long j;
	ret = register_callback(handler_1);
	assert(ret == SUCCESS);
	for(i=0; i<3; i++){
		for(j=0; j<0xffffffff; j++){
		}
		puts("Triggering the event ...");
		trigger_event((i+1));
		result = get_result();
		printf("Result = %d\n", result);
	}

	ret = register_callback(handler_2);
	assert(ret == SUCCESS);
	for(i=0; i<3; i++){
		for(j=0; j<0xffffffff; j++){
		}
		puts("Triggering the event ...");
		trigger_event((i+1));
		result = get_result();
		printf("Result = %d\n", result);
	}
	return (0);
}

int handler_1(int n){
	puts("In handler 1");
	return n*n;
}

int handler_2(int n){
	puts("In handler 2");
	return n*n*n;
}
