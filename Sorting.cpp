#include<iostream>
#include<time.h>
#include<cstdlib>

typedef int KeyType;
typedef char InfoType;
typedef struct{
    KeyType key;
    InfoType data;
}RecType;

//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(RecType R[], int n){
    int i, j;
    RecType tmp;
    for(i=1;i<n;i++){
        if(R[i].key < R[i-1].key){
            tmp = R[i];
            j = i - 1;
            do{
                R[j+1] = R[j];
                j--;
            }while(j>=0 && R[j].key>tmp.key);
            R[j+1] = tmp;
        }
    }
}

//’€∞Î≤Â»Î≈≈–Ú
void BinInsertSort(RecType R[], int n){
    int i,j,low,high,mid;
    RecType tmp;
    for(i=1;i<n;i++){
        if(R[i].key < R[i-1].key){
            tmp = R[i];
            low = 0;
            high = i - 1;
            while(low <= high){
                mid = (low+high) / 2;
                if(tmp.key < R[mid].key){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            for(j=i-1;j>=high+1;j--){
                R[j+1] = R[j];
            }
            R[high+1] = tmp;
        }
    }
}

//œ£∂˚≈≈–Ú
void ShellSort(RecType R[], int n){
    int i,j,d;
    RecType tmp;
    d = n / 2;
    while(d > 0){
        for(i=d;i<n;i++){
            tmp = R[i];
            j = i - d;
            while(j>=0 && tmp.key<R[j].key){
                R[j+d] = R[j];
                j = j - d;
            }
            R[j+d] = tmp;
        }
        d = d / 2;
    }
}

void swap(RecType &a, RecType &b){
    RecType tmp;
    tmp = a;
    a = b;
    b = tmp;
}

//√∞≈›≈≈–Ú
void BubbleSort(RecType R[], int n){
    int i,j;
    bool exchange;
    for(i=0;i<n-1;i++){
        exchange = false;
        for(j=n-1;j>i;j--){
            if(R[j].key < R[j-1].key){
                swap(R[j], R[j-1]);
                exchange = true;
            }
        }
        if(!exchange){
            return;
        }
    }
}

//øÏÀŸ≈≈–Ú
int partition(RecType R[], int s, int t){
    int i=s, j=t;
    RecType tmp=R[i];
    while(i < j){
        while(j > i && R[j].key >= tmp.key){
            j--;
        }
        R[i] = R[j];
        while(i < j && R[i].key <= tmp.key){
            i++;
        }
        R[j] = R[i];
    }
    R[i] = tmp;
    return i;
}

void QuickSort(RecType R[], int s, int t){
    int i;
    if(s < t){
        i = partition(R, s, t);
        QuickSort(R, s, i-1);
        QuickSort(R, i+1, t);
    }
}

//ºÚµ•—°‘Ò≈≈–Ú
void SelectSort(RecType R[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        k = i;
        for(j=i+1;j<n;j++){
            if(R[j].key < R[k].key){
                k = j;
            }
        }
        if(k != i){
            swap(R[i], R[k]);
        }
    }
}

//∂—≈≈–Ú
void sift(RecType R[], int low, int high){
    int i=low,j=2*i;
    RecType tmp=R[i];
    while(j<=high){
        if(j<high && R[j].key<R[j+1].key){
            j++;
        }
        if(tmp.key<R[j].key){
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else{
            break;
        }
    }
    R[i] = tmp;
}

void HeapSort(RecType R[], int n){
    int i;
    for(i=n/2;i>=1;i--){
        sift(R, i, n);
    }
    for(i=n;i>=2;i--){
        swap(R[1], R[i]);
        sift(R, 1, i-1);
    }
}

//πÈ≤¢≈≈–Ú(∂˛¬∑)
void Merge(RecType R[], int low, int mid, int high){
    RecType *R1;
    int i=low,j=mid+1,k=0;
    R1 = (RecType *)malloc((high-low+1) * sizeof(RecType));
    while(i<=mid && j<=high){
        if(R[i].key <= R[j].key){
            R1[k] = R[i];
            i++;
            k++;
        }
        else{
            R1[k] = R[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        R1[k] = R[i];
        i++;
        k++;
    }
    while(j<=high){
        R1[k] = R[j];
        j++;
        k++;
    }
    for(k=0,i=low;i<=high;k++,i++){
        R[i] = R1[k];
    }
    free(R1);
}

void MergePass(RecType R[], int length, int n){
    int i;
    for(i = 0;i + 2*length - 1 < n;i += 2*length){
        Merge(R, i, i+length-1, i+2*length-1);
    }
    if(i+length-1<n-1){
        Merge(R, i, i+length-1, n-1);
    }
}

void MergeSort(RecType R[], int n){
    int length;
    for(length=1;length<n;length*=2){
        MergePass(R, length, n);
    }
}

int main(){
    RecType R[20];
    int n=20;
    srand((unsigned)time(NULL));
    printf("‘≠ ˝◊È:");
    for(int i=0;i<n;i++){
        int a;
        a = rand() % 100;
        R[i].key = a;
        printf("%2d ",R[i].key);
    }
    printf("\n");
    //InsertSort(R, n);
    //BinInsertSort(R, n);
    ShellSort(R, n);
    //BubbleSort(R, n);
    //QuickSort(R, 0, n-1);
    //SelectSort(R, n);
    //HeapSort(R-1, n);
    //MergeSort(R, n);
    printf("≈≈–Ú∫Û:");
    for(int i=0;i<n;i++){
        printf("%2d ",R[i].key);
    }

    return 0;
}