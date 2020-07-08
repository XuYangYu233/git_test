#include <stdio.h>
#include <string.h>

int strcmp_2(char a[], char b[])
{
    if ((strlen(a) == 1 || strlen(b) == 1) && a[0] == b[0]) {
        if (strlen(a) == 1 && a[0] > b[1]){
            return 1;
        } else if (strlen(b) == 1 && b[0] > a[1]) {
            return -1;
        } else {
            return strcmp(a, b);
        }
        //return (strlen(a) == 1 ? 1 : -1);
    } else {
        return strcmp(a, b);
    }
}

void ShellSort(char R[][1000], int n){
    int i,j,d;
    char tmp[1000];
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            //tmp = R[i];
            strcpy(tmp, R[i]);
            j = i - d;
            while(j>=0 && /*tmp.key<R[j].key*/strcmp_2(tmp, R[j]) < 0){
                strcpy(R[j+d], R[j]);
                //R[j+d] = R[j];
                j = j - d;
            }
            strcpy(R[j+d], tmp);
            //R[j+d] = tmp;
        }
        d = d / 2;
    }
}

int main()
{
    freopen("test142.txt", "r", stdin);
    int n, i;
    char strarr[100][1000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", strarr[i]);
    }
    ShellSort(strarr, n);
    for (i = 1; i < n; i++) {
        strcat(strarr[0], strarr[i]);
    }
    printf("%s", strarr[0]);
    
    return 0;
}