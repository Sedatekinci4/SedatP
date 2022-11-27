#include <stdio.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void printStack();
void push(int value);
void pop();
int isEmpty();
int isFull();

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    pop();
    push(5);
    push(6);
    push(7);
    pop();
    pop();
    push(1);
    push(2);
    push(3);
    pop();
    pop();
    pop();
    pop();
    pop();
    return 0;
}

void push(int value){
    if(isFull())
    {
        printf("\n\nStack overflow!!!\nCouldn't push the data!!!\n\n");
        return;
    }
    top++;
    stack_arr[top] = value;
    printStack();
}

void pop(){
    if(isEmpty())
    {
        printf("\nStack underflow!!!\n");
        exit(1);
    }
    stack_arr[top] = 0;
    top--;
    printStack();
}

int isFull(){
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void printStack(){
    printf("\n---------Stack---------\n");
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack_arr[i]);
    }
}
