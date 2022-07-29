#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    char *s;
    int i, charNum, consonantCount = 0;
    char word[20];

    printf("Please enter the word you want to see the pig latin equivalent to:\t");
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    charNum = strlen(s);
    printf("\n=============== String and char number ===============\n");
    printf("%s     %d\n", s, charNum);

    printf("\n\n=============== PIG LATIN EQUIVALENT ===============\n");

    if (*s == 'u' || *s == 'U' || *s == 'I' || *s == 'i' || *s == 'e' || *s == 'E' || *s == 'a' || *s == 'A' || *s == 'o' || *s == 'O')
    {
        printf("%s", s);printf("-ay\n\n");
    }
    else
    {
        for(i = 0; i <= charNum; i++)
        {
            if (*s == 'u' || *s == 'U' || *s == 'I' || *s == 'i' || *s == 'e' || *s == 'E' || *s == 'a' || *s == 'A' || *s == 'o' || *s == 'O')
            break;
            else
            {
                word[i] = *s;
                consonantCount++;
            }
            s += 1;

        }
        printf("%s-", s);
        for(i = 0 ; i < consonantCount; i++)
        {
            printf("%c", word[i]);
        }
        printf("ay\n\n");
    }
    return 0;
}
