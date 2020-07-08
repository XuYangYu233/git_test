#include <stdio.h>

int Solution(int arr[10][10], int n)
{
    
}

int main()
{
    int n, i, j, res;
    int arr[10][10];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    res = Solution(arr, n);
    printf("%d", res);

    return 0;
}