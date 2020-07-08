#include <stdio.h>
#include <string.h>

int Judge(char* qipan)
{
    int i, len = strlen(qipan);
    int mat[9] = { 0 };
    for (i = 0; i < len; i++) {
        if (i % 2 == 0) {
            mat[qipan[i] - '1'] = 1; //»¨Ò¬ÊÇ1
        } else {
            mat[qipan[i] - '1'] = 2;
        }
        //printf("%d",mat[qipan[i]-'1']);
    }
    for (i = 0; i < 3; i++) {
        if (mat[i] == mat[i + 3] && mat[i] == mat[i + 6] && mat[i] != 0) {
            return (mat[i] == 1 ? -1 : 1);
        }
        if (mat[3 * i] == mat[3 * i + 1] && mat[3 * i] == mat[3 * i + 2] && mat[3 * i] != 0) {
            return (mat[3 * i] == 1 ? -1 : 1);
        }
    }
    if ((mat[0] == mat[4] && mat[4] == mat[8] || mat[2] == mat[4] && mat[4] == mat[6]) && mat[4] != 0) {
        return (mat[4] == 1 ? -1 : 1);
    }
    return 0;
}

int main()
{
    char qipan[20];
    scanf("%s", qipan);
    if (Judge(qipan) > 0) {
        printf("suantou wins.");
    } else if (Judge(qipan) < 0) {
        printf("huaye wins.");
    } else {
        printf("drew.");
    }

    return 0;
}