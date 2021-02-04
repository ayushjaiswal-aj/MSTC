#include<stdio.h>
#include<stdlib.h>

int get_square(int n){
	int res;
	res = n*n;
	return res;
}

int main(void) {
	int rs;
	
	rs = get_square(10);
	printf("get_square(10) = rs = %d\n", rs);
	
	return (0);
}
