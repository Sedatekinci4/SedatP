#include <stdio.h>

int recursiveFact(int n);

int main (){
    int number, i, result1 = 1, result2 = 0;
    printf("Please enter the number you want to find the factorial to:(ps: maximum num is 16)\t");
    scanf("%d", &number);

    for(i = number; i >= 1; i--)
    {
        result1 = result1 * i;
    }
    printf("\n\nFactorial of %d for loop is %d", number, result1);
    result2 = recursiveFact(number);
    printf("\n\nFactorial of %d for recursive function is %d\n\n", number, result2);
    return 0;
}

int recursiveFact(int n){
    if (n>1)
    {
        return n*recursiveFact(n-1);
    }
    else
    {
        return 1;
    }
}
