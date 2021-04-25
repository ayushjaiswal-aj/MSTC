#include <stdio.h>
#include <stdlib.h>

unsigned long long n = 0;

int main(void){
	printf("n = %llx\n", n);
	*(char*) (&n) = 0xff;
	printf("n = %llx\n", n);

	*(short*)((char*)(&n) + 1) = 0xffff;
	printf("n = %llx\n", n);

	*(int*)((char*)(&n) + 3) = 0xffffffff;
	printf("n = %llx\n", n);	

	*(char*)((char*)&n + 7) = 0xff;
	printf("n = %llx\n", n);

	return 0;
}
