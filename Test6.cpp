#include <stdio.h>
#include <stdlib.h>
void main()
{
	int cNum,n,m,k,Num[20],*s=(int *)malloc(100000*sizeof(int)),*p=Num,sum=0,comSum,judge=1;
	int *s1=s;
	scanf("%d",&cNum);  //Ҫ�㼸�� 
	for(n=1;n<=cNum;n++,p++)
	{
		scanf("%d",p);  //ÿ���м����� 
		for(m=1;m<=*p;m++)
		    scanf("%d",s++);   //��Щ���ֱ����� 
	}
	for(n=1;n<=cNum;n++)   //��n�����е����� 
	{
		printf("Case %d:\n",n);
		for(m=1;m<=Num[n-1];m++)  //�Ե�m������ͷ������ 
		{
            judge=m;
            sum=*(s1+(m-1));  //�ܺ��ȵ��ڵ�m����
            if(m==1) comSum=sum;  //��comSum����ֵ��comSum�����������е����ֵ 
            if((m<Num[n-1])&&(sum+*(s1+m)>sum))   //���sum+��һ�������(�������һ����) 
            { 
                sum=sum+*(s1+m);  //�ܺͱ��
                judge++;  //��һ�����Ķ�λ
                if(comSum<=sum) comSum=sum;  //�����ܺ� 
                for(k=judge+1;k<=Num[n-1];k++)
                {
                    sum=sum+*(s1+k-1);  //�����Ӻ����һ���� 
                    if(comSum<=sum) 
                    {
                        comSum=sum;
                        judge=k;  //�������ֵ����λ�� 
                    }
                }
	        }
        else if(m==Num[n-1]) //�����m�����������һ�� 
        {
            if(comSum<=sum) comSum=sum;
        }
        else  //����Ӻ���һ������С 
        {
            if(comSum<=sum) comSum=sum; //��ʱ�������ֵ
            for(k=judge+1;k<=Num[n-1];k++)
            {
                sum=sum+*(s1+k-1);  //�����Ӻ����һ���� 
                if(comSum<=sum) 
                {
                    comSum=sum;
                    judge=k;  //�������ֵ����λ�� 
                }
            }
        }
        sum=0;
        } 
        //��������һ�飬��sum==comSumʱֹͣ���Ӷ�ȷ����β 
        for(m=1;m<=Num[n-1];m++)  //�Ե�m������ͷ���� 
        {
            judge=m;
            sum=*(s1+(m-1));   //�ܺ��ȵ��ڵ�m����
            if(sum==comSum) break; //��ȷ��������������㣨��Ŀ��ֻȡ�ǰһ��������� 
            if(m<Num[n-1])  //���m�������һ���� 
            {
                for(k=m+1;k<=Num[n-1];k++)
                {
                    sum=sum+*(s1+k-1);   //�����Ӻ�һ��������comSum�Ƚ� 
                    if(sum==comSum)
                    {
                        judge=k;
                        break;
                    }
                }
            }
            if(sum==comSum) break;
            sum=0;  //���sum����comSum,��sum����Ѱ����һ�� 
        } 
        printf("%d %d %d\n",comSum,m,judge);
        s1=s1+Num[n-1];   //ָ�뿪ͷ�ƶ����ڶ������� 
        comSum=0;
        sum=0;
        judge=0;
    }
}
