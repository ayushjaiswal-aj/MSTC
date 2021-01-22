#include <stdio.h>
#include <stdlib.h>

int A[10];
int i;

int main() {
	for (i=0; i<10; i++){
		printf("A[%d]:", i);
		scanf("%d", &A[i]);
	}

	for (i=0; i<10; i++){
		printf("A[%d]: %d\n", i, A[i]);
	}
}
