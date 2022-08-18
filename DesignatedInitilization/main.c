#include <stdio.h>

int main(){
    int arry[10] = { [5] = 5, [8] = 8};
    struct str{
        int first;
        int second;
    };

    struct str designated = { .first = 1 , .second = 2};
    printf("\n DESIGNATED ARRAY INIT\n");
    for(int i = 0; i < 10 ; i++)
        printf("%d\n", arry[i]);
    printf("\nDESIGNATED STRUCT INIT\n    %d   %d\n", designated.first, designated.second);

    return 0;
}
