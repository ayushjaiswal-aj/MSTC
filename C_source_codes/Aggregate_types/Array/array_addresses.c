#include<stdio.h>
#include<stdlib.h>

int A[5] = {1,2,3,4,5};
int i;

int main() {
	for (i=0; i<5; i++){
		printf("A[%d]: %d, address of A[%d] = %p\n", i, A[i], i, &A[i]);
	}
}
