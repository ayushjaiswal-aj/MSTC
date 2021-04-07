#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int n, m;

int* p;
const int* cp;

int *const x1 = &n;
int *const x2 = &m;

const int *const y1 = &n;
const int *const y2 = &m;

int main(void){
	p = &n;
	printf("p (int* p; p = &n): %p\n", p);

	p = &m;
	printf("p (int* p; p = &m): %p\n", p);

	cp = &n;
	printf("cp (const int* cp; cp = &n): %p\n", cp);
	
	cp = &m;
	printf("cp (const int* cp; cp = &m): %p\n", cp);

	printf("x (int *const x1; x1 = &n): %p\n", x1);

	printf("x (int *const x2; x2 = &m): %p\n", x2);

	printf("y (const int *const y1; y1 = &n): %p\n", y1);
	
	printf("y (const int *const y2; y2 = &m): %p\n", y2);
}
