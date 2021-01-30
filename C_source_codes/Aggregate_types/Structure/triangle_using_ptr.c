#include <stdio.h>
#include <stdlib.h>

struct Point2d{
	float x, y;
};

struct Triangle{
	struct Point2d* p_A;
	struct Point2d* p_B;
	struct Point2d* p_C;
};

struct Point2d A = {12.48, 9.00};
struct Point2d B = {9.76, 6.98};
struct Point2d C = {4.98, -7.53};

struct Triangle T;

int main(void) {
	struct Triangle* p_T = NULL;
	
	p_T = &T;
	p_T-> p_A = &A;
	p_T-> p_B = &B;
	p_T-> p_C = &C;
	
	printf("A.x: %.2f, A.y: %.2f\n", p_T->p_A->x, p_T->p_A->y);
	printf("B.x: %.2f, B.y: %.2f\n", p_T->p_B->x, p_T->p_B->y);
	printf("C.x: %.2f, C.y: %.2f\n", p_T->p_C->x, p_T->p_C->y);
	
	return (0);
}
