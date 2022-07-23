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
void lengthConversion();

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
                lengthConversion();
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


    printf(CYN "\n\n\t\tBye Bye!!!!\n\n" RESET);
    return 0;
}

void massConversion()
{
    int choice1, choice2;
    float unit, unitConv;
    system("cls");
    printf(YEL "\n\n\t\t========== MASS CONVERSION ==========\n\n" RESET);
    printf(GRN "\n1.Kilogram(kg)");
    printf("\n2.Gram(g)" );
    printf("\n3.Miligram(mg)");
    printf("\n4.Ton(t)");
    printf("\n5.Pound(lbs)");
    printf("\n6.Ounce(oz)");
    printf(WHT "\n\nPlease choose the mass unit you have:\t" RESET);
    scanf("%d", &choice1);

    printf(WHT "\nPlease enter the amount of unit you have:\t" RESET);
    scanf("%f", &unit);

    switch(choice1)
    {
        case 1:
            printf(GRN "\n1.Kilogram(kg)");
            printf("\n2.Gram(g)" );
            printf("\n3.Miligram(mg)");
            printf("\n4.Ton(t)");
            printf("\n5.Pound(lbs)");
            printf("\n6.Ounce(oz)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit;
                    printf(GRN "\n%.4f kg is equivalent to %.4f kg", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit *1000;
                    printf(GRN "\n%.4f kg is equivalent to %.4f g", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit *1000000;
                    printf(GRN "\n%.4f kg is equivalent to %.4f mg", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 0.001;
                    printf(GRN "\n%.4f kg is equivalent to %.4f t", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 2.2046226218;
                    printf(GRN "\n%.4f kg is equivalent to %.4f lbs", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 35.27396195;
                    printf(GRN "\n%.4f kg is equivalent to %.4f oz", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
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
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.001;
                    printf(GRN "\n%.4f g is equivalent to %.4f kg ", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit;
                    printf(GRN "\n%.4f g is equivalent to %.4f g ", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit *1000;
                    printf(GRN "\n%.4f g is equivalent to %.4f mg ", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 0.000001;
                    printf(GRN "\n%.4f g is equivalent to %.4f t ", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0022046226;
                    printf(GRN "\n%.4f g is equivalent to %.4f lbs ", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.0352739619;
                    printf(GRN "\n%.4f g is equivalent to %.4f oz ", unit, unitConv);
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
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.000001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f kg ", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f g ", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit;
                    printf(GRN "\n%.4f mg is equivalent to %.4f mg ", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 0.000000001;
                    printf(GRN "\n%.4f mg is equivalent to %.4f t ", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0000022046;
                    printf(GRN "\n%.4f mg is equivalent to %.4f lbs ", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.000035274;
                    printf(GRN "\n%.4f mg is equivalent to %.4f oz ", unit, unitConv);
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
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 1000;
                    printf(GRN "\n%.4f t is equivalent to %.4f kg ", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 1000000;
                    printf(GRN "\n%.4f t is equivalent to %.4f g ", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 1000000000;
                    printf(GRN "\n%.4f t is equivalent to %.4f mg ", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit;
                    printf(GRN "\n%.4f t is equivalent to %.4f t ", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 2204.6226218;
                    printf(GRN "\n%.4f t is equivalent to %.4f lbs ", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 35273.96195;
                    printf(GRN "\n%.4f t is equivalent to %.4f oz ", unit, unitConv);
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
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.45359237;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f kg ", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 453.59237;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f g ", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 453592.37;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f mg ", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 0.0004535924;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f t ", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f lbs ", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 16;
                    printf(GRN "\n%.4f lbs is equivalent to %.4f oz ", unit, unitConv);
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
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.0283495231;
                    printf(GRN "\n%.4f oz is equivalent to %.4f kg ", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 28.349523125;
                    printf(GRN "\n%.4f oz is equivalent to %.4f g ", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 28349.523125;
                    printf(GRN "\n%.4f oz is equivalent to %.4f mg ", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 0.0000283495;
                    printf(GRN "\n%.4f oz is equivalent to %.4f t ", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0625;
                    printf(GRN "\n%.4f oz is equivalent to %.4f lbs ", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit;
                    printf(GRN "\n%.4f oz is equivalent to %.4f oz ", unit, unitConv);
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

void lengthConversion()
{
    int choice1, choice2;
    float unit, unitConv;
    system("cls");
    printf(YEL "\n\n\t\t========== LENGTH CONVERSION ==========\n\n" RESET);
    printf(BLU "\n1.Meter(m)");
    printf("\n2.Kilometer(km)" );
    printf("\n3.Centimeter(cm)");
    printf("\n4.Milimeter(mm)");
    printf("\n5.Mile(mi)");
    printf("\n6.Yard(yd)");
    printf("\n7.Foot(ft)");
    printf("\n8.Inch(in)");;
    printf(WHT "\n\nPlease choose the mass unit you have:\t" RESET);
    scanf("%d", &choice1);

    printf(WHT "\nPlease enter the amount of unit you have:\t" RESET);
    scanf("%f", &unit);

    switch(choice1)
    {
        case 1:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit;
                    printf(GRN "\n%.4f m is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.001;
                    printf(GRN "\n%.4f m is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 100;
                    printf(GRN "\n%.4f m is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 1000;
                    printf(GRN "\n%.4f m is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0006213689;
                    printf(GRN "\n%.4f m is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 1.0936132983;
                    printf(GRN "\n%.4f m is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 3.280839895;
                    printf(GRN "\n%.4f m is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 39.37007874;
                    printf(GRN "\n%.4f m is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 2:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 1000;
                    printf(GRN "\n%.4f km is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit;
                    printf(GRN "\n%.4f km is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 100000;
                    printf(GRN "\n%.4f km is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 1000000;
                    printf(GRN "\n%.4f km is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.6213688756;
                    printf(GRN "\n%.4f km is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 1093.6132983;
                    printf(GRN "\n%.4f km is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 3280.839895;
                    printf(GRN "\n%.4f km is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 39370.07874;
                    printf(GRN "\n%.4f km is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 3:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.01;
                    printf(GRN "\n%.4f cm is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.00001;
                    printf(GRN "\n%.4f cm is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit;
                    printf(GRN "\n%.4f cm is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 10;
                    printf(GRN "\n%.4f cm is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0000062137;
                    printf(GRN "\n%.4f cm is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.010936133;
                    printf(GRN "\n%.4f cm is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 0.032808399;
                    printf(GRN "\n%.4f cm is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 0.3937007874;
                    printf(GRN "\n%.4f cm is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 4:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.001;
                    printf(GRN "\n%.4f m is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.000001;
                    printf(GRN "\n%.4f m is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 0.1;
                    printf(GRN "\n%.4f m is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit;
                    printf(GRN "\n%.4f m is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0000006213;
                    printf(GRN "\n%.4f m is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.0010936133;
                    printf(GRN "\n%.4f m is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 0.0032808399;
                    printf(GRN "\n%.4f m is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 0.0393700787;
                    printf(GRN "\n%.4f m is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 5:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 1609.35;
                    printf(GRN "\n%.4f mi is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 1.60935;
                    printf(GRN "\n%.4f mi is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 160935;
                    printf(GRN "\n%.4f mi is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 1609350;
                    printf(GRN "\n%.4f mi is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit;
                    printf(GRN "\n%.4f mi is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 1760.0065617;
                    printf(GRN "\n%.4f mi is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 5280.019685;
                    printf(GRN "\n%.4f mi is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 63360.23622;
                    printf(GRN "\n%.4f mi is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 6:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.9144;
                    printf(GRN "\n%.4f yd is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.0009144;
                    printf(GRN "\n%.4f yd is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 91.44;
                    printf(GRN "\n%.4f yd is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 914.4;
                    printf(GRN "\n%.4f yd is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0005681797;
                    printf(GRN "\n%.4f yd is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit;
                    printf(GRN "\n%.4f yd is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 3;
                    printf(GRN "\n%.4f yd is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 36;
                    printf(GRN "\n%.4f yd is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 7:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.3048;
                    printf(GRN "\n%.4f ft is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.0003048;
                    printf(GRN "\n%.4f ft is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 30.48;
                    printf(GRN "\n%.4f ft is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 304.8;
                    printf(GRN "\n%.4f ft is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0001893932;
                    printf(GRN "\n%.4f ft is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.3333333333;
                    printf(GRN "\n%.4f ft is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit;
                    printf(GRN "\n%.4f ft is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit * 12;
                    printf(GRN "\n%.4f ft is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        case 8:
            printf(BLU "\n1.Meter(m)");
            printf("\n2.Kilometer(km)" );
            printf("\n3.Centimeter(cm)");
            printf("\n4.Milimeter(mm)");
            printf("\n5.Mile(mi)");
            printf("\n6.Yard(yd)");
            printf("\n7.Foot(ft)");
            printf("\n8.Inch(in)");
            printf(WHT "\n\nPlease choose the mass unit you want to convert:\t" RESET);
            scanf("%d", &choice2);

            switch(choice2)
            {
                case 1:
                    unitConv = unit * 0.0254;
                    printf(GRN "\n%.4f in is equivalent to %.4f m", unit, unitConv);
                    break;
                case 2:
                    unitConv = unit * 0.0000254;
                    printf(GRN "\n%.4f in is equivalent to %.4f km", unit, unitConv);
                    break;
                case 3:
                    unitConv = unit * 2.54;
                    printf(GRN "\n%.4f in is equivalent to %.4f cm", unit, unitConv);
                    break;
                case 4:
                    unitConv = unit * 25.4;
                    printf(GRN "\n%.4f in is equivalent to %.4f mm", unit, unitConv);
                    break;
                case 5:
                    unitConv = unit * 0.0000157828;
                    printf(GRN "\n%.4f in is equivalent to %.4f mi", unit, unitConv);
                    break;
                case 6:
                    unitConv = unit * 0.0277777778;
                    printf(GRN "\n%.4f in is equivalent to %.4f yd", unit, unitConv);
                    break;
                case 7:
                    unitConv = unit * 0.0833333333;
                    printf(GRN "\n%.4f in is equivalent to %.4f ft", unit, unitConv);
                    break;
                case 8:
                    unitConv = unit;
                    printf(GRN "\n%.4f in is equivalent to %.4f in", unit, unitConv);
                    break;
                default:
                    printf(RED "\n Something wrong. Please try again carefully" RESET);
                    break;
            }
            break;

        default:
            printf("Something wrong. Please try again carefully");
            break;
    }
}
