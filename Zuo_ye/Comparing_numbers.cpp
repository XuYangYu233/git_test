#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a,b,m;
	scanf("%d,%d",&a,&b);
	if(a > b)
		m = a;
	else
		m = b;
	printf("max=%d\n",m);
	system("PAUSE");
	return 0;
}
/* g++ -Wall -o "%e.exe" "%f"*/
/*D:\Language\devcpp_setup\MinGW64\bin\g++ "%f"*/
/*D:\Language\devcpp_setup\devcpp "%f"*/
/*".\%e.exe"*/
