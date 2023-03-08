#include <stdio.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void printStack();
void push(int value);
int pop();
int isEmpty();
int isFull();

int main(){
    int choice, data;
    while(1)
    {
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch(choice)
        {
        case 1:
            printf("enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted element is: %d", data);
            break;
        case 3:
            printf("The last element of the stack is: %d", stack_arr[top]);
            break;
        case 4:
            printStack();
            break;
        case 5:
            return 0;
        default:
            printf("\nPlease enter valid operation!!!!\n");
            break;
        }
    }
    return 0;
}

void push(int value){
    if(isFull())
    {
        printf("\nStack overflow!!!\nCouldn't push the data!!!\n\n");
        return;
    }
    top++;
    stack_arr[top] = value;
}

int pop(){
    if(isEmpty())
    {
        printf("\nStack underflow!!!\n");
        exit(1);
    }
    int data;
    data = stack_arr[top];
    top--;
    return data;
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


