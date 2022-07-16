#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main()
{
    // ------------------ PI Calculation ------------------
    
    int N_real, N;
    N_real = MAX;

	if(N_real < 1)
	{	
		printf("Please enter more than 0 digits");
		return -1;
	}
    double digit = 0.0;
    int i;
    printf("%dth digit of PI calculation...\n" , MAX);
    for (i = 0; i != N_real; ++i) 
	{
        digit += ((pow(16, -i))) * (((4.0 / (8 * i + 1))) -((2.0 / (8 * i + 4))) - ((1.0 / (8 * i + 5))) - ((1.0 / (8 * i + 6))));
    }
    printf("Pi is: %.*f\n\n", N_real, digit);
	return 0;
}

