#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

extern int register_callback(void*(*pfn)(void*));
extern void trigger_event(void* data);
extern void* get_result(void);

struct input{
	int ia[5];
	double da[5];
};

struct output{
	int i_sum;
	double d_sum;
};

struct output* handler_1(struct input* p_input);

int main(void){
	struct input I = {{10, 20, 30, 40 ,50}, {10.10, 20.20, 30.30, 40.40, 50.50}};
	struct output *pO = NULL;
	unsigned long j;
	int i;

	register_callback(handler_1);
	for(j=0; j<0xFFFFFFFF; j++){
	}
	trigger_event((void*)&I);

	pO = (struct output*)get_result();
	printf("pO->i_sum = %d\npO->d_sum = %lf\n", pO->i_sum, pO->d_sum);
	free(pO);
	pO = NULL;
	return (0);
}

struct output* handler_1(struct input* p_input){
	struct output* p_output = NULL;
	int i;
	if(p_input == NULL){
		return NULL;
	}

	p_output = (struct output*)malloc(sizeof(struct output));
	if(p_output == NULL){
		return p_output;
	}

	p_output->d_sum = 0.0;
	p_output->i_sum = 0;

	for(i=0; i<5; i++){
		p_output->i_sum += p_input->ia[i];
		p_output->d_sum += p_input->da[i];
	}

	return (p_output);
}
