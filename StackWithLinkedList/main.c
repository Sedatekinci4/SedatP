#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

int isEmpty(Node* root);
void push(Node** root, int value);
int pop(Node** root);
void print_list(Node* root);

void push(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Warning, no memory location left!\n");
        exit(1);
    }
    new_node->val = value;
    if(*root == NULL)
    {
        *root = new_node;
        new_node->next = NULL;
        return;
    }
    new_node->next = *root;
    *root= new_node;
}

int pop(Node** root)
{
    if(isEmpty(*root))
    {
        printf("\n\nStack underflow!!!\n");
        exit(1);
    }
    int data;
    data = (*root)->val;
    Node* curr = *root;
    *root = (*root)->next;
    free(curr);
    return data;
}

int isEmpty(Node* root){
    if(root == NULL)
        return 1;
    else
        return 0;
}

void print_list(Node* root){
    int count = 0;
    printf("\n");
    for(Node* curr = root; curr != NULL; curr = curr->next )
    {
        count++;
        printf("%d\n", curr->val);
    }
    printf("\nThe total number of elements in that linked list is -> %d\n", count);
}

int main()
{
    Node* root = NULL;
    push(&root, 1);
    push(&root, 2);
    push(&root, 3);
    push(&root, 4);
    push(&root, 5);
    print_list(root);
    pop(&root);
    pop(&root);
    print_list(root);
    return 0;
}
