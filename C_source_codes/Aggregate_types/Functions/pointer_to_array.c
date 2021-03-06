#include<stdio.h>
#include<stdlib.h>

int  A[10];

int main(void){
	int  (*p)[10] = NULL;
	int i;
	p = &A;
	printf("Enter elements\n");
	for (i=0; i<10; i++){
		scanf("%d", &(*p)[i]);
	}
	printf("Elements entered into array\n");
	for (i=0; i<10; i++){
		printf("A[%d] = %d\n", i, (*p)[i]);
	}

	exit (0);
}
