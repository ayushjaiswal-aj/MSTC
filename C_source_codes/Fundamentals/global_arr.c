#include<stdio.h>
#include<stdlib.h>

int arr[5] = {100, 200, 300, 400, 500};
int cnt;

int main(void){
	for (cnt = 0; cnt < 5; cnt++){
		printf("arr[%d]: %d\n", cnt, arr[cnt]);
	}
	exit(0);
}
