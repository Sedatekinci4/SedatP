#include <stdio.h>

int main(){

    int arr[50], num, i, j, temp;
    printf("Please Enter the number of elements for your array:\t ");
    scanf("%d", &num);
    printf("Please Enter the Value of the elements: \t ");
    for(i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < num - 1; i++)
    {
        for(j = 0; j < num - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted array is:\t ");
    for(i = 0; i < num; i++)
    {
        printf("%d  ", arr[i]);
    }
    return 0;
}
