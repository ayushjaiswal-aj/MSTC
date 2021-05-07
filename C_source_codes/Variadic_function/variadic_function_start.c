#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void f(int n, ...);

int main(void){
	puts("f(0): ");
	f(0);
	puts("f(1, 10):");
	f(1, 10);
	puts("f(2, 20, 200):");
	f(2, 20, 200);
	puts("f(3, 30, 300, 3000):");
	f(3, 30, 300, 3000);
	puts("f(4, 40, 400, 4000, 40000):");
	f(4, 40, 400, 4000, 40000);

	return 0;
}

void f(int n, ...){
	va_list ap;
	int i_storage;
	int index;

	va_start(ap, n);

	printf("n: %d\n", n);
	printf("variadic arguments:\n");
	for(index = 0; index < n; index++){
		i_storage = va_arg(ap, int);

		printf("i_storage = %d\n", i_storage);
	}

	va_end(ap);
}
