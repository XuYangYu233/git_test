#include<iostream>
int main()
{
    int a,b;
    for(a=1;a<=9;a++)
    {
        for(b=1;b<=9;b++){
			if(a<b) printf(" ");
            else printf("%d * %d =%2d  ",a,b,a*b);
        }
        printf("\n");
    }
    system("PAUSE");
    return 0;
}
