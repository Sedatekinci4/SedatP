//Printing 1 to 200 without while and for loop
// Using goto statement:

#include <stdio.h>

int main(){
    int i = 0;
    START: i++;
    printf("%d\n", i);
    if(i < 200)
    {
    goto START;
    }

    return 0;
}
