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
    cout << "���ϲ����ڿ���!\n�����˻����Ϊ:" << money << "Ԫ" << endl << "��ע���:";
    cin >> temp;
    money -= temp;
    cout << "Ͷע����6λ��Ʊ: ";
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
    cout << "�н��������ڽ���:";
    for(int j=0;j<6;j++){
        cout << *(ans+j) <<" "; 
    }
    cout << "\n����ͬλ����" << count << "λ������ͬ" << endl;
    cout << "������λ����" << count2 << "λ������ͬ" << endl;
    if(count==0&&count2==0) printf("��ϲ�������ƶ���!\n");
    free(six);free(ans);
    money += (count-3)*temp*0.7 + (count2-3)*temp*0.3;
    cout << "����ʣ��" << money << "Ԫ" << endl;
    char still;
    cout << "������?[Y/N]";
    getchar();
    still = getchar();
    if(still=='Y'||still=='y') goto label;
    else cout << "��ӭ�´�����!";
    return 0;
}