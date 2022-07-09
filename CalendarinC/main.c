#include <stdio.h>
#include <stdlib.h>

int get_first_day(int year);

int main()
{
    int year, month, daysInMonth, day, weekDay = 0, startingDay
    , monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31,  30, 31, 30, 31};
    char *months[] = {"January", "February", "March","April", "May", "June"
                      ,"July", "August", "September", "October", "November"
                      ,"December"};
    system("Color 4F");
    printf("Enter your desired year:");
	scanf("%d", &year);
    while(year < 0){
        printf("Please input a year correctly || EX= 1997, 2020 etc.\n");
        scanf("%d", &year);
    }
    if((year % 4 == 0 && year % 100 == 0) || year % 400 == 0)
        monthDay[1] = 29;

    startingDay = get_first_day(year);

    for(month = 0; month < 12; month++){
        daysInMonth = monthDay[month];
        printf("\n\n---------------%s--------------\n", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        for(weekDay = 0; weekDay < startingDay; weekDay++)
            printf("     ");

        for(day = 1; day <= daysInMonth; day++){
            printf("%5d", day);

            if(++weekDay > 6){
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }
    return 0;
}

int get_first_day(int year)
{
    int d;
    d = (((year - 2) * 365) + ((year - 2) / 4) - ((year - 2) / 100)
           + ((year) / 400) + 1) % 7;
    return d;
}


