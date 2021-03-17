#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void test_function(void);

int main(void){
	test_function();
	return (0);
}

void test_function(void){
	char* pc = NULL;
	unsigned char* puc = NULL;
	long int* p_lng_int = NULL;
	float* pf = NULL;

	pc = (char*)malloc(sizeof(char));
	assert(pc != NULL);
	memset(pc, 0, sizeof(char));
	*pc = 'A';
	printf("*pc = %c\n", *pc);
	free(pc);
	pc = NULL;

	puc = (unsigned char*)malloc(sizeof(unsigned char));
	memset(puc, 0, sizeof(unsigned char));
	assert(puc != NULL);
	*puc = 0xff;
	printf("*puc = %hhu\n", *puc);
	free(puc);
	puc = NULL;

	p_lng_int = (long int*)malloc(sizeof(long int));
	assert(p_lng_int != NULL);
	memset(p_lng_int, 0, sizeof(long int));
	*p_lng_int = 0xffffff;
	printf("*p_lng_int = %ld\n", *p_lng_int);
	free(p_lng_int);
	p_lng_int = NULL;
	
	pf = (float*)malloc(sizeof(float));
	assert(pf != NULL);
	memset(pf, 0, sizeof(float));
	printf("Enter a fraction number:");
	scanf("%f", pf);
	printf("Entered fraction = %f\n", *pf);
	free(pf);
	pf = NULL;
}
