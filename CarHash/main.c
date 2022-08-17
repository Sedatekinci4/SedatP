
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define TABLE_VALUE 15
#define MAX_STR 128
#define DELETED_NODE (car*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct
{
    char brand[MAX_STR];
    int year;
    char color[MAX_STR];
    float price;
}car;

car *hash_table[TABLE_VALUE];

unsigned int hash(char *brand)
{
    int length = strnlen(brand, MAX_STR);
    unsigned int hash_value = 0;
    for(int i = 0; i < length ; i++)
    {
        hash_value += brand[i];
        hash_value = hash_value* brand[i];
    }
    return hash_value % TABLE_VALUE;
}

bool init_hash_table()
{
    for(int i = 0; i < TABLE_VALUE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("\n-------START-------\n");
    for(int i = 0; i < TABLE_VALUE; i++)
    {
        if(hash_table[i] == NULL)
        {
            printf("\t%i\t-----\n", i);
        }
        else if(hash_table[i]== DELETED_NODE)
        {
            printf("\t%i\t-----deleted\n", i);
        }
        else
        {
            printf("\t%i\t%s\n",i, hash_table[i]->brand);
        }
    }
    printf("-------END-------\n\n");
}

bool hash_table_insert(car *p)
{
    if(p == NULL) return false;
    int index = hash(p->brand);
    for(int i = 0; i < TABLE_VALUE; i++)
    {
        int try = (i + index) % TABLE_VALUE;
        if(hash_table[try] == NULL ||
           hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

car *hash_table_lookup(char *brand)
{
    int index = hash(brand);
    for(int i = 0; i < TABLE_VALUE; i++)
    {
        int try = (index + i) % TABLE_VALUE;
        if(hash_table[try] == NULL)
        {
            return false;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->brand, brand, TABLE_VALUE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

car *hash_table_delete(char *brand)
{
    int index = hash(brand);
    for(int i = 0; i < TABLE_VALUE; i++)
    {
        int try = (index + i) % TABLE_VALUE;
        if(hash_table[try] == NULL)
        {
            return NULL;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->brand, brand, TABLE_VALUE) == 0)
        {
            car *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main(){

    init_hash_table();
    print_table();

    car BMW = {.brand = "BMW", .year=22, .color = "Black", .price = 750.300};
    car Mercedes = {.brand = "Mercedes", .year=18, .color = "Red", .price = 550.300};
    car Volvo = {.brand = "Volvo", .year=35, .color = "Blue", .price = 670.350};
    car Hyundai = {.brand = "Hyundai", .year=45, .color = "Green", .price = 150.000};
    car Opel = {.brand = "Opel", .year=81, .color = "Purple", .price = 245.450};
    car Ford = {.brand = "Ford", .year=7, .color = "Cyan", .price = 55.250};
    car Nissan = {.brand = "Nissan", .year=14, .color = "Yellow", .price = 400.500};
    car Wolksvagen = {.brand = "Wolksvagen", .year=14, .color = "Orange", .price = 330.300};
    car Wolksvagen = {.brand = "", .year=14, .color = "Orange", .price = 330.300};

    hash_table_insert(&BMW);
    hash_table_insert(&Mercedes);
    hash_table_insert(&Volvo);
    hash_table_insert(&Hyundai);
    hash_table_insert(&Opel);
    hash_table_insert(&Ford);
    hash_table_insert(&Nissan);
    hash_table_insert(&Wolksvagen);
    print_table();

    car *tmp = hash_table_lookup("Mercedes");
    printf("\nSearching for a Mercedes.....\n\n");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->brand);
        printf("The age of the car is %d.\n", tmp->year);
        printf("The color of the car is %s.\n", tmp->color);
        printf("The price of the car is %.3lf\n", tmp->price);
    }

    tmp = hash_table_lookup("Tesla");
    printf("\nSearching for a Tesla.....\n\n");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->brand);
        printf("The age of the car is %d.\n", tmp->year);
        printf("The color of the car is %s.\n", tmp->color);
        printf("The price of the car is %.3lf\n", tmp->price);
    }

    hash_table_delete("Volvo"); printf("Deleting....\nVolvo deleted!\n");
    hash_table_delete("Hyundai"); printf("Deleting....\nHyundai deleted!\n");
    tmp = hash_table_lookup("Volvo");
    printf("\nSearching for a Volvo.....\n\n");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->brand);
        printf("The age of the car is %d.\n", tmp->year);
        printf("The color of the car is %s.\n", tmp->color);
        printf("The price of the car is %.3lf\n", tmp->price);
    }
    print_table();
    hash_table_delete("Opel"); printf("Deleting....\nOpel deleted!\n");

    tmp = hash_table_lookup("BMW");
    printf("\nSearching for a BMW.....\n\n");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n", tmp->brand);
        printf("The age of the car is %d.\n", tmp->year);
        printf("The color of the car is %s.\n", tmp->color);
        printf("The price of the car is %.3lf\n", tmp->price);
    }
    print_table();

    /*printf("BMW => %u\n", hash("BMW"));
    printf("Mercedes => %u\n", hash("Mercedes"));
    printf("Opel => %u\n", hash("Opel"));
    printf("Volvo => %u\n", hash("Volvo"));
    printf("Hyundai => %u\n", hash("Hyundai"));
    printf("Wolksvagen => %u\n", hash("Wolksvagen"));
    printf("Ford => %u\n", hash("Ford"));
    printf("Renault => %u\n", hash("Renault"));*/
    return 0;
}
