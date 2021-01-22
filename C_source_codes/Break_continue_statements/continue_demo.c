#include<stdio.h>
#include<stdlib.h>
	
int A[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int i;

int main(){
	while(i<8) {
		if(A[i] % 7 == 0){
			i = i+1;
			continue;
		}
		printf("A[%d] : %d\n", i, A[i]);
		i = i+1;
	}
	exit(0);
}
