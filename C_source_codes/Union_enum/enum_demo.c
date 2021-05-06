#include <stdio.h>
#include <stdlib.h>

enum color {RED, GREEN, BLUE};
typedef enum state {IN = 5, OUT} state_t;

typedef enum color color_t;

int main(void){
	enum color c1;
	color_t c2;

	enum state s1;
	state_t s2;

	c1 = RED;
	printf("RED: c1=  %d\n", c1);
	c2 = BLUE;
	printf("BLUE: c2= %d\n", c2);

	s1 = IN;
	printf("IN: s1= %d\n", s1);
	
	s2 = OUT;
	printf("OUT: s2= %d\n", s2);

	return 0;
}
