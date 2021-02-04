#include<stdio.h>
#include<stdlib.h>
	
int get_square(int n){
	int rs;	
	printf("Address of (n): %p\n", &n);
	printf("n = %d\n", n);
	rs = n*n;
	return rs;
}

int main(void){
	int m = 10;
	int rs;
	printf("Address of (m) : %p\n", &m);
	printf("Before call (m): %d\n", m);
	rs = get_square(m);
	printf("After call (mm): %d\n", m);
	printf("main : rs : %d\n", rs);
	return (0);
}
