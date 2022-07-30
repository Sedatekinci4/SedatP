//Printing 1 to 200 without while and for loop
// Using recursive main:

#include <stdio.h>

int main(){
    static i = 1;
    if(i <= 200)
    {
        printf("%d\n", i++);
        main();
    }
    return 0;
}
