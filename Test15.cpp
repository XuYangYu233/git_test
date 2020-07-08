#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long a;
    long long b;
}ii;

long long x;

/*int cmp(const void *a, const void *b)
{
    return ((ii *)a)->a * x + ((ii *)a)->b - ((ii *)b)->a * x - ((ii *)b)->b;
}*/

int cmp(ii a, ii b)
{
    if(a.a * x + a.b < b.a * x + b.b) {
        return 1;
    } else {
        return 0;
    }
}

void ShellSort(ii R[], long long n){
    long long i,j,d;
    ii tmp;
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            tmp = R[i];
            j = i - d;
            while(j>=0 && cmp(tmp, R[j])==1){
                R[j+d] = R[j];
                j = j - d;
            }
            R[j+d] = tmp;
        }
        d = d / 2;
    }
}

int main()
{
    freopen("test15.txt", "r", stdin);
    int t, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        long long n, j;
        ii arr[10000];
        scanf("%lld %lld", &n, &x);
        //arr = (ii *)calloc(n, sizeof(ii));
        for (j = 0; j < n; j++) {
            scanf("%lld", &(arr[j].a));
        }
        for (j = 0; j < n; j++) {
            scanf("%lld", &(arr[j].b));
        }
        ShellSort(arr, n);
        //qsort(arr, n, sizeof(ii), cmp);
        //QuickSort(arr, 0, n-1);
        for (j = 0; j < n; j++) {
            x = (arr[j].a * x + arr[j].b) % 10;
        }
        printf("%lld\n", x);
    }
    
    return 0;
}