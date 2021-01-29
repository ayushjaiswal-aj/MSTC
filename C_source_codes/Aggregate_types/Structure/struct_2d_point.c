#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point2D {
	float x, y;
};

int main(void){
	struct Point2D p1 = {1.1f, 2.2f};
	struct Point2D p2 = {-4.3f, 1.8f};
	
	float distance = 0.0f;
	float delta_x = 0.0f;
	float delta_y = 0.0f;

	delta_x = p2.x - p1.x;
	delta_y = p2.y - p2.y;
	
	distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	printf("distance between p1, p2 is %f\n", distance);

	return(0);
} 
