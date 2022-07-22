//                       UNIT CONVERTER

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"


int main (){
    char contFlag = 'y';
    int operation;
    system("color 0a");
    while (contFlag == 'y')
    {
        printf(WHT "\n\n\t\t==========WELCOME TO THE UNIT CONVERTER==========\n" RESET);
        printf(GRN "\n1.Mass " RESET);
        printf(BLU "\n2.Length " RESET);
        printf(CYN "\n3.Time " RESET);
        printf(RED "\n4.Temprature " RESET);
        printf(YEL "\n5.Electric Current " RESET);
        printf(MAG "\n6.Amount of matter " RESET);
        printf(GRN "\n7.Luminosity \n\n" RESET);
        printf(WHT "Please chose the measurement unit:\t" RESET);
        scanf("%d", &operation);
        printf("%d", operation);

        switch(operation)
        {
            case 1:
                massConversion();
                break;
            case 2:
                lenghtConversion();
                break;
            case 3:
                timeConversion();
                break;
            case 4:
                tempratureConversion();
                break;
            case 5:
                currentConversion();
                break;
            case 6:
                matterConversion();
                break;
            case 7:
                luminosityConversion();
                break;
            default:
                printf(RED "\nOpps you hit the wrong keys\nPlease select from 1 to 7 !!"  RESET)
        }

        printf("\n\nDo you want to continue? [ y / n ] ----> ");
        scanf("%s", &contFlag);
    }



    return 0;
}
