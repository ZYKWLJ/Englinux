#include "../../include/execute/find.h"
// 精确查找单词
int find_in_single_library(int library_index, char *str, int search_mod, word_entry *result)
{
    // printf("查询%s%s%d%s级词库\n", BLUE, BOLD, library_index,RESET);
    switch (search_mod)
    {
    case 0:
        return find_exact(str, library_index, result);
        break;
    case 1:
        return find_prefix(str, library_index, result);
        break;
    case 2:
        return find_suffix(str, library_index, result);
        break;
    case 3:
        return find_contain(str, library_index, result);
        break;
    default:
        break;
    }
}

word_entry *find(char *str, int library_index, int search_mod, word_entry *result,int* result_size)
{
    // git commit -a -m "初始框架完成一半"
    // 先找到单词并高亮，然后放在一个三维数组里面，然后在打印输出
    // int total = 0;
    // 默认查到5000条，足够了
    library_index=library_index==4?0:1;
    *result_size = find_in_single_library(library_index, str, search_mod, result);
    // printf("查询%s%s%d级%s词库[%s%s%d条]%s\n", BOLD, BLUE, library_index==0?4:6, RESET, BOLD, BLUE, *result_size, RESET);
    return result;
}
// 查询模式参数的唯一作用就是判别某些单词是不是相应查询！具体来说是前中后缀还是精确查询！
