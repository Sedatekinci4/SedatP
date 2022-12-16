#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void digit_randomizer(char *pword, int j);
void lower_randomizer(char *pword, int j);
void upper_randomizer(char *pword, int j);
void symbol_randomizer(char *pword, int j);

int main(){
    printf("Length:\t");

    int length;
    scanf("%d", &length);

    if(length <= 0)
    {
        printf("Password length must be >= 1!");
        return 1;
    }

    char *password = malloc(length + 1);

    srand(time(NULL)* getpid());

    for(int i = 0; i < length; i++)
    {
        int char_type = rand() % 4;

        if (char_type == 0)
            digit_randomizer(password, i);
        else if (char_type == 1)
            lower_randomizer(password, i);
        else if (char_type == 2)
            upper_randomizer(password, i);
        else if (char_type == 3)
            symbol_randomizer(password, i);
    }

    password[length] = '\0';

    printf("Password:\t%s\n", password);

    free(password);

    return 0;
}

void digit_randomizer(char *pword, int j)
{
    char *digits = "0123456789";
    int digits_length = strlen(digits);
    pword[j] = digits[rand() % digits_length];
}

void lower_randomizer(char *pword, int j)
{
    char *lowers = "abcdefghijklmnopqrstuvwxyz";
    int lowers_length = strlen(lowers);
    pword[j] = lowers[rand() % lowers_length];
}

void upper_randomizer(char *pword, int j)
{
    char *uppers = "ABCDEFGHÝJKLMNOPQRSTUVWXYZ";
    int uppers_length = strlen(uppers);
    pword[j] = uppers[rand() % uppers_length];
}

void symbol_randomizer(char *pword, int j)
{
    char *symbols = "!@#$%^/()*";
    int symbols_length = strlen(symbols);
    pword[j] = symbols[rand() % symbols_length];
}
