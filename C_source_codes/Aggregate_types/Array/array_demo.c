#include<stdio.h>
#include<stdlib.h>
	
int A1[] = {1, 2, 3, 4, 5};
int A2[5] = {1, 2, 3};
int A3[5];
int i;
int main() {
	for (i=0; i<5; i++){
		printf("A1[%d]: %d\n", i, A1[i]);
	}
	for (i=0; i<5; i++){
		printf("A2[%d]: %d\n", i, A2[i]);
	}
	for (i=0; i<5; i++){
		printf("A3[%d]: %d\n", i, A3[i]);
	}
}
