#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADSIZE 2
#define ARRSIZE 6

int arr[ARRSIZE] = {1 ,2, 3, 4, 5, 6};

void* routine(void* arg){
    int index = *(int*)arg;
    int sum = 1;
    for (int j = 0; j < (ARRSIZE/2); j++)
    {
        sum = sum * arr[index + j];
    }
    printf("Local multiplication result is: %d\n", sum);
    *(int*)arg = sum;
    return arg;
}

int main(){
    pthread_t th[THREADSIZE];
    for (int i = 0; i < THREADSIZE; i++)
    {
        int* a = malloc(sizeof(int));
        *a = i * (ARRSIZE/2);
        if(pthread_create(th + i, NULL, &routine, a) != 0)
        {
            perror("Error while creating thread!\n");
        }
    }
    int globalSum = 1;
    for (int i = 0; i < THREADSIZE; i++)
    {
        int* r;
        if(pthread_join(th[i], (void**) &r) != 0)
        {
            perror("Error while operating the thread\n");
        }
        globalSum = globalSum * (*r);
        free(r);
    }
    printf("Global multiplication result is: %d\n", globalSum);
    return 0;
}