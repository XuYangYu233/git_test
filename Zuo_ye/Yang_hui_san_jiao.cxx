#include <iostream>

long int jiecheng(long int shu)
{
	long int jieguo=1;
	for(;shu>0;shu--){
		jieguo = jieguo * shu;}
	return jieguo;
}

long int zuheshu(long int n,long int m)
{
	long int cnm;
	cnm = jiecheng(m)/(jiecheng(m-n)*jiecheng(n));
	return cnm;
}

int main()
{
	long int a,b,c,hangshu;
	printf("please input hangshu:");
	scanf("%ld",&hangshu);
	for(a=1;a<=hangshu;a++){
		c = hangshu-a;
		for(;c>0;c--){
			printf("   ");
		}
		for(b=0;b<a;b++){
			printf("   %3ld",zuheshu(b,a-1));
		}
		printf("\n");
	}
	system("PAUSE");
	return 0;
}//输入大于13的行数会产生bug，有待进一步解决
