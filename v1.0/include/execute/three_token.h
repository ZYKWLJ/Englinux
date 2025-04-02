# ifndef THREE_TOKEN_H
# define THREE_TOKEN_H
# include "../display/color.h"
# include "../display/print_words.h"
# include "../display/display.h"
#include "../../include/display/error.h"
#include <stdlib.h>
#include "find.h"
#include "help.h"
# include "is_all_digit.h"
#include"parser_second_token.h"
#include"parser_third_token.h"
void execute_three_token(char*token[],int token_num, char *origin_str);
#endif