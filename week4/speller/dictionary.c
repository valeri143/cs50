#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define SIZE 65536

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

node *hashtable[SIZE];
unsigned int word_count = 0;

unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % SIZE;
}

bool add_to_hashtable(const char *word)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    strcpy(new_node->word, word);
    unsigned int index = hash(word);
    new_node->next = hashtable[index];
    hashtable[index] = new_node;
    word_count++;
    return true;
}

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        if (!add_to_hashtable(word))
        {
            fclose(file);
            return false;
        }
    }
    fclose(file);
    return true;
}

bool check(const char *word)
{
    char lower_word[LENGTH + 1];
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[strlen(word)] = '\0';
    unsigned int index = hash(lower_word);
    for (node *cursor = hashtable[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcmp(cursor->word, lower_word) == 0)
        {
            return true;
        }
    }
    return false;
}

unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *cursor = hashtable[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
