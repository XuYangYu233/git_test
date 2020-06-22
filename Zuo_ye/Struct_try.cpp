#include<iostream>
using namespace std;
int main(){
    /*struct Book{
        int a = 111;
        int b = 333;
        char c[4] = "yes";
    }book;*/            //<-Only c++11 can write like this!
    struct Book{
        int a;
        int b;
        char c[40];
    }book={111,333};//,"yes"}; //<-Traditional c and c++ shuold write like this!
    cout<<"input book.c:";
    cin>>book.c;
    cout<<book.a<<"||"<<book.b<<"||"<<book.c<<endl;
    return 0;
}