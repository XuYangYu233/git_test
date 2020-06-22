#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x=1,y=1;
	for(y=1;y<=11;y++){
		if (y==6){
			for(int n=1;n<=11;n++)
				printf("* ");
				printf("\n");}
		else{
			for(x=1;x<=11;x++){
				if (x==y||x==6||x==12-y)
					printf("* ");
				else
					printf("  ");}
		printf("\n");}}
	system("PAUSE");
	return 0;
}
