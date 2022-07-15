#include <stdio.h>
#include <stdlib.h>

int binary = 0,  	  // binary number we take with scanf
decimal = 0,     	  // var for storing decimal equivalent
bincpy = 0, 	 	  // copy of binary num to use later
bin = 0,		 	  // copy of binary to use in calculations
rem = 0, weight = 1,  //variables for conversion 
j =0;				  // vaiable to check binary input (continious %10 processes)

int isBinary = 1;	  // just a boolean to check if the input correct or not

int main() 
{
	while(isBinary)
	{
		printf("Please enter binary you want to convert: ");
		scanf("%d", &binary);
		bin = binary;
		while(binary > 0)
		{
			j = binary%10;
			if(j!= 0 && j != 1)
			{
				printf("Number is not binary or more than 8 digits\n");
				break;
			}
			binary = binary/10;;
			if(binary == 0)
			{
				isBinary = 0;
			}
		}
	}
	bincpy = bin;
	while(bin != 0)
	{
		rem = bin %10;
		decimal = decimal + rem*weight;
		bin = bin /10;
		weight = weight*2;
	}
	printf("Decimal equivalent of binary %d ----> decimal %d", bincpy ,decimal);
	return 0;
}
