#include<iostream>
#define num 10
int main(){
    int a[num]={0};
    int i,sum=0,n;
    for(i=0;i<num;i++){
        printf("�������%iλͬѧ�ĳɼ�:",i+1);
        scanf("%d",&a[i]);
        if(a[i]==88){
            printf("jump!\n");
            goto label;
        }
        sum += a[i];
    }
    printf("¼����ɣ�ƽ����Ϊ��%lf\n",(double)sum/num);
    printf("���鳤��Ϊ:%d\n",sizeof(a));
    label:
    printf("��������Ϊ:");
    for(i=0;i<num;i++){
        printf("%d",a[i]);
        if(i==num-1) break;
        printf(",");
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}