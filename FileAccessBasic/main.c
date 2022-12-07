#include <stdio.h>
#include <stdbool.h>

int main(){
    FILE *fh_out;

    fh_out = fopen("io.txt", "w");

    //fputs("abc", fh_out);
    //fputs("123\n", fh_out);
    //fputs("A string\n", fh_out);

    //int data = 5;
    //fprintf(fh_out, "data: %d\n", data);

    //for(int i = 0; i < 10; i++)
    //{
    //    fprintf(fh_out, "%d\n", i);
    //}

    int input = 0;
    while(true)
    {
        printf("Enter # (-1 quits): ");
        scanf("%d", &input);
        if(input == -1) break;
        else fprintf(fh_out, "%d\n", input);
    }
    fclose(fh_out);

    FILE *fh_in;
    fh_in = fopen("io.txt", "r");

    int finput = 0;
    int lines = 0;
    int numbers[100];  //input buffer

    while(fscanf(fh_in, "%d", &finput) != EOF)
    {
        numbers[lines] = finput;
        printf("File line %d: %d\n", lines+1, finput);
        lines++;
    }

    int total = 0;
    for(int i = 0; i< lines; i++)
    {
        total += numbers[i];
    }
    printf("Average: %d\n", total/lines);

    fclose(fh_in);

    return 0;
}
