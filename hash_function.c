#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h> 
#define TABLE_SIZE 5
#define LENGTH 256


//Linked list struct node
typedef struct node
{
    char str[LENGTH + 1];
    int age;
    struct node *next;
} node;

// Hash table
node *table[TABLE_SIZE];

// Hash value / table index
unsigned int hashValue = 0;

// Hash function
unsigned int hashFunction(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        hashValue = hashValue * str[i] - strlen(str);
        
    }
    return hashValue % TABLE_SIZE;
}


// Load data to hash table
bool loadData(char *str, int number)
{
    
    hashValue = hashFunction(str);

    node *head = table[hashValue];

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    strcpy(n->str, str);
    n->age = number;

    
    if (table[hashValue] == NULL)
    {
        table[hashValue] = n;
        n->next = NULL;
    }
    else
    {
        n->next = table[hashValue];
        table[hashValue] = n;
    }
    
    return true;
}

// Print a hash table
void printHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == NULL)
        {
            printf("%d\t***\n", i);
        }
        else
        {
            node *cursor = table[i];
            while(cursor != 0)
            {
            printf("%d\tName: %s\tAge: %d\n", i, cursor->str, cursor->age);
            cursor = cursor->next;
            }
        }
    }
}

int main()
{
    //hashFunction("Charlie");
    //hashFunction("Anne");
    //hashFunction("Luke");
    //hashFunction("Marie");
    //hashFunction("Rufus");

    node charlie = {.str = "Charlie", .age = 25};
    node anne = {.str = "Anne", .age = 41};
    node luke = {.str = "Luke", .age = 10};
    node marie = {.str = "Marie", .age = 58};
    node rufus = {.str = "Rufus", .age = 4};

    loadData(charlie.str, charlie.age);
    loadData(anne.str, anne.age);
    loadData(luke.str, luke.age);
    loadData(marie.str, marie.age);
    loadData(rufus.str, rufus.age);

    printHashTable();
    
    return 0;
}

/*
In computing, a hash table, also known as hash map or dictionary, 
is a data structure that implements a set abstract data type, a structure that can map keys to values. 
A hash table uses a hash function to compute an index, 
also called a hash code, into an array of buckets or slots, from which the desired value can be found. 
During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.
Source: https://en.wikipedia.org/wiki/Hash_table

Chaining is a technique used for avoiding collisions in hash tables. 
A collision occurs when two keys are hashed to the same index in a hash table. Collisions are a problem 
because every slot in a hash table is supposed to store a single element.
In the chaining techniques a hash table is an array of Linked Lists.
Source: https://www.educative.io/answers/what-is-chaining-in-hash-tables
*/