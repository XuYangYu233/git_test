#include <stdio.h>
#include <string.h>

void reverse(char num[])
{
    int i, j;
    char temp;
    i = 0;
    j = strlen(num) - 1;
    while (i < j) {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        i++;
        j--;
    }
}

void str_x2(char result[])
{
    int len_str = strlen(result);
    int i = 0, cf = 0;
    char temp;
    reverse(result);
    while (i < len_str || cf != 0) {
        if (result[i] > '9' || result[i] < '0') {
            result[i] = '0';
        }
        temp = (result[i] - '0') * 2 + '0' + cf;
        if (temp > '9') {
            cf = 1;
            temp -= 10;
        } else {
            cf = 0;
        }
        result[i] = temp;
        
        i++;
    }
    reverse(result);
}

int main()
{
    int n, i;
    char result[100]="1";
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        str_x2(result);
    }
    printf("%s", result);
    
    return 0;
}