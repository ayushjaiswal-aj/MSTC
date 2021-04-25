#include <stdio.h>
#include <stdlib.h>

int n = 0x0A0B0C0D;
unsigned char uc;

int main(void){
	uc = (unsigned char) n;
	printf("uc = %hhx\n", uc);
	return 0;
}
