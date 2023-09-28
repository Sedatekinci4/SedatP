#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CHAR 100

int word_occurence(char *string,  char const *word);
void word_cencoration(char *string,  char const *word);

int main(){
    FILE *fp;
    char s[MAX_CHAR];
    const char *curse[] = {"shit", "fuck"};
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
    printf("\nBad word has been detected, please be nice!!!!!!\n");
    int result = word_occurence(s, curse[0]);

    while(result > 0){

        word_cencoration(s, curse[0]);
        result--;
    }
    printf("%s", s);



    return 0;
}

int word_occurence(char *string, char const *word){
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

void word_cencoration(char *string, char const *word){
    int srlen= strlen(string);
    int wdlen = strlen(word);
    int strloop = srlen - wdlen + 1;
    int i, j, k, wdlen_c = 0;

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
                if(wdlen_c != wdlen){
                    string[k -1] = '*';
                    wdlen_c++;
                }
                else{
                    break;
                }
            }
        }
    }
}