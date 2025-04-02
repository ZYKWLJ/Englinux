#include "../../include/display/print_help.h"
// 计算字符串的显示宽度（中文算2，英文算1）
// int display_width(const char *str) {
//     int width = 0;
//     while (*str) {
//         if ((unsigned char)*str >= 0x80) { // 中文字符
//             width += 2;
//             str += 3; // UTF-8中文字符通常占3字节
//         } else {
//             width += 1;
//             str += 1;
//         }
//     }
//     return width;
// }

// // 打印固定宽度的字符串，考虑中文字符
// void print_padded(const char *str, int width) {
//     int str_width = display_width(str);
//     printf("%s", str);
//     for (int i = str_width; i < width; i++) {
//         printf(" ");
//     }
// }

// 打印表格内容的函数（通用版本）
void print(const char **str[], int columns_num) {
    setlocale(LC_ALL, ""); // 设置本地化，支持宽字符

    // 1. 计算每列的最大宽度
    int col_max_widths[columns_num];
    for (int i = 0; i < columns_num; i++) {
        col_max_widths[i] = 0;
        for (int row = 0; str[i][row] != NULL; row++) {
            int width = display_width(str[i][row]);
            if (width > col_max_widths[i]) {
                col_max_widths[i] = width;
            }
        }
    }

    // 2. 计算最大行数（以最长的列为准）
    int max_rows = 0;
    for (int i = 0; i < columns_num; i++) {
        int rows = 0;
        while (str[i][rows] != NULL) {
            rows++;
        }
        if (rows > max_rows) {
            max_rows = rows;
        }
    }

    // 3. 打印上边框
    for (int i = 0; i < columns_num; i++) {
        printf("+");
        for (int j = 0; j < col_max_widths[i] + 2; j++) {
            printf("-");
        }
    }
    printf("+\n");

    // 4. 打印表头（第一行）
    printf("|");
    for (int i = 0; i < columns_num; i++) {
        printf(" ");
        print_padded(str[i][0], col_max_widths[i]);
        printf(" |");
    }
    printf("\n");

    // 5. 打印表头和内容之间的分隔线
    for (int i = 0; i < columns_num; i++) {
        printf("+");
        for (int j = 0; j < col_max_widths[i] + 2; j++) {
            printf("-");
        }
    }
    printf("+\n");

    // 6. 打印表格内容（从第2行开始）
    for (int row = 1; row < max_rows; row++) {
        printf("|");
        for (int i = 0; i < columns_num; i++) {
            printf(" ");
            if (str[i][row] != NULL) {
                print_padded(str[i][row], col_max_widths[i]);
            } else {
                print_padded("", col_max_widths[i]);
            }
            printf(" |");
        }
        printf("\n");
    }

    // 7. 打印下边框
    for (int i = 0; i < columns_num; i++) {
        printf("+");
        for (int j = 0; j < col_max_widths[i] + 2; j++) {
            printf("-");
        }
    }
    printf("+\n");
}