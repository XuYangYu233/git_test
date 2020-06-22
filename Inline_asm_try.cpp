// compile only in x86
#include<iostream>

int main(){
    int a=7;
    _asm{
        mov     ax, word ptr [a]
        inc     ax
        mov     word ptr [a], ax
    }
    printf("%d",a);

    return 0;
}