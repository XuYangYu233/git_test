#include <cstring>
#include <iostream>

char duibi(char* origin, char* after)
{
    char temp = 0, sum = 0;
    sum = origin[0];
    for (int i = 1; i < strlen(origin); i++) {
        temp = origin[i];
        sum = sum ^ temp;
    }
    for (int i = 0; i < strlen(after); i++) {
        temp = after[i];
        sum = sum ^ temp;
    }

    return sum;
}

int main()
{
    char origin[] = "23456789QJKA";
    char after[] = "2346789QJKA";
    char temp;
    temp = duibi(origin, after);
    printf("%c", temp);

    return 0;
}