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
	Studentptr_t stu;
	
	printf("Enter roll number: ");
	scanf("%d", &((*stu).roll_no));
	
	printf("Enter marks: ");
	scanf("%f", &((*stu).marks));
	
	printf("Roll no: %d, marks: %f\n", stu->roll_no, stu->marks);
	
	return (0);
}
