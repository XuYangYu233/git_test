#include<stdio.h>
#include<string.h>
const char *path="myfile.txt";
char s[2000];
char c;	
int main()
{
	
	FILE * fp=fopen(path,"r");
	if(fp==NULL)
		printf("error: file not found");
	/*
	˵����scanf(%s)�����ո� fscanf(%c)����
			^\n��ʾ��������Ϊֹ ����%c�Ե���ĩ�Ļس� ����ѭ������?
            				windows�»�����\r\n ���س����У�
            				linux: \n Mac��\r
	*/
	while(fscanf(fp,"%[^\r\n]%c",&s,&c)!=EOF)
	{		
		if(s!="")		 	
		{
			fputs(s,stdout);
			printf("\n");
			memset(s,0,sizeof(char));
		}	
		else
			printf("error: no content");		
	}
	fclose(fp);
	return 0;	
}