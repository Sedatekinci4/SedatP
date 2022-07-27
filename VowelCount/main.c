#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char *s;
    int i, charNum, vowelNum = 0;
    printf("Please enter the string you want to count the vowels inside of it:\t");
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    charNum = strlen(s);
    printf("%s -- is your string     \n%d is your char count;\n", s, charNum);
    for(i = 0; i <= charNum; i++)
    {
        printf("%c", *s);

    if (*s == 'u' || *s == 'U' || *s == 'I' || *s == 'i' || *s == 'e' || *s == 'E' || *s == 'a' || *s == 'A' || *s == 'o' || *s == 'O')
    {
        vowelNum += 1;
    }
    s += 1;
    }
    printf("\n\n\tVowel count of this string is %d\n\n", vowelNum);
    return 0;
}

