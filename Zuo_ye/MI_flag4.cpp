#include <iostream>

int main()
{
	int a,b,n;
	for(a=1;a<=11;a++){
		if(a==6){
			for(n=1;n<=11;n++){
				printf("* ");}}
		else{
			for(b=1;b<=11;b++){
				if(b==a||b==6||b==12-a) printf("* ");
				else printf("  ");}}
		printf("\n");}
	system("PAUSE");
	return 0;
}

