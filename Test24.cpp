#include <stdio.h>

typedef struct {
    int q, p;
}ii;

void ShellSort(ii R[], int n){
    int i,j,d;
    ii tmp;
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            tmp = R[i];
            j = i - d;
            while(j>=0 && tmp.q<R[j].q){
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
    freopen("test24.txt", "r", stdin);
    int n, k, i, j = 0;
    long long time = 0;
    char temp[] = "Register";
    ii missions[50005];
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s %d %d", temp, &missions[i].q, &missions[i].p);
    }
    ShellSort(missions, n);
    while (j < k) {
        time++;
        for (i = 0; i < n; i++) {
            if (time % missions[i].p == 0) {
                printf("%d\n", missions[i].q);
                j++;
                if (j >= k) {
                    break;
                }
            }
        }
    }
    
    return 0;
}