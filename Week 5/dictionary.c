/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "dictionary.h"
#include <stdlib.h>

/**
 * Returns true if word is in dictionary else false.
 */
 
typedef struct node {
    bool is_word;
    struct node* children[27];
}node;
struct node *root;
unsigned int words;

void freeroot(node *copy);

bool check(const char *word)
{   
    
    struct node* ch = malloc(sizeof(node));
    ch = root;
    for (int i = 0, n = strlen(word); i < n; i++) {
        int c = word[i] - '0' - 48;
        if (c < 0) {
            c = 26;
            words++;
        }
        
        if (root->children[c] == NULL)
            return false;
        else {
            ch = ch->children[c];
        }
    }
    
    if (ch->is_word)
        return true;
    return false;
}



/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{   
    
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
        return false;
    
    char line[45];
    root = malloc(sizeof(node));
    root->is_word = false;
    
    for (int i = 0; i < 27; i++) {
        root->children[i] = NULL;
    }
    
    while(fgets(line, sizeof(line), dict)) {
        //character to corresponding int conversion
        
        for (int i = 0, n = sizeof(line)/sizeof(line[0]); i < n; i++) {
            int c = line[i] - '0' - 48;
            if (c < 0)
                c = 26;
                
            if (!root->children[c]) {
                struct node *new_node = (struct node*)malloc(sizeof(struct node));
                root->children[c] = new_node;
            } else {
                root = root->children[c];
            }
        }
        root->is_word = true;
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */


bool unload(void)
{
    if (!root) return true;
    
    struct node *copy = malloc(sizeof(node));
    copy = root;
    
    freeroot(copy);

    return false;
}

void freeroot(node* copy) {
    for (int i = 0; i < 27; i++){
        if (copy->children[i] != NULL){
            freeroot(copy->children[i]);
        }
    }
    free(copy); 
}
