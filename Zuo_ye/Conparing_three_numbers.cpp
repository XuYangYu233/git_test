#include<stdio.h>
#include<stdlib.h>

int maxing(int a,int b)
{
	int maxer;
	if (a > b)
		maxer = a;
	else
		maxer = b;
	return maxer;
}
	
int main()
{
	int a,b,c,maxer;
	scanf("%d,%d,%d",&a,&b,&c);
	maxer = maxing(c,maxing(a,b));
	printf("max=%d\n",maxer);
	system("PAUSE");
	return 0;
}
