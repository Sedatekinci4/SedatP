#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ENTER 13
#define TAB 9
#define BACKSPACE 8

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void input(char ch[50]);
void inputPassword(char pwd[50]);

struct user
{
    char name[50];
    char phone[50];
    char email[50];
    char username[50];
    char password[50];
};

int main(){
    system("color 0a");
    FILE *fp;
    struct user user;
    char password2[50];
    int option, userCheck = 0;

    printf(GRN "\n\n\t\t\t--------WELCOME TO THE AUTHENTICATION PAGE---------\n" RESET);
    printf(BLU "\nPlease choose operation:"  RESET);
    printf(CYN "\n1.Signup"  RESET);
    printf(CYN "\n2:Login"  RESET);
    printf(CYN "\n3.Exit"  RESET);
    printf(YEL "\n\nPlease enter your choice: "  RESET);
    scanf("%d", &option);
    fgetc(stdin);

    switch(option)
    {
        case 1:
            system("cls");
            printf(YEL "Please enter your name:\t"  RESET);
            input(user.name);
            printf(YEL "Please enter your e phone number:\t"  RESET);
            input(user.phone);
            printf(YEL "Please enter your email:\t"  RESET);
            input(user.email);
            printf(YEL "Please enter your username:\t"  RESET);
            input(user.username);
            printf(YEL "Please enter your password:\t"  RESET);
            inputPassword(user.password);
            printf(YEL "\nPlease confirm your password:\t" RESET);
            inputPassword(password2);

            if(! strcmp(user.password, password2))
            {
                fp = fopen("Users.dat", "a+");
                fwrite(&user, sizeof(struct user),1, fp);
                if(fwrite != 0) printf(GRN "\n\nUser registration success!! "  RESET);
                else printf(RED "\n\nOpps, something wrong!!" RESET);
                fclose(fp);
            }
            else
            {
                printf("Password does not matched, please be careful!");
                Beep(750, 350);
            }
        break;

        case 2:
            char usrName[50], pword[50];
            struct user userlog;

            printf(YEL "\nPlease enter your username:\t"  RESET);
            input(usrName);
            printf(YEL "\nPlease enter your password:\t"  RESET);
            inputPassword(pword);


            fp = fopen("Users.dat", "r");
            while(fread(&userlog, sizeof(struct user), 1 , fp))
            {
                if(!strcmp(userlog.username, usrName))
                {
                    printf("Done");
                    if(!strcmp(userlog.password, pword))
                    {
                        system("cls");
                        printf(CYN "\n\t\t\t\t\t\tWelcome %s"  RESET,userlog.name);
						printf(CYN  "\n\n|Full Name:\t%s"  RESET,userlog.name );
						printf(CYN  "\n|Email:\t\t%s"  RESET, userlog.email);
						printf(CYN  "\n|Username:\t%s"  RESET, userlog.username);
						printf(CYN  "\n|Contact no.:\t%s"  RESET, userlog.phone);
                    }
                    else
                    {
                        printf(RED "\n\n INVALID PASSWORD!!");
                        Beep(800,250);
                    }
                    userCheck = 1;
                }
            }
            if(!userCheck)
            {
                printf(RED "\n\nSorry, User could not found"  RESET);
                Beep(800,250);
            }
            fclose(fp);
            break;

        case 3:
            printf(GRN "\n\t\tBye Bye :)"  RESET);
            return 0;
    }
    return 0;
}

void input(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

void inputPassword(char pwd[50])
{
    int i;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch == ENTER || ch == TAB)
        {
            pwd[i] = '\0';
            break;
        }
        else if(ch == BACKSPACE)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else
        {
            pwd[i++] = ch;
            printf("* \b");
        }
    }
}
