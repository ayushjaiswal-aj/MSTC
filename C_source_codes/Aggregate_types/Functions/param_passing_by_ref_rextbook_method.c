#include<stdio.h>
#include<stdlib.h>

int get_sum(int(*p_arr)[], int size);

int main(void){
	int A[10] = {10,20,30,40,50,60,70,80,90,100};
	int sum;

	sum = get_sum(&A, 10);
	printf("Textbook method: sum= %d\n", sum);
	
	return (0);
}

int get_sum(int (*p_arr)[], int size){
	int sum =0;
	int i;
	for (i=0; i<size; i++){
		sum = sum + (*p_arr)[i];
	}
	return (sum);
}
