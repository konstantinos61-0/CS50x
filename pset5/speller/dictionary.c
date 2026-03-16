// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 373;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // hash word
    unsigned int hcode = hash(word);

    // Go to table[hcode]
    node *ptr = table[hcode];

    // Iterate through linked list
    while (ptr != NULL)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }

    // Haven't found word in hash table
    return false;
}

// size of table in terms of nodes
unsigned int sizeofhtable = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int length = strlen(word);
    unsigned int sum = 0;
    for (int i = 0; i < length - 1; i++)
    {
        sum = sum + tolower(word[i]);
    }
    sum = sum % N;
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // initialize hash table linked lists to NULL
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary file
    FILE *f = fopen(dictionary, "r");

    // Check if dictionary opens
    if (f == NULL)
    {
        printf("Couldn't open dictionary file\n");
        return false;
    }

    // Read dictionary word by word

    // enter the whole file word by word
    char c;
    int index = 0;
    char word[LENGTH + 1];
    while (fread(&c, sizeof(char), 1, f) != 0)
    {
        // adding letters to the word
        if (c != '\n')
        {
            word[index] = c;
            index++;
        }

        // end of word detected. insert word into the hash table
        else
        {
            word[index] = '\0';
            unsigned int code = hash(word);
            node *n = malloc(sizeof(node));
            strcpy(n->word, word);
            n->next = table[code];
            table[code] = n;

            // clear the word[LENGTH + 1] string for the new word
            for (int i = 0; i < index; i++)
            {
                word[i] = '\0';
            }

            index = 0;
            sizeofhtable++;
        }
    }

    // close dictionary file
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sizeofhtable;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    // iterating through the hash table (N)
    for (int i = 0; i < N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }

    return true;
}
