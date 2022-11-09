#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* previous;
}Node;

void add_to_end(Node** root, int value);
void add_to_beginning(Node** root, int value);
void add_after_element_value(Node** root, int element_val, int value);
void add_to_certain_position(Node** root, int pos, int value);
void add_after_element(Node* node, int value);
void delete_element(Node** root, int element_val);
void delete_from_certain_position(Node** root, int pos);
void sorted_add(Node** root, int value);
void reverse_list(Node** root);
void deallocate(Node** root);
void print_list(Node* root);

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
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(4);
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

void add_after_element(Node* node, int value){
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL)
    {
        exit(5);
    }
    new_node->val = value;
    new_node->next = node->next;
    node->next = new_node;
    new_node->previous = node;
}

void delete_element(Node** root, int element_val){
    if(*root == NULL)
    {
        return;
    }
    if((*root)->val == element_val)
    {
        Node* temp = *root;
        (*root)->next->previous = NULL;
        *root = (*root)->next;
        free(temp);
        return;
    }
    Node* curr = *root;
    while(curr->next->val != element_val)
    {
        curr = curr->next;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    if(temp->next == NULL)
    {
        free(temp);
        return;
    }
    temp->next->previous = curr;
    free(temp);
}

void delete_from_certain_position(Node** root, int pos){
    if(*root == NULL)
    {
        return;
    }
    int count = 0;
    for(Node* curr = *root; curr != NULL; curr = curr->next )
    {
        count++;
    }
    if(pos-1 > count)
    {
        printf("\n\n---------------WARNING---------------\n----You cannot delete from this location, because it's more than the last element of the linked list!!!\n");
        return;
    }
    if(pos == 1)
    {
        Node* temp = *root;
        (*root)->next->previous = NULL;
        *root = (*root)->next;
        free(temp);
        return;
    }
    Node* curr = *root;
    pos--;
    while(pos != 1)
    {
        curr = curr->next;
        pos--;
    }
    Node* temp = curr->next;
    curr->next = temp->next;
    if(temp->next == NULL)
    {
        free(temp);
        return;
    }
    temp->next->previous = curr;
    free(temp);
}

void delete_all_list(Node** root){
    if(*root == NULL)
    {
        return;
    }
    while((*root)->next != NULL)
    {
        Node* curr = *root;
        *root = (*root)->next;
        free(curr);
    }
    free(*root);
    *root = NULL;
}

void sorted_add(Node** root, int value){
    if(*root == NULL || ((*root)->val >= value))
    {
        add_to_beginning(root, value);
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
    add_to_end(&curr, value);
}

void reverse_list(Node** root){
    if(*root == NULL)
    {
        return;
    }
    Node* curr = *root;
    while(curr->next != NULL)
    {
        Node* temp = curr->next;
        curr->next = curr->previous;
        curr->previous = temp;
        curr = curr->previous;
    }
    Node* temp = curr->next;
    curr->next = curr->previous;
    curr->previous = temp;
    *root = curr;
    temp = NULL;
    curr = NULL;
    printf("\n---------------------------\n");
    printf("REVERSED");
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
    printf("LINKED LIST\n---------------\n");
    for(Node* curr = root; curr != NULL; curr = curr->next )
    {
        count++;
        printf("%d\n", curr->val);
    }
    printf("\nThe total number of elements in that linked list is -> %d\n", count);
}

int main(){
    Node* root = NULL;
    /*add_to_end(&root, 5);
    add_to_end(&root, 3);
    add_to_end(&root, 4);
    print_list(root);
    add_to_beginning(&root, 12);
    add_to_beginning(&root, 14);
    add_to_beginning(&root, 52);
    add_after_element_value(&root, 52, 15);
    add_to_certain_position(&root, 8, 16);
    //delete_element(&root, 16);
    delete_from_certain_position(&root, 8);
    print_list(root);
    reverse_list(&root);
    print_list(root);
    printf("\nThe test that shows second element-> %d\n", root->next->next->next->previous->previous->val);
    */
    sorted_add(&root, 5);
    sorted_add(&root, 4);
    sorted_add(&root, 7);
    sorted_add(&root, 15);
    sorted_add(&root, 785);
    sorted_add(&root, 0);
    sorted_add(&root, -3);
    print_list(root);
    printf("\nThe test that shows second element-> %d\n", root->next->next->next->previous->previous->val);


    reverse_list(&root);
    print_list(root);
    printf("\nThe test that shows second element-> %d\n", root->next->next->next->previous->previous->val);

    delete_all_list(&root);
    sorted_add(&root, 785);
    sorted_add(&root, 0);
    sorted_add(&root, 3);
    sorted_add(&root, 5);
    sorted_add(&root, -7);
    print_list(root);
    printf("\nThe test that shows second element-> %d\n", root->next->next->next->previous->previous->val);


    deallocate(&root);
    return 0;
}
