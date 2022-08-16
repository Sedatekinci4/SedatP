#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int word_occurence(char *string, char *word);
void word_deletion(char *string, char *word);

int main(){
    char s[] = "This is a string, and it is in this string once. The problem is there is not any problem. LOL ";
    char w[] = " LOL ";

    int result = word_occurence(s, w);
    word_deletion(s, w);

    printf("\nYour word is in the string %d times!!\n", result);
    printf("%s", s);

    return 0;
}

int word_occurence(char *string, char *word){
    int srlen= strlen(string);
    int wdlen = strlen(word);
    int strloop = srlen - wdlen + 1;
    int count = 0;
    int i, j;

    for(i = 0; i < strloop; i++)
    {
        bool wordFound = true;
        for(j = 0; j < wdlen ; j++)
        {
            if( word[j] != string[i + j])
            {
                wordFound = false;
                break;
            }
        }
        if(wordFound)
        {
            count++;
        }
    }
    return count;
}

void word_deletion(char *string, char *word){
    int srlen= strlen(string);
    int wdlen = strlen(word);
    int strloop = srlen - wdlen + 1;
    int i, j, k;

    for(i = 0; i < strloop; i++)
    {
        bool wordFound = true;
        for(j = 0; j < wdlen ; j++)
        {
            if( word[j] != string[i + j])
            {
                wordFound = false;
                break;
            }
        }
        if(wordFound)
        {
            for(k = i + j - wdlen; k < strloop; k++ )
            {
                string[k] = string[k + wdlen];
            }
        }
    }
}
