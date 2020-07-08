#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n, m, p1, p2, s1, s2;
    long long suma = 0, sumb = 0;
    long long i, temp_sig=0, temp_val=0;
    long long* arr=NULL;
    scanf("%lld", &n);
    arr = (long long*)malloc(n * sizeof(long long));
    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }
    scanf("%lld %lld %lld %lld", &m, &p1, &s1, &s2);
    for (i = 0; i < m - 1; i++) {
        suma += (m - i - 1) * arr[i];
    }
    for (i = m; i < n; i++) {
        sumb += (i - m + 1) * arr[i];
    }

    if (p1 < m) {
        suma += (m - p1) * s1;
    } else if (p1 > m) {
        sumb += (p1 - m) * s1;
    } else {
        /*pass*/
    }

    if (suma > sumb) {
        temp_val = suma - sumb - s2 > 0 ? suma - sumb - s2 : s2 + sumb - suma;
        temp_sig = m + 1;
        for (i = m + 1; i < n; i++) {
            long long token;
            token = suma - sumb - s2 * (i + 1 - m) > 0 ? suma - sumb - s2 * (i + 1 - m) : 0 - (suma - sumb - s2 * (i + 1 - m));
            if (token < temp_val) {
                temp_val = token;
                temp_sig = i + 1;
            }
        }
        if (suma - sumb < temp_val) {
            goto MID;
        }
        printf("%lld", temp_sig);
    } else if (suma < sumb) {
        temp_val = sumb - suma - s2 * (m - 1) > 0 ? sumb - suma - s2 * (m - 1) : 0 - (sumb - suma - s2 * (m - 1));
        temp_sig = 1;
        for (i = 1; i < m - 1; i++) {
            long long token;
            token = sumb - suma - s2 * (m - i - 1) > 0 ? sumb - suma - s2 * (m - i - 1) : 0 - (sumb - suma - s2 * (m - i - 1));
            if (token < temp_val) {
                temp_val = token;
                temp_sig = i + 1;
            }
        }
        if (sumb - suma < temp_val) {
            goto MID;
        }
        printf("%lld", temp_sig);
    } else {
        MID:
        printf("%lld", m);
    }

    return 0;
}