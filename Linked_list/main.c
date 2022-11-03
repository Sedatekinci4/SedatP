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
void delete_element(Node** node, int value);
void reverse_list(Node** root);
void print_list(Node* root);

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

void delete_element(Node** root, int value){
    if(*root == NULL)
    {
        return;
    }
    if((*root)->val == value)
    {
        Node* temp = *root;
        *root = (*root)->next;
        free(temp);
        return;
    }

    for(Node* curr = *root; curr->next != NULL; curr = curr->next)
    {
        if(curr->next->val == value)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
    }
}

void reverse_list(Node** root){
    printf("REVERSED\n\n");
    Node* curr = *root;
    Node* back_ptr = NULL;
    while(curr != NULL)
    {
        Node* forward_ptr = curr->next;
        curr->next = back_ptr;
        back_ptr = curr;
        curr = forward_ptr;
    }
    *root = back_ptr;
}

void print_list(Node* root){
    int count = 0;
    for(Node* curr = root; curr != NULL; curr = curr->next )
    {
        count++;
        printf("%d\n", curr->val);
    }
    printf("\nThe total number of elements in that linked list is -> %d\n", count);
}

int main(){
    Node* root = NULL;

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
    print_list(root);

    /*delete_element(&root, 1);
    delete_element(&root, 10);
    delete_element(&root, 5);*/

    printf("\n----------------------------\n");
    reverse_list(&root);
    print_list(root);


    deallocate(&root);
    return 0;
}
