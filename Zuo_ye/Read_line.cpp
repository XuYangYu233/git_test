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
	说明：scanf(%s)不读空格 fscanf(%c)可以
			^\n表示读到换行为止 加上%c吃掉行末的回车 可以循环读行?
            				windows下换行是\r\n （回车换行）
            				linux: \n Mac：\r
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