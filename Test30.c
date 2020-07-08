#include <stdio.h>
#include <string.h>

int shixiaoxie(char a)
{
    return (a <= 'z' && a >= 'a');
}

int shidaxie(char a)
{
    return (a <= 'Z' && a >= 'A');
}

int main()
{
    int len, i;
    char yuanwen[55];
    char temp;
    scanf("%s", yuanwen);
    len = strlen(yuanwen);
    for (i = 0; i < len; i++) {
        if (shixiaoxie(yuanwen[i]) && !shixiaoxie(yuanwen[i] + 3)) {
            yuanwen[i] -= 26;
        }
        if (shidaxie(yuanwen[i]) && !shidaxie(yuanwen[i] + 3)) {
            yuanwen[i] -= 26;
        }
        yuanwen[i] += 3;
    }
    i = 0;
    while (i < len / 2) {
        temp = yuanwen[i];
        yuanwen[i] = yuanwen[len - 1 - i];
        yuanwen[len - i - 1] = temp;
        i++;
    }
    for (i = 0; i < len; i++) {
        if (shixiaoxie(yuanwen[i])) {
            yuanwen[i] -= 0x20;
        } else if (shidaxie(yuanwen[i])) {
            yuanwen[i] += 0x20;
        }
    }
    printf("%s", yuanwen);
    
    return 0;
}