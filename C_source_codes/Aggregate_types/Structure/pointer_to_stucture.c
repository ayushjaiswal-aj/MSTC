#include <stdio.h>
#include <stdlib.h>

struct Date{
	int day;
	int month;
	int year;
};
	
struct Student{
	int st_roll_number;
	float st_marks;
	float st_attendance;
	struct Date st_date_of_birth;
};

struct Student s1 = {10, 87.90, 96.33, {20, 11, 2000}};

struct Date d1 = {12, 4, 2021};

struct Student* p_student;

struct Date* p_date;

int main(void) {
	p_student = &s1;

	printf("roll number (s1): %d\n", (*p_student).st_roll_number);
	printf("marks (s1): %.2f\n", (*p_student).st_marks);
	printf("attendance (s1): %.2f\n", (*p_student).st_attendance);
	printf("date of birth (s1): %d-%d-%d\n", (*p_student).st_date_of_birth.day, (*p_student).st_date_of_birth.month, (*p_student).st_date_of_birth.year);

	(*p_student).st_roll_number = 12;
	(*p_student).st_marks = 76.88;
	(*p_student).st_attendance = 89.99;
	(*p_student).st_date_of_birth.day = 2;
	(*p_student).st_date_of_birth.month = 3;
	(*p_student).st_date_of_birth.year = 2002;

	printf("roll number (s1): %d\n", (*p_student).st_roll_number);
	printf("marks (s1): %.2f\n", (*p_student).st_marks);
	printf("attendance (s1): %.2f\n", (*p_student).st_attendance);
	printf("date of birth (s1): %d-%d-%d\n", (*p_student).st_date_of_birth.day, (*p_student).st_date_of_birth.month, (*p_student).st_date_of_birth.year);

	p_date = &d1;

	printf("%d-%d-%d\n", p_date->day, p_date->month, p_date->year);

	p_date->day = 12;
	p_date->month = 7;
	p_date->year = 2019;

	printf("%d-%d-%d\n", p_date->day, p_date->month, p_date->year);

	return (0);
}
