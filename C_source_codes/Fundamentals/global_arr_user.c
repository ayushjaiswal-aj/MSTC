#include<stdio.h>
#include<stdlib.h>

int arr[5];
int cnt;

int main(void){
	for(cnt = 0; cnt < 5; cnt++){
		printf("Enter arr[%d]: ", cnt);
	scanf("%d", &arr[cnt]);
	}

	for(cnt = 0; cnt < 5; cnt++){
		printf("arr[%d]: %d\n", cnt, arr[cnt]);
	}

	exit(0);
}
