#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHAR 100

int word_occurence(char *string, char *word);
void word_cencoration(char *string, char *word);

int main(){
    FILE *fp;
    char s[MAX_CHAR];
    char curse[] = "Fuck ";
    char* cptr;

    fp = fopen("text_file.txt", "r");

    int tx;
    int i = 0;

    while ((tx = fgetc(fp)) != EOF)
    {
        s[i] = tx;
        i++;
    }
    
    printf("%s", s);
    printf("Bad word has been detected, please be nice!!!!!!\n");
    int result = word_occurence(s, curse);

    if(result == 1){

        word_cencoration(s, curse);
    }
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

void word_cencoration(char *string, char *word){
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
            for(k = i + j - wdlen + 1; k < strloop; k++)
            {
                string[k -1] = '*';
            }
        }
    }
}