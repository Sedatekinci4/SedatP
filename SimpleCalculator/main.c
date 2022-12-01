// Simple Calculator

#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <stdlib.h>

void addition(void);
void subtraction(void);
void multiply(void);
void division(void);
void factorial(void);
void modulus(void);
void power(void);

int main() {
    char contFlag = 'y';
    char op;
    while(contFlag)
    {
        system("cls");
        printf("\n------------Welcome to the Calculator------------");
        printf("\n\nEnter '+' for addition");
        printf("\nEnter '-' for subtraction");
        printf("\nEnter '*' for multiply");
        printf("\nEnter '/' for division");
        printf("\nEnter '!' for factorial");
        printf("\nEnter '^' for power");
        printf("\nEnter mod operand for modulus");
        printf("\nEnter 'Q' or 'q' for quitting");
        printf("\nPlease enter the operation you want to do:\t");
        scanf("%s", &op);
        switch(op)
        {
            case '+':
                addition();
                break;
            case '-':
                subtraction();
                break;
            case '*':
                multiply();
                break;
            case '/':
                division();
                break;
            case '!':
                factorial();
                break;
            case '^':
                power();
                break;
            case '%':
                modulus();
                break;
            case 'q':
            case 'Q':
                return 0;
                break;
            default:
                system("cls");
                printf("\n------You have entered inappropriate operation------");
                printf("\n-----------------------------------------------------");
                printf("\n Please enter any of available operations");
                printf("\n-----------------------------------------------------\n");
                break;
        }


        printf("\nDo you want to continue? [y / n] --------->\t");
        scanf(" %c", &contFlag);
        if(contFlag == 'n')
        {
            return 0;
        }
    }

    return 0;
}

void addition(void)
{
    int first, second, result;
    printf("Please enter the first number:\t");
    scanf("%d", &first);
    printf("Please enter the first number:\t");
    scanf("%d", &second);
    result = first + second;
    printf("\n%d + %d = %d\n", first, second, result);
}

void subtraction(void)
{
    int first, second, result;
    printf("Please enter the first number:\t");
    scanf("%d", &first);
    printf("Please enter the first number:\t");
    scanf("%d", &second);
    result = first - second;
    printf("\n%d - %d = %d\n", first, second, result);
}

void multiply(void)
{
    int first, second, result;
    printf("Please enter the first number:\t");
    scanf("%d", &first);
    printf("Please enter the first number:\t");
    scanf("%d", &second);
    result = first * second;
    printf("\n%d * %d = %d\n", first, second, result);
}

void division(void)
{
    int first, second, result;
    printf("Please enter the first number:\t");
    scanf("%d", &first);
    printf("Please enter the first number:\t");
    scanf("%d", &second);
    result = first / second;
    printf("\n%d / %d = %d\n", first, second, result);
}

void modulus(void)
{
    int first, second, result;
    printf("Please enter the first number:\t");
    scanf("%d", &first);
    printf("Please enter the first number:\t");
    scanf("%d", &second);
    result = first % second;
    printf("\n%d mod %d = %d\n", first, second, result);
}

void power(void)
{
    double first, second, result;
    printf("Please enter the number:\t");
    scanf("%lf", &first);
    printf("Please enter the power of the number:\t");
    scanf("%lf", &second);
    result = pow(first, second);
    printf("\n%lf + %lf = %lf\n", first, second, result);
}

void factorial(void)
{
    int i, fact = 1, num;

    printf("\nEnter a number for the factorial operation:\t");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("\nPlease enter positive number, factorial can't be done:\t");
        return 1;
    }

    for(i = 1; i <= num; i++)
    {
        fact = fact*i;
    }
    printf("The factorial of the %d is %d", num, fact);
}
