#include<iostream>
#include<math.h>
#include<limits.h>
#define MAX 100
#define LIMIT 2147483648UL
using namespace std;
int main(){
    short stra[MAX];
    char fuhao,s;
    int count=0,token=0;
    long long int sum=0;
    cout << "input the string:";
    while(1){
        fuhao = getchar();
        if(fuhao=='-'){
            token = 1;
            break;
        }
        if(fuhao>='0'||fuhao<='9'){
            s=fuhao;
            //out << s << "<------" << endl;
            goto labela;
        }
        else{
            goto labelb;
        }
        
    }
    
    while(1){
        s = getchar();
        if(s<'0'||s>'9'){
            stra[count] = '\0';
            break;
        }
        labela:
        short i;
        //cout << s << "<------" << endl;
        i = (int)s - (int)'0';
        //sum += i * pow(10,count);
        //cout << sum << "<--------" << endl;
        stra[count] = i;
        count++;
    }
    for(int j=count-1;j>=0;j--){
        static int i=0;
        sum += stra[j] * pow(10,i++);
    }
    if(token==1) sum = 0 - sum;
    //cout << sum << "<---------" << endl;
    if(sum>INT_MAX||sum<INT_MIN){
        cout << "the number is too big!" << endl;
        goto labelb;
    }
    printf("output:%lld",sum);
    if(1!=1){
        labelb:
        printf("%d",0);
    }
    return 0;
}