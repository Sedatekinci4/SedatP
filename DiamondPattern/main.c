#include <stdio.h>

#define STAR "*"

int main(){
    int choice, i, j, k, most;

    printf("Please enter the number of rows you want to see in diamond:\t");
    scanf("%d", &choice);

    if(choice <= 0)
    {
        printf("\nPlease enter valid number! (choice cannot be negative of 0)\n\n");
        return 0;
    }

    for (i = 1; i <= choice ; i++)
    {
        for(j = 1; j <= choice - i; j++)
        {
            printf(" ");
        }
        for(k = 1; k <= 2*i - 1; k++)
        {
            printf("%s", STAR);
        }
        printf("\n");
    }

    //////////////////////REVERSE ORDER//////////////////////
    for (i = 1; i <= choice - 1 ; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf(" ");
        }
        for(k = 1; k <= 2*(choice - i) - 1; k++)
        {
            printf("%s", STAR);
        }
        printf("\n");
    }
    return 0;
}
