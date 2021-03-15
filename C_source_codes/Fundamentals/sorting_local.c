#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int main(void){

	int a[SIZE];
	int i, j, key;

	for (i=0; i<SIZE; i++){
		printf("Enter a[%d]: ", i);
		scanf("%d", &a[i]);
	}

	puts("Before sort:");
	for (i=0; i<SIZE; i++){
		printf("a[%d]: %d\n", i, a[i]);
	}

	for (j=1; j<SIZE; j++){
		key = a[j];
		i = j-1;

		while(i> -1 && a[i]>key){
			a[i+1] = a[i];
			i = i - 1;
		}
		a[i+1] = key;
	}

	puts("After sort:");
	for (i=0; i<SIZE; i++){
		printf("a[%d]: %d\n", i, a[i]);
	}

	exit(0);
}
