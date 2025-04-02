/**
 * filename:execute.h
 * description:
 * author:EthanYankang
 * create time:2025/03/31 14:43:55
 */
#ifndef _EXECUTE_H_
#define _EXECUTE_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "search.h"
#include "clear.h"
#include "../display/error.h"
#include "execute_one_token.h"
#include "execute_two_token.h"
#include "execute_three_token.h"
#include "execute_four_token.h"
#include "../lexer/lexer.h"
#include "is_all_digit.h"
#include "find.h"
void execute(char *str);
// int is_all_digit(const char *str);
#endif