#include <stdio.h>

typedef struct complex{
    float real;
    float imaginer;
}complex;

void addComplex(complex a, complex b);
void negateComplex(complex a);
void multiplyComplex(complex a, complex b);
void invertComplex(complex a);

int main(){
    char contFlag = 'y';
    int option;
    complex a, b;

    while(contFlag == 'y' || contFlag == 'Y')
    {
        printf("\n\t\t================== COMPLEX CALCULATOR ==================");
        printf("\n\n1.Add two complex number");
        printf("\n2.Negate two complex number");
        printf("\n3.Multiply two complex number");
        printf("\n4.Inverse a complex number");
        printf("\n\nPlease select the option you want to operate:\t");
        scanf("%d", &option);

        system("cls");
        printf("\nPlease enter the real section of first complex number:\t");
        scanf("%f", &a.real);
        printf("Please enter the imaginary section of first complex number:\t");
        scanf("%f", &a.imaginer);

        if(option == 1 || option == 3)
        {
            printf("\n\nPlease enter the real section of second complex number:\t");
            scanf("%f", &b.real);
            printf("Please enter the imaginary section of second complex number:\t");
            scanf("%f", &b.imaginer);
        }

        switch(option)
        {
            case 1:
                printf("\n\t\t================== Add ==================");
                addComplex(a, b);
                break;
            case 2:
                printf("\n\t\t================== Negate ==================");
                negateComplex(a);
                break;
            case 3:
                printf("\n\t\t================== Multiply ==================");
                multiplyComplex(a, b);
                break;
            case 4:
                printf("\n\t\t================== Inverse ==================");
                invertComplex(a);
                break;
            default:
                printf("\nPLEASE SELECT VALID OPTION!!!");
        }

        printf("\n\nDo you want to continue? [ y / n ]: \t");
        scanf("%s", &contFlag);
        system("cls");
    }
    printf("\n\n\t\tBye Bye!!!!\n\n");
    return 0;
}

void addComplex(complex a, complex b){
    complex temp;
    temp.real = a.real + b.real;
    temp.imaginer = a.imaginer + b.imaginer;
    printf("\n\nSum of these two complex numbers is (%.2f)+(%.2fi)", temp.real, temp.imaginer);
    printf("\n\t\tProcess;\n[(%.2f)+ (%.2fi)] + [(%.2f)+ (%.2fi)] = [(%.2f)+ (%.2fi)]", a.real, a.imaginer, b.real, b.imaginer, temp.real, temp.imaginer);
}

void negateComplex(complex a){
    complex temp;
    temp.real = -a.real;
    temp.imaginer = -a.imaginer;
    printf("\n\nNegation of this complex number is (%.2f)+(%.2fi)", temp.real, temp.imaginer);
}

void multiplyComplex(complex a, complex b){
    complex temp;
    temp.real = (a.real * b.real) - (a.imaginer * b.imaginer);
    temp.imaginer = (a.real * b.imaginer) + (b.real * a.imaginer);
    printf("\n\nSum of these two complex numbers is (%.2f)+(%.2fi)", temp.real, temp.imaginer);
    printf("\n\t\tProcess;\n[(%.2f)+ (%.2fi)] + [(%.2f)+ (%.2fi)] = [(%.2f)+ (%.2fi)]", a.real, a.imaginer, b.real, b.imaginer, temp.real, temp.imaginer);
}

void invertComplex(complex a){
    complex temp;
	temp.real = a.real / (a.real * a.real + a.imaginer * a.imaginer);
	temp.imaginer = (- a.imaginer) / (a.real * a.real + a.imaginer * a.imaginer);
	printf("\n\nInvert of this complex number is (%.2f)+(%.2fi)", temp.real, temp.imaginer);
}
