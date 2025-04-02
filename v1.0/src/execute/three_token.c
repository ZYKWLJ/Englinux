#include "../../include/execute/three_token.h"
void execute_three_token(char *token[], int token_num, char *origin_str)
{
    if (strcmp(token[0], "find") == 0 || strcmp(token[0], "f") == 0)
    {
        int library_index = 0; // 超找的词库
        int find_mod = 0;      // 查找的模式
        char *word = (char*)malloc(sizeof(char)*strlen(token[1]));     // 查找的单词
        parser_second_token(token[1], origin_str, &find_mod, word);
        parser_third_token(token[2], origin_str, &library_index);
        // 存放4、6级查到的单词块！
        word_entry *result = (word_entry *)malloc(sizeof(word_entry) * 5000);
        int result_size = 0;
        // printf("word:%s\n", word);
        find(word, library_index, find_mod, result, &result_size);
        display(library_index, find_mod, word, result, result_size, 1, 3, -1, -1);
    }
    else
    {
        printf(ERROR_CMDS, BOLD, RED, origin_str, RESET, BOLD, YELLOW, RESET);
        return;
    }
}