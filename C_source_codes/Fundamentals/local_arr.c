#include<stdio.h>
#include<stdlib.h>

int main(void){
	int i;
	int a[5] = {100, 200, 300, 400, 500};
	
	for (i=0; i<5; i++){
		printf("a[%d] = %d\n", i, a[i]);
	}

	exit(0);
}
