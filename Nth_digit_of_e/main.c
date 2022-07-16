#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

unsigned int factorial(unsigned int n);

int main()
{
	// ------------------ e Calculation ------------------
	int N = 0, N_real =0;
	N = MAX;
	if(N < 1)
	{	
		printf("Please enter more than 0 digits");
		return -1;
	}
	else if(N < 5)
	{
		N_real = 5;
	}
	else
	{
		N_real = MAX;
	}
	int j;
    double e = 1.0;
    printf("%dth digit of e calculation...\n", MAX);
    for (j = 1; j != N_real + 1; ++j) 
	{
        e += 1.0 / factorial(j);
    }
    	printf("e = %.*f\n", MAX , e);

    return 0;
}

unsigned int factorial(unsigned int n)
{
    unsigned int i;
    unsigned val = 1;
    for (i = 1; i != n + 1; ++i) 
	{
        val *= i;
    }
    return val;
}

