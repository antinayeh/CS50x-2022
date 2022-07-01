// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2545;

// Hash table
node *table[N];
int dict_size = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_val = hash(word);

    node *n = table[hash_val];

    while(n != NULL)
    {
        if(strcasecmp(word, n -> word) == 0)
        {
            return true;
        }
        n = n -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int letter = tolower(word[0])-97;
    int length = strlen(word);
    int hash_val = letter * 100 + length;

    return hash_val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    char new_word[LENGTH + 1];
    while(fscanf(dict, "%s", new_word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, new_word);
        int hash_val = hash(new_word);
        n -> next = table[hash_val];
        table[hash_val] = n;
        dict_size ++;

    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while(n != NULL)
        {
            node *temp = n;
            n = n -> next;
            free(temp);
        }
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
