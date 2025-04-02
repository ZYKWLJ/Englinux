#ifndef _PRINT_H_
#define _PRINT_H_
#include <stdio.h>
#include <stdarg.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include "color.h"
#include"../../include/words_lib/words.h"
#include"display_width.h"

void print_words(word_entry *words, int word_count,char*str,int match_mod,
                 int firstcol_show, int secondcol_show,
                 int thirdcol_show, int fourthcol_show);
#endif