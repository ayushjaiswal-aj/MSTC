#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int* p = NULL;

	p = (int*)malloc(sizeof(int));

	if(p == NULL){
		printf("Memory allocation failed, exiting.....");
		exit(-1);
	}

	memset(p, 0, sizeof(int));

	printf("Enter an integer:");
	scanf("%d", p);
	printf("Enter number: %d\n", *p);
	free(p);
	p = NULL;
	return(0);
}
