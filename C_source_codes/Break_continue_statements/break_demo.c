#include<stdio.h>
#include<stdlib.h>

int A[8];
int i;

int main(void){
	i=0;
	while(i < 8) {
		printf("Enter A[%d] element: ", i);
		scanf("%d", &A[i]);
		i = i + 1;
	}

	i = 0;
 	while(i<8) {
		if(A[i] %7 == 0){
			i = i + 1;
			break;
		}
		printf("A[%d] : %d\n", i, A[i]);
		i = i+1;
	}
	return(0);
}
