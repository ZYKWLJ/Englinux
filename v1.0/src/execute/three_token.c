#include "../../include/execute/three_token.h"
void execute_three_token(char *token[], int token_num, char *origin_str)
{
    if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        // 判断是不是单词合法单词！
        if (!is_all_digit(token[1]))
        {
            if (token[2][0] != '-')
            {
                printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            }
            else
            {
                char *lib_str = NULL;
                strncpy(lib_str, token[2] + 1, strlen(token[2]) - 1);
                int lib = atoi(lib_str);
                printf("%s\t%d\n", lib_str, lib);
                if (lib != 4 || lib != 6)
                {
                    printf(ERROR_LIB_NOT_EXIST, RED, BOLD, lib, RESET);
                }
                else
                {
                    // search(token[1], lib);
                }
            }
            if (strcmp(token[2], "-4") == 0 || strcmp(token[2], "-6") == 0)
            {
            }
            else
            {
                printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            }
        }
        else
        {
            printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            // printf("%s%s%s--无效指令！%s(按下%s%shelp%s查看指令表)\n", BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET); // 这里提示的信息也是原字符串！
            return;
        }
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        // printf("%s%s%s--无效指令！%s(按下%s%shelp%s查看指令表)\n", BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET); // 这里提示的信息也是原字符串！
        return;
    }
}