#include<iostream>
#include<cstring>
using namespace std;

/*enum WEEK {
    Monday=1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};*/

enum WEEK {Mon,Tue,Wed,Thu,Fri,Sat,Sun};

int main(){
    WEEK wekk;
    char dayname[4];
    short weksig;
    cout << "输入星期X之后第d天:" << endl << "X:";
    cin >> dayname;
    cout << "d:";
    cin >> weksig;
    char *wekname[7]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    short i=0;
    for(;i<7;i++){
        if(!strcmp(dayname,wekname[i])){
            wekk = (enum WEEK)i;
            break;
        }
    }
    cout << i << endl;
    weksig %= 7;
    if(weksig + i >=7){
        wekk = (enum WEEK)((weksig + i) % 7);
    }
    else{
        wekk = (enum WEEK)(weksig + i);
    }
    cout << "answer is " << wekname[wekk] << endl;
    return 0;
}