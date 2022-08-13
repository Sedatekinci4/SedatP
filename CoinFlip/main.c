#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef enum coin {HEADS, TAILS} coin;

coin flipCoin(void);

int main(){
    char answer = 'y';
    int tails = 0, heads = 0 , num = 0, allflips = 0;

    srand(time(NULL));

    printf("%d", num);
    do
    {

        printf("Flipping the coin...\n");
        if (flipCoin() == HEADS)
        {
            printf("HEADS\n");
            heads++;
        }
        else
        {
            printf("TAILS\n");
            tails++;
        }
        allflips++;
        printf("\n\nDo you want to flip the coin? [ y / n ]  --------> ");
        scanf(" %c", &answer);

    }while(answer == 'y' || answer == 'Y');

    printf("\nThe final heads number is: %d\nThe final tails number is: %d\nThe flip count is        : %d\n\n", heads, tails, allflips);
    printf("\nThe final heads number is: %d\nThe final tails number is: %d\nThe flip count is        : %d\n\n", heads, tails, allflips);
    getchar();
    return 0;
}

coin flipCoin()
{
  if (rand() % 2 == 0) return HEADS;
  else return TAILS;
}
