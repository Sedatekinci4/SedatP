// Next Prime Number

#include <stdio.h>

int main(){
    char answer = 'y';
    int num = 2, i = 0;

    do
    {
        printf("Do you want to find the next prime number? [ y / n ] ----->  ");
        answer = getchar();
        getchar();

        for(i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                num++;
            }
        }
        printf("The next Prime number is ----> %d\n", num);
        num++;
    }while(answer == 'y' || answer == 'Y');

    return 0;
}
