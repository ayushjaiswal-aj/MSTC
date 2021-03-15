#include<stdio.h>
#include<stdlib.h>

int main(void){
	int i;
	int a[5];

	for (i=0; i<5; i++){
		printf("Enter a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	for (i=0; i<5; i++){
		printf("a[%d]: %d\n", i , a[i]);
	}

	exit(0);
}
