#include<stdio.h>
#include<stdlib.h>

int get_square(int *p){
	int n = *p;
	int rs;
	printf("get_square: p = %p, n = %d\n", p, n);
	rs = n*n;	
	return rs;
}

int main(void){
	int m = 100;
	int rs;
	printf("main: A(m): %p\n", &m);
	printf("main: Before call: V(m): %d\n", m);
	rs = get_square(&m);
	printf("main: After call:V(m): %d\n", m);
	printf("main: rs = %d\n", rs);
	return (0);
}
