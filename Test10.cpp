#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 128

void swap(char* a, char* b)
{
    char temp[MAXSIZE];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void SelectSort(char* R[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            for (int token = 0; token < MAXSIZE; token++) {
                if (R[j][token] < R[k][token]) {
                    k = j;
                    break;
                } else if (R[j][token] > R[k][token]) {
                    break;
                }
            }
        }
        if (k != i) {
            swap(R[i], R[k]);
        }
    }
}

int main()
{
    char* R[5];
    printf("请输入5个国家名(用空格隔开):");
    for (int i = 0; i < 5; i++) {
        R[i] = (char*)calloc(1, MAXSIZE * sizeof(char));
        scanf("%s", R[i]);
    }
    SelectSort(R, 5);
    printf("按字母顺序排序后如下:");
    for (int i = 0; i < 5; i++) {
        printf("%s ", R[i]);
    }

    return 0;
}