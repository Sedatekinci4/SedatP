#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
} Node;

void add_to_the_end(Node** root, int value);
void deallocate(Node** root);
void add_to_the_beginning(Node** root, int value);
void add_after_element(Node* node, int value);
void sorted_add(Node** root, int value);

void add_to_the_end(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(1);
    }
    new_node->next = NULL;
    new_node->val = value;

    if(*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
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

void add_to_the_beginning(Node** root, int value){
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL){
        exit(2);
    }
    new_node->val = value;
    new_node->next = *root;

    *root= new_node;
}

void add_after_element(Node* node, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(5);
    }
    new_node->val = value;
    new_node->next = node->next;
    node->next = new_node;
}

void sorted_add(Node** root, int value){
    if(*root == NULL || ((*root)->val >= value))
    {
        add_to_the_beginning(root, value);
        return;
    }

    Node* curr = *root;
    while(curr->next != NULL)
    {
        if(curr->next->val >= value)
        {
            add_after_element(curr, value);
            return;
        }
        curr= curr->next;
    }
    add_to_the_end(&curr, value);
}

int main(){
    Node* root = NULL;
    int count;

    /*add_to_the_beginning(&root, 3);
    add_to_the_beginning(&root, 2);
    add_to_the_beginning(&root, 1);
    add_to_the_end(&root, 4);
    add_after_element(root->next, 8);
    add_to_the_end(&root, 5);
    add_to_the_end(&root, 6);*/

    sorted_add(&root, 2);
    sorted_add(&root, 1);
    sorted_add(&root, 5);
    sorted_add(&root, 7);
    sorted_add(&root, 10);
    sorted_add(&root, 4);

    for(Node* curr = root; curr != NULL; curr = curr->next )
    {
        count++;
        printf("%d\n", curr->val);
    }
    printf("\nThe total number of elements in that linked list is -> %d\n", count);

    deallocate(&root);
    return 0;
}
