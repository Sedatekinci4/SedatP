#include <stdio.h>

void int_to_binary(int n);

int main(){
    int PORT_A = 0b10101010;
    printf("\nFirst value of PORT A;\n");
    int_to_binary(PORT_A);
    PORT_A |= (0x01 << 2);
    printf("\nAfter setting the bit number 2 of PORT A;\n");
    int_to_binary(PORT_A);
    PORT_A &= ~(0x01 << 1);
    printf("\nAfter clearing the bit number 1 of PORT A;\n");
    int_to_binary(PORT_A);

    return 0;
}

void int_to_binary(int n){
    int a[10], num, i;
    num = n;
    // Loop to calculate and store the binary format
    for (i = 0; n > 0; i++) {
        a[i] = n % 2;
        n = n / 2;
    }
    printf("Integer Format: %d", num);
    printf("\nBinary Format: ");

    // Loop to print the binary format of given number
    for (i = i - 1; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
    printf("\n");
}
