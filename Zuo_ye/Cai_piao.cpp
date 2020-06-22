#include<iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
    double money=500,temp;
    label:
    time_t seed;
    int *six,*ans,count=0,count2=0;
    srand(time(&seed));
    six = (int *)calloc(6,sizeof(int));
    ans = (int *)calloc(6,sizeof(int));
    cout << "六合彩现在开奖!\n您的账户余额为:" << money << "元" << endl << "下注金额:";
    cin >> temp;
    money -= temp;
    cout << "投注您的6位彩票: ";
    for(int i=0;i<6;i++){
        int token;
        scanf("%d",&token);
        *(six+i) = token%100;
        *(ans+i) = rand()%100;
        if(*(six+i)==*(ans+i)){
            count++;
        }
    }
    for(int a=0;a<6;a++){
        for(int b=a;b<6;b++){
            if(*(six+a)==*(ans+b)) count2++;
        }
    }
    cout << "中奖号码现在揭晓:";
    for(int j=0;j<6;j++){
        cout << *(ans+j) <<" "; 
    }
    cout << "\n您在同位上有" << count << "位号码相同" << endl;
    cout << "您在异位上有" << count2 << "位号码相同" << endl;
    if(count==0&&count2==0) printf("恭喜您，慈善赌神!\n");
    free(six);free(ans);
    money += (count-3)*temp*0.7 + (count2-3)*temp*0.3;
    cout << "您还剩下" << money << "元" << endl;
    char still;
    cout << "还赌吗?[Y/N]";
    getchar();
    still = getchar();
    if(still=='Y'||still=='y') goto label;
    else cout << "欢迎下次再来!";
    return 0;
}