#include <stdio.h>

int min_el(int array[], int length);
int max_el(int array[], int length);

int main(){
    int arr[] = {22, 34, 11, 75, 25, 62, 26, 47};
    int min, max, len;
    len = sizeof(arr)/ sizeof(arr[0]);

    min = min_el(arr, len);
    max = max_el(arr, len);

    printf("\n\nThe minimum element of this array is:  %d\n\n", min);
    printf("\n\nThe maximum element of this array is:  %d\n\n", max);

    return 0;
}

int min_el(int array[], int length){
    int min, i;
    min = array[0];

    printf("\n\n\t\t================ MIN ELEMENT OF AN ARRAY ================\n");
    for (i = 1; i < length; i++)
    {
        printf("\nSearching....\nArray[%d] = %d\n", i, array[i]);
        if(array[i] < min)
        {
            min = array[i];
            printf("New min found !! ----->  %d\n", min);
        }
    }

    return min;
}

int max_el(int array[], int length){
    int max, i;
    max = array[0];

    printf("\n\n\t\t================ MAX ELEMENT OF AN ARRAY ================\n");
    for (i = 1; i < length; i++)
    {
        printf("\nSearching....\nArray[%d] = %d\n", i, array[i]);
        if(array[i] > max)
        {
            max = array[i];
            printf("New max found !! ----->  %d\n", max);
        }
    }

    return max;
}
