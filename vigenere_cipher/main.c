#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 128

int main(){
    int l = 0, j= 0, i = 0;
    char key[MAX_STRING];
    printf("Enter the key:\t");
    fgets(key, sizeof(key), stdin);
    int key_len = strlen(key) - 1;


    printf("Enter the string:\t");
	char s[MAX_STRING];
	fgets(s, sizeof(s), stdin);
	int str_len = strlen(s) - 1;
	char new_key[str_len];


    for(i = 0, j = 0; i < str_len; ++i, ++j){
        if(j == key_len)
            j = 0;

        new_key[i] = key[j];
    }
    new_key[i] = '\0';
    //for converting every key to lower case
	while(new_key[l]!='\0')
	{
	    if(islower(new_key[l]))
	        new_key[l]= toupper(new_key[l]);
	    l++;
	}
	printf("%s", new_key);
	l = 0;
    while(s[l]!='\0')
	{
	    if(islower(s[l]))
	        s[l]= toupper(s[l]);
	    l++;
	}
	printf("%s", s);


    char encrypted[str_len], decrypted[str_len];
    //encryption
    for(i = 0; i < str_len; ++i){
        encrypted[i] = ((s[i] + new_key[i]) % 26) + 'A';
        printf("%c \n", s[i]);
        printf("%c \n", new_key[i]);}
    encrypted[i] = '\0';

    //decryption
    for(i = 0; i < str_len; ++i)
        decrypted[i] = (((encrypted[i] - new_key[i]) + 26) % 26) + 'A';

    decrypted[i] = '\0';

    printf("Original Message: %s", s);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", new_key);
    printf("\nEncrypted Message: %s", encrypted);
    printf("\nDecrypted Message: %s", decrypted);

    return 0;
}
