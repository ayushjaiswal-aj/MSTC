#include <stdio.h>
#include <stdlib.h>

int min, max;
int i;
int A[5];

int main() {
	for (i=0; i<5; i++){
		printf("A[%d]: ", i);
		scanf("%d", &A[i]);
	}

	min = A[0];
	max = A[0];
	
	for (i=0; i<5; i++){
		if (A[i] < min){
			min = A[i];
		}
		if (A[i] > max){
			max = A[i];
		}
	}
	printf("min: %d, max: %d\n", min, max);
}
