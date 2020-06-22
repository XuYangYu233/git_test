#include<iostream>
#define num 10
int main(){
    int a[num]={0};
    int i,sum=0,n;
    for(i=0;i<num;i++){
        printf("请输入第%i位同学的成绩:",i+1);
        scanf("%d",&a[i]);
        if(a[i]==88){
            printf("jump!\n");
            goto label;
        }
        sum += a[i];
    }
    printf("录入完成，平均分为：%lf\n",(double)sum/num);
    printf("数组长度为:%d\n",sizeof(a));
    label:
    printf("数组内容为:");
    for(i=0;i<num;i++){
        printf("%d",a[i]);
        if(i==num-1) break;
        printf(",");
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}