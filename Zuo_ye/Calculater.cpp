#include<iostream>
#include<math.h>
double kaifang(double a){
    return sqrt(a);
}
double daoshu(double a){
    return 1/a;
}
int baifenshu(double a){
    printf("%lf",a*100);
    printf("%");
    return 0;
}
int main(){
    int n;
    printf("which calculating?\n0.+\n1.-\n2.*\n3./\n4.kaifang\n5.daoshu\n6.baifenshu\n");
    scanf("%d",&n);
    if(n==0||n==1||n==2||n==3){
        double a,b;
        printf("input numbers a,b:");
        scanf("%lf,%lf",&a,&b);
        switch (n)
        {
        case 0:
            printf("%lf+%lf=%lf",a,b,a+b);
            break;
        case 1:
            printf("%lf-%lf=%lf",a,b,a-b);
            break;
        case 2:
            printf("%lf*%lf=%lf",a,b,a*b);
            break;
        case 3:
            printf("%lf/%lf=%lf",a,b,a/b);
            break;
        default:
            printf("input error");
            break;
        }
    }
    else{
        double a;
        printf("input the number a:");
        scanf("%lf",&a);
        switch (n)
        {
        case 4:
            printf("%lf**0.5=%lf",a,sqrt(a));
            break;
        case 5:
            printf("1/%lf=%lf",a,daoshu(a));
            break;
        case 6:
            baifenshu(a);
        default:
            break;
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}