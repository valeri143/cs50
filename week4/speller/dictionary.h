#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define LENGTH 45

bool load(const char *dictionary);

bool check(const char *word);

unsigned int size(void);

bool unload(void);

#endif 
