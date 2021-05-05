#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 2

extern int register_callback(void* (*pfn)(void*));
extern void trigger_event(void* data);
extern void* get_result(void);

float* handler2(int* pi);

int main(void){
	int n = 500;
	float *pf = NULL;
	register_callback(handler2);
	trigger_event((void*)&n);
	pf = (float*)get_result();
	printf("*pf = %f\n", *pf);
	free(pf);
	pf = NULL;

	return (0);
}

float* handler2(int *pi){
	float *pf = (float*) malloc(sizeof(float));
	if(pf == NULL){
		return pf;
	}
	*pf = (*pi + 150)/10.0;
	return (pf);
}
