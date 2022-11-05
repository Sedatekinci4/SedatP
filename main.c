#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void add_to_the_end(Node** root, int value){
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

void add_to_the_beginning(Node** root, int value){
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
    add_to_the_end(&root, 5);
    add_to_the_end(&root, 3);
    add_to_the_end(&root, 4);
    print_list(root);
    add_to_the_beginning(&root, 12);
    add_to_the_beginning(&root, 14);
    add_to_the_beginning(&root, 52);
    print_list(root);
    printf("\n%d", root->next->next->next->previous->previous->val);


    deallocate(&root);
    return 0;
}
