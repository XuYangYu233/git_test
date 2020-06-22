#include <iostream>

int main()
{
	int a,b,c;
	printf("input a number that less than 10000:");
	scanf("%d",&a);
	printf("\n");
	b = a/2;
	printf("do xunhuan for %d times\n",b);
	while (1){
		//printf("do xunhuan for %d times\n",b);
		c = a%b;
		//printf("c is %d",c);
		if(c==0){
			printf("not a sushu!\n");
			break;}
		else{
			b--;
			if(b<=1){
				printf("it is a sushu!\n");
				break;}}}
	system("PAUSE");
	return 0;
}

