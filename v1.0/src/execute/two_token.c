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
            // 存放4、6级查到的单词块！
            word_entry *result_4 = (word_entry *)malloc(sizeof(word_entry) * 5000);
            word_entry *result_6 = (word_entry *)malloc(sizeof(word_entry) * 5000);
            int result_4_size = 0, result_6_size = 0;
            // 现在这里才开始分查询模式！
            // 默认是四六级一起查询-0，并且显示两列-103，单词和释义！查询归查询，显示归显示！两者解耦！
            if (l == 0 && r == strlen(token[1]) - 1)
            {

                // 没有%--精确匹配
                // int
                find(str, 4, 0, result_4, &result_4_size);
                find(str, 6, 0, result_6, &result_6_size);
                // 显示4级库精确查询的result_4_size条结果的result_4单词块！
                display(4, 0,str,result_4, result_4_size, 1,3,-1,-1);
                display(6, 0,str,result_6, result_6_size, 1,3,-1,-1);
            }
            else if (l == 0)
            {
                // 只有%在后面--前缀匹配
                find(str, 4, 1, result_4, &result_4_size);
                find(str, 6, 1, result_6, &result_6_size);
                display(4, 1,str,result_4, result_4_size, 1,3,-1,-1);
                display(6, 1,str,result_6, result_6_size, 1,3,-1,-1);
            }
            else if (r == strlen(token[1]) - 1)
            {
                // 只有%在前面--后缀匹配
                find(str, 4, 2, result_4, &result_4_size);
                find(str, 6, 2, result_6, &result_6_size);
                display(4, 2,str,result_4, result_4_size, 1,3,-1,-1);
                display(6, 2,str,result_6, result_6_size, 1,3,-1,-1);
            }
            else
            {
                // 有%在前后--包含匹配
                find(str, 4, 3, result_4, &result_4_size);
                find(str, 6, 3, result_6, &result_6_size);
                display(4, 3,str,result_4, result_4_size, 1,3,-1,-1);
                display(6, 3,str,result_6, result_6_size, 1,3,-1,-1);
            }
        }
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return;
    }
}