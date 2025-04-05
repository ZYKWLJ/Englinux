#include "../../include/execute/execute_three_token.h"
void execute_three_token(char *token[], int token_num, char *origin_str)
{
    parser_first_token(token[0], origin_str);
    int library_index = 0;                                        // 超找的词库
    int find_mod = 0;                                             // 查找的模式
    char *word = (char *)malloc(sizeof(char) * strlen(token[1])); // 查找的单词
    // 解析第二个token！
    char *subquerys[1024];
    if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 2)
    {
        // 防止无限查询提前退出！
        if (parser_third_token(token[2], origin_str, &library_index) == 0)
        {
            return;
        }
        // 查询每一个中文子串！
        for (int i = 0; subquerys[i]; i++)
        {
            if (parser_third_token(token[2], origin_str, &library_index) == 0)
            {
                return;
            }
            // 存放4、6级查到的单词块！
            word_entry *result = (word_entry *)malloc(sizeof(word_entry) * 5000);
            int result_size = 0;
            // printf("word:%s\n", word);
            find(subquerys[i], library_index, find_mod, result, &result_size); // 改为查询中文！
            display(library_index, find_mod, word, result, result_size, 2, 4, 0, 0);
        }
    }
    else if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 1)
    {
        if (parser_third_token(token[2], origin_str, &library_index) == 0)
        {
            return;
        }
        // 存放4、6级查到的单词块！
        word_entry *result = (word_entry *)malloc(sizeof(word_entry) * 5000);
        int result_size = 0;
        // printf("word:%s\n", word);
        find(word, library_index, find_mod, result, &result_size);
        display(library_index, find_mod, word, result, result_size, 2, 4, 0, 0);
    }
    else
    {
        return;
    }
}