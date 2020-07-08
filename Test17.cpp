#include <stdio.h>

typedef struct {
    long long la, lb, lc;
} lll;

int main()
{
    long long int n;
    long long int a, b, count = 0;
    lll arr[200];
    scanf("%lld", &n);
    for (a = 0; a <= n / 7; a++) {
        if ((n - 7 * a) % 4 == 0) {
            arr[count].la = a;
            arr[count].lb = (n - 7 * a) / 4;
            arr[count].lc = n - a - arr[count].lb;
            count++;
        }
    }
    if (count == 0) {
        printf("No Answer.");
    } else {
        for (a = 0; a < count; a++) {
            printf("%lld %lld %lld\n", arr[a].la, arr[a].lb, arr[a].lc);
        }
    }

    return 0;
}