#include <stdio.h>

int main ()
{
    char ch, str[1000];

    printf("Please enter your string to transform:\n");
    gets(str);

    int i = 0;
    while (str[i] != '\0')
    {
        ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
            str[i] = str[i] + 32;
        else if (ch >= 'a' && ch <= 'z')
            str[i] = str[i] - 32;
        i++;
    }

    printf("%s\n", str);

    return 0;
}
