#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long a, b;
}ii;

void ShellSort(ii R[], long long n){
    long long i,j,d;
    ii tmp;
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            tmp = R[i];
            j = i - d;
            while(j>=0 && tmp.a<R[j].a){
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
    freopen("test16.txt", "r", stdin);
    long long n, i, count = 0;
    ii *arr;
    ii last;
    scanf("%lld", &n);
    arr = (ii *)malloc(n * sizeof(ii));
    for (i = 0; i < n; i++) {
        scanf("%lld %lld", &((arr + i)->a), &((arr + i)->b));
    }
    ShellSort(arr, n);
    last = arr[0];
    count++;
    for (i = 1; i < n; i++) {
        if (arr[i].a >= last.b) {
            last = arr[i];
            count++;
        }
    }
    printf("%lld", count);
    
    return 0;
}