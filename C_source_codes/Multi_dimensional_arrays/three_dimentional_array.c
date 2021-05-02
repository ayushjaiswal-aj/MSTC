#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long int u64;

void method1(void);

int main(void){
	method1();
	return (0);
}

void method1(void){
	int *p = NULL;
	int i,j,k;

	p = (int*)malloc(sizeof(int) * 3 * 5 * 4);
	assert(p);

	for (i=0; i<3; i++){
		for(j=0; j<5; j++){
			for(k=0; k<4; k++){
				printf("p + (%d*5*4) + (%d*4) + %d = %llu\n", i, j, k, (u64)(p + (i*5*4) + (j*4) + k));
			}
		}
	}
	free(p);
	p = NULL;
	return;
}
