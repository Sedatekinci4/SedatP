#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAXSTRING 50

int main(){
    char str[MAXSTRING];
    int i, len, temp=0;
    int flag = 0;
    printf("Enter a string: ");scanf("%s", str);
    len = strlen(str);
    for(i=0;i < len ;i++)
	{
        if(str[i] != str[len-i-1])
		{
            temp = 1;
        break;
		}
	}
    
    if (temp==0) 
	{
        printf("String is a palindrome");
    }    
    else 
	{
        printf("String is not a palindrome");
    }
    return 0;
} 
