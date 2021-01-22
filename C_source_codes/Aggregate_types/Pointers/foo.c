#include<stdio.h>
#include<stdlib.h>

void test(){
	puts("hey!");
}

int main(){
	puts("hey");
	void(*pfn)(void) = &test;
	return 0;
}

