#include <stdio.h>
#include <stdlib.h>

typedef int roll_t;
typedef float marks_t;

struct student{
	roll_t roll_no;
	marks_t marks;
};

typedef struct student student_t;

int main(void){
	student_t student1;
	
	printf("Enter roll number: ");
	scanf("%d", &(student1.roll_no));
	
	printf("Enter marks: ");
	scanf("%f", &(student1.marks));

	printf("roll no: %d, marks: %f\n", student1.roll_no, student1.marks);
	
	return (0);
}
