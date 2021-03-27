#include <stdio.h>
#include <stdlib.h>

typedef int roll_t;
typedef float marks_t;

int main(void){
	roll_t roll_no;
	marks_t marks;
	
	puts("Enter roll no.");
	scanf("%d", &roll_no);

	puts("Enter marks");
	scanf("%f", &marks);
	
	printf("Roll no: %d, marks: %f\n", roll_no, marks);
}
