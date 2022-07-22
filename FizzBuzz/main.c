#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
	int j;

	for(j = 1; j <= MAX; j++)
	{
		if(j % 3 == 0 && j % 5 == 0)
		{
			printf("FizzBuzz | ");
		}
		else if(j % 3 == 0)
		{
			printf("Fizz | ");
		}
		else if(j % 5 == 0)
		{
			printf("Buzz | ");	
		}
		else
			printf("%d | ", j);
	}
	
	return 0;
}
