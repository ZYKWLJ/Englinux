#ifndef _SEARCH_H_
#define _SEARCH_H_
// # include "words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../words_lib/words.h"
#include "../display/color.h"
#include "match.h"
// extern word_entry **library[LIB_NUM];
word_entry *find(char *str, int library_index, int search_mod, word_entry *result,int* result_size);
int isAllChinese(const char *str);
#endif
