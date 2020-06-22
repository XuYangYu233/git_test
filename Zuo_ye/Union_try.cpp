#include<iostream>
using namespace std;
int main(){
    typedef union python_int{
        short int s;
        int i;
        long l;
        long long int ll;
    }Jack;
    Jack pint;
    pint.l = 23123213;
    cout<<pint.l<<" takes "<<sizeof(Jack)<<"kb"<<endl;
    return 0;
}