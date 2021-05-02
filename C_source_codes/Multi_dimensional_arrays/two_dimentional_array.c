#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long int u64;

void method1(void);
void method2(void);
void method3(void);
void method4(void);

int main(void){
	method1();
	method2();
	method3();
	method4();

	return 0;
}

void method1(void){
	int a[5][3];
	int i, j;
	printf("address of a = %llu\n", (u64)a);
	printf("address of a+1 = %llu\n", (u64)(a+1));
	printf("address of &a+1 = %llu\n", (u64)(&a+1));

	puts("Method1: element is set to multiplication of its indices:");
	for(i=0; i<5; i++){
		for(j=0; j<3; j++){
			a[i][j] = i*j;
		}
	}
	for (i=0; i<5; i++){
		for(j=0; j<3; j++){
			printf("a[%d][%d]: %d\n", i, j, a[i][j]);
		}
	}
	return;
}

void method2(void){
	int m = 6, n = 4;
	int i, j;
	int *p = NULL;
	int element;

	p = (int*)malloc(sizeof(int) * m * n);
	assert(p);
	
	puts("Method2: element is set to addition of its indices");
	for (i=0; i<m; i++){
		for(j=0; j<n; j++){
			element = *(p + i*n + j);
			printf("a[%d][%d]: %d\n", i, j, element);
		}
	}
	free(p);
	p = NULL;

	return ;
}

void method3(void){
	int (*p)[6][4];
	typedef int (*array_t)[6][4];
	int i, j;

	puts("Method3: element is set to multiplication of its indices:");

	p = (array_t) malloc(sizeof(int) * 6 * 4);
	for(i=0; i<6; i++){
		for(j=0; j<4; j++){
			printf("a[%d][%d]: %d\n", i, j, (*p)[i][j]);
		}
	}
	free(p);
	p = NULL;

	return;
}

void method4(void){
	int m = 6, n= 4;
	int **pp = NULL;
	int i, j;
	pp = (int**)malloc(sizeof(int*) * m);
	for(i=0; i<m; i++){
		pp[i] = (int*) malloc(n * sizeof(int));
	}

	for (i=0; i<m; i++){
		for(j=0; j<n; j++){
			pp[i][j] = i*j;
		}
	}
	
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("pp[%d][%d] = %d\n", i, j, pp[i][j]);
		}
	}
	for (i=0; i<m; i++){
		free(pp[i]);
	}
	free(pp);
	pp = NULL;
	return ;
}
