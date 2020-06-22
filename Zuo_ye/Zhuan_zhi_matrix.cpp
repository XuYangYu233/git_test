#include<iostream>
int main(){
    int n;
    printf("Input n:");
    scanf("%d",&n);
    int matrix[n][n];
    int tmatrix[n][n];
    printf("Input %d*%d matrix:\n",n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
            tmatrix[j][i] = matrix[i][j];
        }
    }
    printf("The transposed matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%4d",tmatrix[i][j]);
        }
        printf("\n");
    }
    //system("PAUSE");
    return 0;
}