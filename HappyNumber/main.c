#include <stdio.h>
#include <stdbool.h>

bool happyNumber(int n);

int main(){
    int number;
    printf("\nPlease enter the number to check if it is a happy number or not:\t");
    scanf("%d", &number);

    if(happyNumber(number))
    {
        printf("\n%d is a happy number!!!", number);
    }
    else
    {
        printf("\n%d is NOT a happy number!!!", number);
    }
    return 0;
}

bool happyNumber(int n){
    if(n == 1 || n == 7)
    {
        return true;
    }
    int sum = n, x = n;
    while (sum > 9)
    {
        sum = 0;

        while(x > 0)
        {
            int d = x%10;
            sum += d * d;
            x /= 10;
        }
        if (sum == 1)
            return true;

        x = sum;
    }
    if ( sum == 7)
        return true;

    return false;
}
