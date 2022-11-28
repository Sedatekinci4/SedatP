#include <stdio.h>

#define BINARY 8

void push(int data);
int pop();
void printStack();
int isFull();
int isEmpty();
void toDecimal(int num);

int first = -1;
int binary_arr[8];

int main(){
    int num;
    printf("Please enter the decimal number to convert to binary :");
    scanf("%d", &num);
    toDecimal(num);
    printStack();


    return 0;
}

void toDecimal(int num){
    int count = 0;
    while(num != 0)
    {
        push(num % 2);
        num = num / 2;
        count++;
    }
    for(int i = count; i < 8; i++)
    {
        push(0);
    }

}

void printStack(){
    printf("\n-----------BINARY EQUIVALENT-------------\n");
    for(int i = 0; i < 8; i++)
    {
        printf("%d ", binary_arr[i]);
    }
    printf("\n");
}

void push(int data){
    if(isFull())
    {
        printf("\nStack overflow!!!\nCan not add the data to the stack!\n");
        return;
    }
    first++;
    for(int i = first; i>0; i--)
    {
        binary_arr[i] = binary_arr[i-1];
    }
    binary_arr[0] = data;
    printf("%d added to the stack\n", data);
}

int pop(){
    if(isEmpty())
    {
        printf("\nStack underflow!!!\nThe stack is already empty!!\n");
        exit(1);
    }
    int data = binary_arr[0];
    for(int i = 0; i<first; i++)
    {
        binary_arr[i] = binary_arr[i+1];
    }
    binary_arr[first] = 0;
    first--;
    return data;
}

int isFull(){
    if(first >= BINARY-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(first == -1)
        return 1;
    else
        return 0;
}
