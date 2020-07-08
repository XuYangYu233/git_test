#include <stdio.h>

char saolei(char lei[100][100], int n, int m, int i, int j)
{
    char count = 0;
    if (lei[i][j] == '*') {
        return '*';
    } else {
        if (lei[i - 1][j - 1] == '*' && i > 0 && j > 0) {
            count++;
        }
        if (lei[i - 1][j] == '*' && i > 0) {
            count++;
        }
        if (lei[i - 1][j + 1] == '*' && i > 0 && j < m - 1) {
            count++;
        }
        if (lei[i][j - 1] == '*' && j > 0) {
            count++;
        }
        if (lei[i][j + 1] == '*' && j < m - 1) {
            count++;
        }
        if (lei[i + 1][j - 1] == '*' && i < n - 1 && j > 0) {
            count++;
        }
        if (lei[i + 1][j] == '*' && i < n - 1) {
            count++;
        }
        if (lei[i + 1][j + 1] == '*' && i < n - 1 && j < m - 1) {
            count++;
        }
        return (count + '0');
    }
}

int main()
{
    int n, m, i, j, count = 0;
    scanf("%d %d", &n, &m);
    char lei[100][100];
    char out[10000];
    for (i = 0; i < n; i++) {
        getchar();
        for (j = 0; j < m; j++) {
            scanf("%c", &lei[i][j]);
        }

    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            //printf("%c", saolei(lei, n, m, i, j));
            out[count++] = saolei(lei, n, m, i, j);
        }
        out[count++] = '\n';
        //printf("\n");
    }
    out[count] = '\0';
    printf("%s", out);
    
    return 0;
}