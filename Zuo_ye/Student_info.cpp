#include<iostream>
using namespace std;
typedef struct stu{
    long number;
    char name[16];
    float score[3],aver;
}STU;
int main(){
    STU set[1000];
    short count=0;
    while(1){
        char token='y';
        cout << "Input a student?[y/n]";
        scanf("%c",&token);
        if(token=='n'){
            cout << "Exit!" << endl;
            getchar();
            break;
        }
        if(token=='y'){
            cout << "Input xuehao:";
            cin >> set[count].number;
            cout << "Input name:";
            cin >> set[count].name;
            cout << "Input score of Yuwen,Math and English:";
            cin >> set[count].score[0] >> set[count].score[1] >> set[count].score[2];
            set[count].aver = (set[count].score[0]+set[count].score[1]+set[count].score[2])/3;
            cout << "Aver_score is " << set[count].aver << endl;
            count++;
            cout << "Successfully contained!" << endl;
        }
        else{
            cout << "Input error!try again!" << endl;
        }
        getchar();
    }
    while(1){
        char st='y';
        cout << "Search student?[y/n]";
        scanf("%c",&st);
        if(st=='n'){
            cout << "Exit!" << endl;
            break;
        }
        if(st=='y'){
            long temp;
            cout << "Input xuehao:";
            cin >> temp;
            for(int i=0;i<count;i++){
                if(temp==set[i].number){
                    cout << "Student found:name:" << set[i].name << endl << "              Yuwen score:" << set[i].score[0] << " Math score:" << set[i].score[1] << " English score:" << set[i].score[2] << endl << "              Aver score:" << set[i].aver << endl;
                    break;
                }
            }
        }
        else{
            cout << "Input error!" << endl;
        }
        getchar();
    }
    cout << "End" << endl;

    return 0;
}