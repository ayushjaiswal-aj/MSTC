#include <stdio.h>
#include <stdlib.h>

typedef int roll_t;
typedef float marks_t;

struct Student{
	roll_t roll_no;
	marks_t marks;
};

typedef struct Student Student_t;
typedef Student_t* Studentptr_t;

int main(void){
	Student_t stu;
	Studentptr_t stuptr;

	stu.roll_no = 123;
	stu.marks = 87.098;
	
	printf("Roll no: %d, marks: %f\n", stu.roll_no, stu.marks);

	printf("Roll No: ");
	scanf("%d", &(stuptr->roll_no));

	printf("Marks: ");
	scanf("%f", &(stuptr->marks));

	printf("Roll no: %d, marks: %f\n", stuptr->roll_no, stuptr->marks);		
	return (0);
}
