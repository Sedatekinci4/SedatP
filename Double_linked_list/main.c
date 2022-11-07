#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void add_to_end(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->val = value;
    if(*root == NULL)
    {
        new_node->next = NULL;
        new_node->previous = NULL;
        *root = new_node;
        return;
    }
    Node* curr = *root;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->next = NULL;
    new_node->previous = curr;
}

void add_to_beginning(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(2);
    }
    new_node->val = value;
    if(*root == NULL)
    {
        new_node->next = NULL;
        new_node->previous = NULL;
        *root = new_node;
        return;
    }
    (*root)->previous = new_node;
    new_node->next = *root;
    new_node->previous = NULL;
    *root = new_node;
}

void add_after_element_value(Node** root, int element_val, int value){
    if(*root == NULL)
    {
        return;
    }
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(3);
    }
    new_node->val = value;
    Node* curr = *root;
    while(curr->val != element_val)
    {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = new_node;
    new_node->previous = curr;
    new_node->next = temp;
    temp->previous = new_node;
}

void add_to_certain_position(Node** root, int pos, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(4);
    }
    int count = 0;
    for(Node* curr = *root; curr != NULL; curr = curr->next )
    {
        count++;
    }
    if(pos-1 > count)
    {
        printf("\n\n---------------WARNING---------------\n----You cannot add to this location, because it's more than the last element of the linked list!!!\n");
        return;
    }

    new_node->val = value;
    if(pos == 1)
    {
        new_node->next = *root;
        new_node->previous = NULL;
        (*root)->previous = new_node;
        *root= new_node;
        return;
    }

    Node* curr = *root;
    pos--;
    while(pos != 1)
    {
        curr = curr->next;
        pos--;
    }

    new_node->next = curr->next;
    new_node->previous = curr;
    curr->next = new_node;

}

void deallocate(Node** root){
    Node* curr = *root;
    while(curr != NULL){
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
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

int main(){
    Node* root = NULL;
    add_to_end(&root, 5);
    add_to_end(&root, 3);
    add_to_end(&root, 4);
    print_list(root);
    add_to_beginning(&root, 12);
    add_to_beginning(&root, 14);
    add_to_beginning(&root, 52);
    add_after_element_value(&root, 52, 15);
    add_to_certain_position(&root, 8, 16);
    print_list(root);
    printf("\nThe test that shows second element-> %d\n", root->next->next->next->previous->previous->val);


    deallocate(&root);
    return 0;
}
