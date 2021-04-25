#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long int n = 0x0a0b0c0d;
	if (*(unsigned char*)&n == 0xd)
		puts("this machine is a little endian machine");
	else if (*(unsigned char*)&n == 0xa)
		puts("this machine is a big endian machine");
	else 
		puts("this is a strange machine");

	return 0;
}
