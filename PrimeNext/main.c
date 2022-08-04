// Ýnputted Next Prime Number

#include <stdio.h>

int main(){
    char answer = 'y';
    int num = 2, i = 0;
    printf("\nThis program will find the next prime number after your inputted integer.\n");
    printf("Please enter your integer: \t");
    scanf("%d", &num);
    do
    {
        num++;
        printf("Do you want to find the next prime number? [ y / n ] ----->  ");
        scanf(" %c", &answer);

        for(i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                num++;
            }
        }
        printf("The next Prime number is ----> %d\n", num);
    }while(answer == 'y' || answer == 'Y');

    return 0;
}

