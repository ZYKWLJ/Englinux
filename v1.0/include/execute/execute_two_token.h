# ifndef TWO_TOKEN_H
# define TWO_TOKEN_H
#include "../../include/display/error.h"
# include "../display/color.h"
# include "../display/display.h"
#include "is_all_digit.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "find.h"
#include "help.h"

void execute_two_token(char*token[],int token_num, char *origin_str);
#endif