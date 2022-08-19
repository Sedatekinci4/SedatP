#include <stdio.h>

void menu(void);
void reverseArray(int array[], int length);
void printArray(int array[], int length);
void rotateArrayLeftOnce(int array[], int length);
void rotateArrayLeftNtimes(int array[], int length, int N);
void rotateArrayRightOnce(int array[], int length);
void rotateArrayRightNtimes(int array[], int length, int N);


int main(){

    int arry[] = {1, 2, 3, 4, 5, 6, 7 , 8, 9};
    int length, choice, num;
    char contFlag = 'y';
    length = sizeof(arry) / sizeof(int);



    do
    {
        printf("\n\n\tThe array is:\t");
        printArray(arry, length);
        menu();
        printf("\n\nYour answer:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\nPRINTING THE ARRAY.....\n");
                printArray(arry, length);
                break;
            case 2:
                printf("\nREVERSING THE ARRAY.....\n");
                reverseArray(arry, length);
                printArray(arry, length);
                break;
            case 3:
                printf("\nROTATING THE ARRAY LEFT ONCE.....\n");
                rotateArrayLeftOnce(arry, length);
                printArray(arry, length);
                break;
            case 4:
                printf("\n\nPlease enter the times you want to rotate:\t");
                scanf("%d", &num);
                printf("\nROTATING THE ARRAY LEFT %d TIMES.....\n", num);
                rotateArrayLeftNtimes(arry, length, num);
                printArray(arry, length);
                break;
            case 5:
                printf("\nROTATING THE ARRAY RIGHT ONCE.....\n");
                rotateArrayRightOnce(arry, length);
                printArray(arry, length);
                break;
            case 6:
                printf("\n\nPlease enter the times you want to rotate:\t");
                scanf("%d", &num);
                printf("\nROTATING THE ARRAY RIGHT %d TIMES.....\n", num);
                rotateArrayRightNtimes(arry, length, num);
                printArray(arry, length);
                break;
            case 7:
                return 0;
                break;
            default:
                printf("You have pressed the wrong key. Please enter a valid key!!!!");
                fflush(stdin);
                break;
        }
    printf("Do you want to make another operation? [ y / n ]:\t");
    scanf("%s", &contFlag);
    }while(contFlag == 'y' || contFlag == 'Y');

    /*printArray(arry, length);
    reverseArray(arry, length);
    printArray(arry, length);
    rotateArrayLeftOnce(arry, length);
    printArray(arry, length);
    rotateArrayLeftNtimes(arry, length, 7);
    printArray(arry, length);
    rotateArrayRightOnce(arry, length);
    printArray(arry, length);
    rotateArrayRightNtimes(arry, length, 5);
    printArray(arry, length);*/

    printf("\n\n\tBye Bye\n\n");
    return 0;
}

void menu(void)
{
    printf("\n--------Please choose the operation you want to do--------");
    printf("\n1. Print the array");
    printf("\n2. Reverse and print the array");
    printf("\n3. Rotate left once and print the array");
    printf("\n4. Rotate left N times and print the array");
    printf("\n5. Rotate right and print the array");
    printf("\n6. Rotate right N times and print the array");
    printf("\n7. Exit the program");

}

void reverseArray(int array[], int length)
{
    int temp = 0;

    for (int i = 0; i < (length / 2); i++)
    {
        temp = array[i];
        array[i] = array[length - i - 1];
        array[length -i - 1] = temp;
    }

}

void printArray(int array[], int length)
{
    printf("{ ");
    for( int i = 0; i < length; i++)
    {
        printf("%d  ",array[i]);
    }
    printf("}");
    printf("\n\n");
}

void rotateArrayLeftOnce(int array[], int length)
{
    int temp = array[0];
    for (int i = 0; i < (length - 1); i++)
    {
        array[i] = array[i+1];
    }
    array[length - 1] = temp;
}

void rotateArrayLeftNtimes(int array[], int length, int N)
{
    for(int i = 0; i < N; i++)
    {
        rotateArrayLeftOnce(array, length);
    }
}

void rotateArrayRightOnce(int array[], int length)
{
    int temp = array[length - 1];
    for (int i = length - 2; i >= 0 ; i--)
    {
        array[i + 1] = array[i];
    }
    array[0] = temp;
}

void rotateArrayRightNtimes(int array[], int length, int N)
{
    for(int i = 0; i < N; i++)
    {
        rotateArrayRightOnce(array, length);
    }
}
