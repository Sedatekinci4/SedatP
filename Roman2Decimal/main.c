#include <stdio.h>

static int roman2dec(char c){
    switch (c)
    {
    case 'I':
        return 1; 
        break;
    case 'V':
        return 5; 
        break;
    case 'X':
        return 10; 
        break;
    case 'L':
        return 50; 
        break;
    case 'C':
        return 100; 
        break;
    case 'D':
        return 500; 
        break;
    case 'M':
        return 1000; 
        break;
    default:
        return 0;
        break;
    }
}

int converter(char *st){
    char ch;
    int i = 1;
    int num = roman2dec(st[0]);
    for (i = 1; st[i] != '\0'; i++)
    {
        int prev_num = roman2dec(st[i-1]);
        int curr_num = roman2dec(st[i]);
        if(prev_num < curr_num){
            num = num - prev_num + (curr_num - prev_num);
        }
        else{
            num += curr_num;
        }
    }
    return num;
}

int main(){
    char ch, str[100];
    int answer = 0;

    printf("Please enter the roman number that you want to convert to the decimal:\t");
    gets(str);
    answer = converter(str);

    printf("Your roman number:\t");
    puts(str);
    printf("Your decimal equivalent of it:\t%d", answer);

    return 0;
}