#include <stdio.h>
#include <stdlib.h>

int __attribute__((regparm(3))) find_max(int a, int b, int c);

int n1 = 10, n2 = 20, n3 = 30;
int m;

int main(void){
	m = find_max(n1, n2, n3);
	printf("max = %d\n", m);
	return (0);
}

int __attribute__((regparm(3))) find_max(int a, int b, int c){
	register int max = a;

	if (b>max)
		max = b;
	if (c>max)
		max = c;
	return (max);
}
