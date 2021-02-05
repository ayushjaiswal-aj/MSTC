#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point2d{
	float x,y;
};

float distance(struct point2d* p_point1, struct point2d* p_point2);

int main(void){
	struct point2d p1 = {1.1f, 2.2f};
	struct point2d p2 = {3.3f, 4.4f};
	float d;
	
	d = distance(&p1, &p2);
	printf("d(p1, p2): %.3f\n", d);
		
	return(0);
}

float distance(struct point2d* p_point1, struct point2d* p_point2){
	float delta_x, delta_y;
	float d;

	delta_x = p_point2->x - p_point1->x;
	delta_y = p_point2->y - p_point1->y;

	d = sqrt(delta_x * delta_x + delta_y*delta_y);
	return (d);
}
