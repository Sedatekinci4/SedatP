#include <stdio.h>
#include <stdlib.h>

void merge(int arry[], int left, int middle, int right);
void mergeSort(int arry[], int left, int right);

int main() {
    int arry[] = {14, 15, 78, 48, 95, 10, 96, 21};
    int arry_size = sizeof(arry)/sizeof(arry[0]);
    int i;
    printf("The given array is:\n");
    for (i=0; i < arry_size; i++)
    {
        printf("%d ", arry[i]);
    }
    printf("\n\n");

    mergeSort(arry, 0, arry_size - 1);
    printf("\nThe sorted array is:\n");
    for (i=0; i < arry_size; i++)
    {
        printf("%d ", arry[i]);
    }
    printf("\n\n\n");


    return 0;
}

void mergeSort(int arry[], int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(arry, left, middle);
        mergeSort(arry, middle + 1, right);
        merge(arry, left, middle, right);
    }
}

void merge(int arry[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    L[i] = arry[left + i];
    for (j = 0; j < n2; j++)
    R[j] = arry[middle + 1+ j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arry[k] = L[i];
            i++;
        }
        else
        {
            arry[k] = R[j];
            j++;
        }
    k++;
    }
    while (i < n1)
    {
        arry[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arry[k] = R[j];
        j++;
        k++;
    }
}
