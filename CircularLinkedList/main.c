#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void add_to_end(Node** tail, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->val = value;
    if(*tail == NULL)
    {
        new_node->next = new_node;
        *tail = new_node;
        return;
    }
    new_node->next = (*tail)->next;
    (*tail)->next = new_node;

    *tail = new_node;
}

void add_to_beginning(Node** tail, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->val = value;
    if(*tail == NULL)
    {
        new_node->next = new_node;
        *tail = new_node;
        return;
    }
}

void print_list(Node* tail){
    int count = 0;
    printf("\n");

    printf("\nThe total number of elements in that linked list is -> %d\n", count);
}


int main()
{
    Node* tail = NULL;
    add_to_end(&tail, 1);
    add_to_end(&tail, 2);
    add_to_end(&tail, 3);
    add_to_end(&tail, 4);
    add_to_end(&tail, -5);
    printf("%d\n", tail->val);
    printf("%d\n", tail->next->val);
    printf("%d\n", tail->next->next->val);
    printf("%d\n", tail->next->next->next->val);
    printf("%d\n", tail->next->next->next->next->val);
    return 0;
}
