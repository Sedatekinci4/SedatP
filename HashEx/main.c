#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#define MAX_TABLE 10
#define MAX_NAME 256
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)

typedef struct
{
    char name[MAX_NAME];
    int age;
}person;

person *hash_table[MAX_TABLE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for(int i = 0; i < length ; i++)
    {
        hash_value += name[i];
        hash_value = hash_value* name[i];
    }
    return hash_value %MAX_TABLE;
}

bool init_hash_table()
{
    for(int i = 0; i < MAX_TABLE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("-------START-------\n");
    for(int i = 0; i < MAX_TABLE; i++)
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
            printf("\t%i\t%s\n",i, hash_table[i]->name);
        }
    }
    printf("-------END-------\n");
}

bool hash_table_insert(person *p)
{
    if(p == NULL) return false;
    int index = hash(p->name);
    for(int i = 0; i <MAX_TABLE; i++)
    {
        int try = (i + index) % MAX_TABLE;
        if(hash_table[try] == NULL ||
           hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }
    return false;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    for(int i= 0; i< MAX_TABLE; i++)
    {
        int try = (index + i) % MAX_TABLE;
        if(hash_table[try] == NULL)
        {
            return false;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->name, name, MAX_TABLE) == 0)
        {
            return hash_table[try];
        }
    }
    return NULL;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    for(int i= 0; i< MAX_TABLE; i++)
    {
        int try = (index + i) % MAX_TABLE;
        if(hash_table[try] ==NULL)
        {
            return NULL;
        }
        if(hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try]->name, name, MAX_TABLE) == 0)
        {
            person *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main(){

    init_hash_table();
    print_table();

    person Sedat = {.name = "Sedat", .age=22};
    person Rumeysa = {.name = "Rumeysa", .age=18};
    person Ege = {.name = "Ege", .age=35};
    person Selim = {.name = "Selim", .age=45};
    person Burak = {.name = "Burak", .age=81};
    person Ferhat = {.name = "Ferhat", .age=7};
    person Anil = {.name = "Anil", .age=14};
    person Emre = {.name = "Emre", .age=14};

    hash_table_insert(&Sedat);
    hash_table_insert(&Rumeysa);
    hash_table_insert(&Ege);
    hash_table_insert(&Selim);
    hash_table_insert(&Burak);
    hash_table_insert(&Ferhat);
    hash_table_insert(&Anil);
    hash_table_insert(&Emre);
    print_table();

    person *tmp = hash_table_lookup("Rumeysa");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }

    tmp = hash_table_lookup("Gorkem");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }

    hash_table_delete("Ege");
    hash_table_delete("Selim");
    tmp = hash_table_lookup("Ege");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }
    print_table();
    hash_table_delete("Burak");

    tmp = hash_table_lookup("Sedat");
    if(tmp == NULL)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }
    print_table();

    /*printf("Sedat => %u\n", hash("Sedat"));
    printf("Rumeysa => %u\n", hash("Rumeysa"));
    printf("Burak => %u\n", hash("Burak"));
    printf("Ege => %u\n", hash("Ege"));
    printf("Selim => %u\n", hash("Selim"));
    printf("Emre => %u\n", hash("Emre"));
    printf("Ferhat => %u\n", hash("Ferhat"));
    printf("Ozan => %u\n", hash("Ozan"));*/
    return 0;
}
