#include<iostream>
using namespace std;

class A{
    public:
    A(int i): va(i){
        cout << "Constracting A " << i << endl;
        count++;
        cout << "Object A count = " << count << endl;
    }
    private:
    int va;
    static int count;
};

int A::count=0;

class B: public A{
    public:
    B(int i, int j): A(i), vb(j){
        cout << "Constructing B " << i << " " << j << endl;
    }
    private:
    int vb;
};

class C{
    public:
    C(int i): vc(i){
        cout << "Constructing C " << i << endl;
    }
    private:
    int vc;
};

class D: public C, public B{
    public:
    D(int a, int b, int c, int d, int e, int f): B(a, b), objb(d, e), objc(f), C(c){
        /*None*/
    }
    private:
    C objc;
    B objb;
};

int main(){
    /*char s[50]="The C++ Programming Language!";
    short *p1=(short *)(s+4),*p2=(short *)(s+20);
    cout << p2-p1 << endl;*/
    //D obj(1, 2, 3, 4, 5, 6);

    return 0;
}