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

void add_to_certain_position(Node** tail, int value, int pos){
    int count = 0;
    for(Node* curr = (*tail)->next; curr != *tail; curr = curr->next)
    {
        count++;
    }
    count++;
    printf("\nThe total number of elements in that linked list is -> %d\nThe position you want to add is\t\t\t    -> %d\n", count, pos);
    if(pos-1 > count || pos <= 0 )
    {
        printf("\n\n---------------WARNING---------------\nYou cannot add to this location, because it's more than the last element of the linked list\n\
               Or 0 index is not allowed!!!\n");
        return;
    }
    Node* new_node = malloc(sizeof(Node));
    new_node->val = value;
    if(pos == 1)
    {
        new_node->next = (*tail)->next;
        (*tail)->next = new_node;
        printf("Addition Complete!\n");
        return;
    }
    Node* curr= (*tail)->next;
    pos--;
    if(pos == count)
    {
        add_to_end(tail, value);
        printf("Addition Complete!\n");
        return;
    }
    while(pos != 1)
    {
        curr = curr->next;
        pos--;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    printf("Addition Complete!\n");
}

void print_list(Node* tail){
    if(tail == NULL)
    {
        return;
    }
    int count = 0;
    printf("\n");
    printf("CIRCULAR LINKED LIST\n---------------\n");
    for(Node* curr = tail->next; curr != tail; curr = curr->next)
    {
        printf("%d\n", curr->val);
        count++;
    }
    printf("%d\n", tail->val);
    count++;
    printf("\nThe total number of elements in that linked list is -> %d\n", count);
}

void deallocate(Node** tail){
    Node* curr = (*tail)->next;
    while(curr != *tail){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *tail = NULL;
}


int main()
{
    Node* tail = NULL;
    add_to_end(&tail, 1);
    add_to_end(&tail, 2);
    add_to_end(&tail, 3);
    add_to_end(&tail, 4);
    add_to_end(&tail, 5);
    add_to_end(&tail, 6);
    add_to_certain_position(&tail, 7, 8);
    print_list(tail);
    /*printf("%d\n", tail->next->val);
    printf("%d\n", tail->next->next->val);
    printf("%d\n", tail->next->next->next->val);
    printf("%d\n", tail->next->next->next->next->val);
    printf("%d\n", tail->val);*/
    deallocate(&tail);
    return 0;
}
