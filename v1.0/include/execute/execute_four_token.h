# ifndef FOUR_TOKEN_H
# define FOUR_TOKEN_H
# include "../display/color.h"
#include "find.h"
#include "help.h"
# include "is_all_digit.h"
#include "../../include/display/error.h"
#include "../../include/display/display.h"
#include "parser_first_token.h"
#include "parser_second_token.h"
#include "parser_third_token.h"
#include "parser_fourth_token.h"
// void execute_four_token(char*token,char *origin_str,int*firstcol_show,int*secondcol_show,int*thirdcol_show,int*fourthcol_show);
void execute_four_token(char*token[],int token_num, char *origin_str);
#endif