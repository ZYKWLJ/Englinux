#include "../../include/execute/parser_second_token.h"
int  parser_second_token(char *token, char *origin_str, int *find_mod, char *word)
{
    // 1.先判断是不是合法单词！
    // 首先去除可能的%
    int l = 0, r = strlen(token) - 1;
    if (token[0] == '%')
    {
        l++;
    }
    if (token[r] == '%')
    {
        r--;
    }
    
    // 直接处理原始 word 指针，不要创建新的 str
    // 将处理后的字符串复制到 word 中
    int len = r - l + 1;
    strncpy(word, token + l, len);
    word[len] = '\0';
    
    // 2.再判断中心的字符串是不是全字母！
    if (!is_all_alpha(word))
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return 0;
    }
    
    // 开始解析查找模式！
    if (l == 0 && r == strlen(token) - 1)
    {
        *find_mod = 0;
    }
    else if (l == 0)
    {
        *find_mod = 1;
    }
    else if (r == strlen(token) - 1)
    {
        *find_mod = 2;
    }
    else
    {
        *find_mod = 3;
    }
    return 1;
}