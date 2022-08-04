// Prime Factorization

#include <stdio.h>

#define MAXDIVIDER 20

int main (){
    int num, i, divider = 0, maxnum;
    int arr[MAXDIVIDER];
    printf("Please enter the number you want to find the prime factorization to:\t");
    scanf("%d", &num);
    maxnum = num;

    for(i = 2; i <= maxnum; i++)
    {
        if(num % i == 0)
        {
            arr[divider] = i;
            num = num / i;
            printf( "\n%d     %d", num, arr[divider]);
            divider++;
            i = 1;
        }
    }
    printf("\n\nThe list of the dividers:\t{ ");
    for(i = 0; i < divider; i++)
    {
        printf("|  %d  |", arr[i]);
    }
    printf(" }\n\n");

    return 0;
}
