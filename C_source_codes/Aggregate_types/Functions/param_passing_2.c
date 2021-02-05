#include<stdlib.h>
#include<stdio.h>

int get_sum(int *, int n);

int main(void) {
	int A[] = {10,20, 30, 40, 50, 60, 70, 80, 90,100};
	int result;
	printf("A[] = {10,20,30,40,50,60,70,80,90,100}\n");
	result = get_sum(&A[0], 10);
	printf("Result = %d\n", result);

	return (0);
}

int get_sum(int *A, int size){
	int i;
	int sum = 0;
	for (i=0; i<size; i++){
		sum = sum + A[i];
	}

	return (sum);
}
