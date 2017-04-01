/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

node* root;

unsigned int count;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int length = strlen(word);
    
    node* ptr = root;
    
    for (int i=0; i < length; i++)
    {
        char c = tolower(word[i]);
        
        if (c == '\'')
        {
            c = 123;
        }
        
        node* nextNode = ptr->nodes[c-97];
        
        if (nextNode == NULL)
        {
            return false;
        }
        else
        {
            ptr = nextNode;
        }
    }
    
    if (ptr->isWord == true)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    
    // allocate space for the first root node
    root = calloc(1, sizeof(node));
    
    // point to current node
    node* ptr = root;
    
    // read the dictionary
    for (char c = tolower(fgetc(dict)); c != EOF; c = fgetc(dict))
    {
        if (c == '\n')
        {
            if (ptr != root)
            {
                count++;
                ptr->isWord = true;
                ptr = root;
            }
        }
        else
        {
            if (c == '\'')
            {
                c = 123;
            }
            
            node* nextNode = ptr->nodes[c-97];
            if(nextNode == NULL)
            {
                ptr->nodes[c-97] = calloc(1, sizeof(node));
                ptr = ptr->nodes[c-97];
            }
            else
            {
                ptr = nextNode;
            }
        }
    }
    
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

void clear(node* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if (ptr->nodes[i] != NULL)
        {
            clear(ptr->nodes[i]);
        }
    }
    free(ptr);
}
/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    clear(root);
    return true;
}
