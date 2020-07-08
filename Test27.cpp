#include <stdio.h>
#include <stdlib.h>

int Cha_chong(int shudu[9][9], int i, int j, int k)
{
    int area_i = i / 3;
    int area_j = j / 3;
    int a, b;
    for (a = area_i * 3; a < area_i * 3 + 3; a++) {
        for (b = area_j * 3; b < area_j * 3 + 3; b++) {
            if (a != i && b != j && shudu[a][b] == k) {
                return 0;   //指查重不通过
            }
        }
    }
    for (b = 0; b < 9; b++) {
        if (shudu[i][b] == k && b != j) {
            return 0;
        }
    }
    for (a = 0; a < 9; a++) {
        if (shudu[a][j] == k && a != i) {
            return 0;
        }
    }
    return 1;   //指查重通过
}

int Solution(int shudu[9][9], int x, int y)
{
    int i, j, res = 0;
    int next_x = x, next_y = y;
    while(shudu[x][y] != 0) {
        x = next_x;
        y = next_y;
        next_y++;
        if (next_y > 8) {
            next_y = 0;
            next_x++;
        }
    }
    if (x > 8) {
        return 1;
    }
    for (i = 1; i <= 9; i++) {
        if (x == 8) {
            printf("!");
        }
        if (Cha_chong(shudu, x, y, i) == 1) {
            shudu[x][y] = i;
            if (next_x > 8 /*|| (next_x == 8 && next_y == 8)*/) {
                return 1;
            } else {
                res = Solution(shudu, next_x, next_y);
            }
            if (res == 1) {
                return 1;
            }
        }
    }
    shudu[x][y] = 0;
    return 0;
}

int main()
{
    int shudu[9][9];
    int i, j;
    char temp;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf("%c", &temp);
            if (temp == ' ' || temp == '\n') {
                j--;
            } else if (temp == '*') {
                shudu[i][j] = 0;
            } else {
                shudu[i][j] = (int)temp - '0';
            }
        }
    }
    Solution(shudu, 0, 0);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d", shudu[i][j]);
            if (j == 8) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }
    
    return 0;
}