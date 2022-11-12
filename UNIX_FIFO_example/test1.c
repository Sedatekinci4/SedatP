#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <time.h>

#define ARRSIZE 5

int main(){
    int arr[ARRSIZE];
    srand(time(NULL));
    int i;
    for ( i = 0; i < ARRSIZE; i++)
    {
        arr[i] = rand() % 100;
    }

    int fd = open("sum", O_WRONLY);
    if (fd == -1)
    {
        return 1;
    }
    
    for ( i = 0; i < ARRSIZE; i++)
    {
        if (write(fd, &arr[i], sizeof(int)) == -1)
        {
            return 2;
        }
        printf("Wrote.. %d\n", arr[i]);
    }
    close(fd);

    fd = open("sum", O_RDONLY);
    if (fd == -1)
    {
        return 3;
    }
    int sum = 0;
    if(read(fd, &sum, sizeof(int)) == -1)
    {
        return 4;
    }
    printf("Recieved the sum val --> %d\n", sum);
    close(fd);


    return 0;
}