#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define ARRSIZE 5

int main(){
    int arr[ARRSIZE];
    int fd = open("sum", O_RDONLY);
    if (fd == -1)
    {
        return 1;
    }

    int i;
    for (i = 0; i < ARRSIZE; i++)
    {
        if(read(fd, &arr[i], sizeof(int)) == -1)
        {
            return 2;
        }
        printf("Recieved.. %d\n", arr[i]);
    }
    close(fd);

    int sum = 0;
    for (i = 0; i < ARRSIZE; i++)
    {
        sum += arr[i];
    }
    printf("result is --> %d\n", sum);

    fd = open("sum", O_WRONLY);
    if (fd == -1)
    {
        return 3;
    }

    if (write(fd, &sum, sizeof(int)) == -1)
    {
        return 2;
    }
    printf("Wrote the sum val -> %d\n", sum);
    close(fd);   
    
    
    return 0;
}