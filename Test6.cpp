#include <stdio.h>
#include <stdlib.h>
void main()
{
	int cNum,n,m,k,Num[20],*s=(int *)malloc(100000*sizeof(int)),*p=Num,sum=0,comSum,judge=1;
	int *s1=s;
	scanf("%d",&cNum);  //要算几组 
	for(n=1;n<=cNum;n++,p++)
	{
		scanf("%d",p);  //每组有几个数 
		for(m=1;m<=*p;m++)
		    scanf("%d",s++);   //这些数分别输入 
	}
	for(n=1;n<=cNum;n++)   //第n个数列的运算 
	{
		printf("Case %d:\n",n);
		for(m=1;m<=Num[n-1];m++)  //以第m个数开头的运算 
		{
            judge=m;
            sum=*(s1+(m-1));  //总和先等于第m个数
            if(m==1) comSum=sum;  //给comSum赋初值，comSum将是整个数列的最大值 
            if((m<Num[n-1])&&(sum+*(s1+m)>sum))   //如果sum+后一个数变大(不是最后一个数) 
            { 
                sum=sum+*(s1+m);  //总和变大
                judge++;  //后一个数的定位
                if(comSum<=sum) comSum=sum;  //更新总和 
                for(k=judge+1;k<=Num[n-1];k++)
                {
                    sum=sum+*(s1+k-1);  //继续加后面的一个数 
                    if(comSum<=sum) 
                    {
                        comSum=sum;
                        judge=k;  //更新最大值所在位置 
                    }
                }
	        }
        else if(m==Num[n-1]) //如果第m个数就是最后一个 
        {
            if(comSum<=sum) comSum=sum;
        }
        else  //如果加后面一个数变小 
        {
            if(comSum<=sum) comSum=sum; //暂时保存最大值
            for(k=judge+1;k<=Num[n-1];k++)
            {
                sum=sum+*(s1+k-1);  //继续加后面的一个数 
                if(comSum<=sum) 
                {
                    comSum=sum;
                    judge=k;  //更新最大值所在位置 
                }
            }
        }
        sum=0;
        } 
        //再重新算一遍，当sum==comSum时停止，从而确定首尾 
        for(m=1;m<=Num[n-1];m++)  //以第m个数开头运算 
        {
            judge=m;
            sum=*(s1+(m-1));   //总和先等于第m个数
            if(sum==comSum) break; //已确定，无需继续计算（题目中只取最靠前一个最大结果） 
            if(m<Num[n-1])  //如果m不是最后一个数 
            {
                for(k=m+1;k<=Num[n-1];k++)
                {
                    sum=sum+*(s1+k-1);   //继续加后一个数，跟comSum比较 
                    if(sum==comSum)
                    {
                        judge=k;
                        break;
                    }
                }
            }
            if(sum==comSum) break;
            sum=0;  //如果sum不是comSum,给sum归零寻找下一轮 
        } 
        printf("%d %d %d\n",comSum,m,judge);
        s1=s1+Num[n-1];   //指针开头移动到第二个数组 
        comSum=0;
        sum=0;
        judge=0;
    }
}
