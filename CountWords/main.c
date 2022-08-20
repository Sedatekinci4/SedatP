#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char *s;
    int i, charNum, wordNum = 1;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    charNum = strlen(s);

    for(i = 0; i <= charNum; i++)
    {
        printf("%c", *s);
        if(*s == ' ')
        {
            wordNum++;
        }
        s += 1;
    }

    printf("\n\n\t\tWord count of this string is %d\n\n", wordNum);
    return 0;
}
