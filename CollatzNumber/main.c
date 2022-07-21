#include <stdio.h>

int collatzAlgorithm(int number);

int main(){
	int n;
	printf("Please enter a integer you want to use in collatz algorithm: ");
	scanf("%d", &n);
	collatzAlgorithm(n);
	
	return 0;
}

int collatzAlgorithm(int number)
{
	int nextTerm = number;
	printf("%d ", number);

	if(number == 1)
	{
		return 1;
	}

	if(number % 2 == 0)
	{
		nextTerm = number / 2;
	}
	
	else if(number % 2 == 1)
	{
		nextTerm = 3*number + 1;
	}
	
	return collatzAlgorithm(nextTerm);
}

