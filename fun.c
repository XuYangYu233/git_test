//extern int a;
//extern int b;
static int a=3,b=3;
int fun(int n){
    a *= n;
    b = a+ 1;
    return b;
}