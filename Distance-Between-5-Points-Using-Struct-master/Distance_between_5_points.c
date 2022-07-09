/*
	C Programlama--> 
	Finding the distance between 5 different 2D points using structs
	Struct kullanarak 5 noktanin birirleri ile arasindaki mesafeyi bulma
	-Sedat Ekinci

*/
#include <stdio.h>
#include <math.h>

typedef struct points
{
	int x,y;
}point;

float distanceBetweenPoints(point p1, point p2) 
{
	float distance = 0;
	distance = sqrt(pow(p2.y - p1.y, 2) + pow(p2.x - p1.x, 2));
	return distance; 	
}

int main()
{
	int i,j,k;
	point p[5];
	
	for(i = 1;i <= 5;++i)
	{
		printf("Enter the coordinates of %d. point as x and y -->\n",i);
		scanf("%d%d", &p[i].x, &p[i].y);		
	}
	
	for(j = 1;j <=5;++j)
	{	
		for (k = j + 1;k <= 5;++k)
		{
			printf("Distance between %d. ve %d. points --> %3f unit\n",j,k,distanceBetweenPoints(p[j],p[k]));
		
		} 	
	} 
	
	return 0;
}
