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

void massConversion();

int main (){
    char contFlag = 'y';
    int operation;
    system("color 0a");
    while (contFlag == 'y' || contFlag == 'Y')
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

        switch(operation)
        {
            case 1:
                massConversion();
                break;
            case 2:
                //lenghtConversion();
                break;
            case 3:
                //timeConversion();
                break;
            case 4:
                //tempratureConversion();
                break;
            case 5:
                //currentConversion();
                break;
            case 6:
                //matterConversion();
                break;
            case 7:
                //luminosityConversion();
                break;
            default:
                printf(RED "\nOpps you hit the wrong keys\nPlease select from 1 to 7 !!"  RESET);
        }

        printf(WHT "\n\nDo you want to continue? [ y / n ] ----> " RESET);
        scanf("%s", &contFlag);
        system("cls");
    }



    return 0;
}

void massConversion()
{
    int massChoice, mConversionChoice;
    float mass, massConv;
    system("cls");
    printf(YEL "\n\n\t\t==========MASS CONVERSÝON==========\n\n" RESET);
    printf(GRN "\n1.Kilogram(kg)");
    printf("\n2.Gram(g)" );
    printf("\n3.Miligram(mg)");
    printf("\n4.Ton(t)");
    printf("\n5.Pound(lbs)");
    printf("\n6.Ounce(oz)");
    printf(WHT "\n\nPlease choose the mass unit you have:\t" RESET);
    scanf("%d", &massChoice);

    printf(WHT "\nPlease enter the amount of unit you have:\t" RESET);
    scanf("%f", &mass);

    switch(massChoice)
    {
        case 1:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass;
                    printf(GRN "\n%.4f kg is equivalent to %.4f kg", mass, massConv);
                    break;
                case 2:
                    massConv = mass *1000;
                    printf(GRN "\n%.4f kg is equivalent to %.4f g", mass, massConv);
                    break;
                case 3:
                    massConv = mass *1000000;
                    printf(GRN "\n%.4f kg is equivalent to %.4f mg", mass, massConv);
                    break;
                case 4:
                    massConv = mass * 0.001;
                    printf(GRN "\n%.4f kg is equivalent to %.4f t", mass, massConv);
                    break;
                case 5:
                    massConv = mass * 2.2046226218;
                    printf(GRN "\n%.4f kg is equivalent to %.4f lbs", mass, massConv);
                    break;
                case 6:
                    massConv = mass * 35.27396195;
                    printf(GRN "\n%.4f kg is equivalent to %.4f oz", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
         case 2:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass * 0.001;
                    printf(GRN "\n%.4f g is equivalent to %.4f kg ", mass, massConv);
                    break;
                case 2:
                    massConv = mass;
                    printf(GRN "\n%.4f g is equivalent to %.4f g ", mass, massConv);
                    break;
                case 3:
                    massConv = mass *1000;
                    printf(GRN "\n%.4f g is equivalent to %.4f mg ", mass, massConv);
                    break;
                case 4:
                    massConv = mass * 0.000001;
                    printf(GRN "\n%.4f g is equivalent to %.4f t ", mass, massConv);
                    break;
                case 5:
                    massConv = mass * 0.0022046226;
                    printf(GRN "\n%.4f g is equivalent to %.4f lbs ", mass, massConv);
                    break;
                case 6:
                    massConv = mass * 0.0352739619;
                    printf(GRN "\n%.4f g is equivalent to %.4f oz ", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
        case 3:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass * 0.000001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f kg ", mass, massConv);
                    break;
                case 2:
                    massConv = mass * 0.001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f g ", mass, massConv);
                    break;
                case 3:
                    massConv = mass;
                    printf(GRN "\n%.4f mg is equivalent to %.4f mg ", mass, massConv);
                    break;
                case 4:
                    massConv = mass * 0.000000001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f t ", mass, massConv);
                    break;
                case 5:
                    massConv = mass * 0.0000022046;
                    printf(GRN "\n%.4f mg is equivalent to %.4f lbs ", mass, massConv);
                    break;
                case 6:
                    massConv = mass * 0.000035274;
                    printf(GRN "\n%.4f mg is equivalent to %.4f oz ", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
        case 4:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass * 1000;
                    printf(GRN "\n%.4f t is equivalent to %.4f kg ", mass, massConv);
                    break;
                case 2:
                    massConv = mass * 1000000;
                    printf(GRN "\n%.4f t is equivalent to %.4f g ", mass, massConv);
                    break;
                case 3:
                    massConv = mass * 1000000000;
                    printf(GRN "\n%.4f t is equivalent to %.4f mg ", mass, massConv);
                    break;
                case 4:
                    massConv = mass;
                    printf(GRN "\n%.4f t is equivalent to %.4f t ", mass, massConv);
                    break;
                case 5:
                    massConv = mass * 2204.6226218;
                    printf(GRN "\n%.4f t is equivalent to %.4f lbs ", mass, massConv);
                    break;
                case 6:
                    massConv = mass * 35273.96195;
                    printf(GRN "\n%.4f t is equivalent to %.4f oz ", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
        case 5:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass * 0.45359237;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f kg ", mass, massConv);
                    break;
                case 2:
                    massConv = mass * 453.59237;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f g ", mass, massConv);
                    break;
                case 3:
                    massConv = mass * 453592.37;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f mg ", mass, massConv);
                    break;
                case 4:
                    massConv = mass * 0.0004535924;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f t ", mass, massConv);
                    break;
                case 5:
                    massConv = mass;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f lbs ", mass, massConv);
                    break;
                case 6:
                    massConv = mass * 16;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f oz ", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
        case 6:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &mConversionChoice);

            switch(mConversionChoice)
            {
                case 1:
                    massConv = mass * 0.0283495231;
                    printf(GRN "\n%.4f oz is equivalent to %.4f kg ", mass, massConv);
                    break;
                case 2:
                    massConv = mass * 28.349523125;
                    printf(GRN "\n%.4f oz is equivalent to %.4f g ", mass, massConv);
                    break;
                case 3:
                    massConv = mass * 28349.523125;
                    printf(GRN "\n%.4f oz is equivalent to %.4f mg ", mass, massConv);
                    break;
                case 4:
                    massConv = mass * 0.0000283495;
                    printf(GRN "\n%.4f oz is equivalent to %.4f t ", mass, massConv);
                    break;
                case 5:
                    massConv = mass * 0.0625;
                    printf(GRN "\n%.4f oz is equivalent to %.4f lbs ", mass, massConv);
                    break;
                case 6:
                    massConv = mass;
                    printf(GRN "\n%.4f oz is equivalent to %.4f oz ", mass, massConv);
                    break;
                default:
                    printf("Something wrong. Please try again carefully");
                    break;
            }
            break;
        default:
            printf("Something wrong. Please try again carefully");
            break;
    }
}
