This is just an exxample how a program can prints its own sorce code.

EXAMPLE OUTPUT
------------------------------------------------------------------------
```diff
#include <stdio.h>

int main(){
    FILE *fp;
    char c;

    fp = fopen(__FILE__, "r");

    while( (c = getc(fp)) != EOF)
    {
        putchar(c);
    }

    fclose(fp);

    return 0;
}

Process returned 0 (0x0)   execution time : 0.023 s
Press any key to continue.

