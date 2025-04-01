#include "../../include/execute/two_token.h"
// #include "../../include/display/error.h"
void execute_two_token(char *token[], int token_num, char *origin_str)
{
    if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        // 1.先判断是不是合法单词！
        // 首先去除可能的%
        int l = 0, r = strlen(token[1]) - 1;
        if (token[1][0] == '%')
        {
            l++;
        }
        if (token[1][r] == '%')
        {
            r--;
        }
        char *str = (char *)malloc(sizeof(char) * (r - l + 2));
        strncpy(str, token[1] + l, r - l + 1);
        str[r - l + 1] = '\0';
        // 判断中心的字符串是不是全字母！
        if (!is_all_alpha(str))
        {
            printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
            return;
        }
        // 开始执行查找模式！
        else
        {
            // 现在这里才开始分查询模式！
            // 默认是四六级一起查询，并且显示两列，单词和释义！
            if (l == 0 && r == strlen(token[1]) - 1)
            {
                // 没有%--精确匹配
                find(str, 0, 0, 1, 0, 3);
            }
            else if (l == 0)
            {
                // 只有%在后面--前缀匹配
                find(str, 0, 1, 1, 0, 3);
            }
            else if (r == strlen(token[1]) - 1)
            {
                // 只有%在前面--后缀匹配
                find(str, 0, 2, 1, 0, 3);
            }
            else
            {
                // 有%在前后--包含匹配
                find(str, 0, 3, 1, 0, 3);
            }
        }
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return;
    }
}