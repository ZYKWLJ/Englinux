#include "../../include/execute/execute_two_token.h"
void execute_two_token(char *token[], int token_num, char *origin_str)
{
    parser_first_token(token[0], origin_str);
    int library_index = 0;                                        // 超找的词库
    int find_mod = 0;                                             // 查找的模式
    char *word = (char *)malloc(sizeof(char) * strlen(token[1])); // 查找的单词
    // 解析第二个token！
    char *subquerys[1024];
    if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 2)
    {
        // 查询每一个中文子串！
        for (int i = 0; subquerys[i]; i++)
        {
            // 存放4、6级查到的单词块！
            //             // 存放4、6级查到的单词块！
            word_entry *result_4 = (word_entry *)malloc(sizeof(word_entry) * 5000);
            word_entry *result_6 = (word_entry *)malloc(sizeof(word_entry) * 5000);
            int result_4_size = 0, result_6_size = 0;
            // printf("word:%s\n", word);
            find(subquerys[i], library_index, find_mod, result_4, &result_4_size); // 改为查询中文！
            find(subquerys[i], library_index, find_mod, result_6, &result_6_size); // 改为查询中文！
            display(4, find_mod, subquerys[i], result_4, result_4_size, 2, 4, 0, 0);
            display(6, find_mod, subquerys[i], result_6, result_6_size, 2, 4, 0, 0);
            // free(result_4);
            // free(result_6);
        }
    }
    else if (parser_second_token(token[1], origin_str, &find_mod, word, subquerys) == 1)
    {
        // 存放4、6级查到的单词块！
        //             // 存放4、6级查到的单词块！
        word_entry *result_4 = (word_entry *)malloc(sizeof(word_entry) * 5000);
        word_entry *result_6 = (word_entry *)malloc(sizeof(word_entry) * 5000);
        int result_4_size = 0, result_6_size = 0;
        // printf("word:%s\n", word);
        find(word, library_index, find_mod, result_4, &result_4_size); // 英文查询
        find(word, library_index, find_mod, result_6, &result_6_size); // 英文查询
        display(4, find_mod, word, result_4, result_4_size, 2, 4, 0, 0);
        display(6, find_mod, word, result_6, result_6_size, 2, 4, 0, 0);
    }
    else
    {
        return;
    }
}