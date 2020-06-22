#include<iostream>
int main(){
	//int arr[]={1,3,5,7,9};
	int *arr;
	arr = (int *)malloc(5*4);
	arr[0] = 1;
	printf("size of int is %lld\n",sizeof(int));
	printf("size of long is %lld\n",sizeof(long int));
	printf("size of short is %lld\n",sizeof(short));
	printf("size of char is %lld\n",sizeof(char));
	printf("size of float is %lld\n",sizeof(float));
	printf("size of double is %lld\n",sizeof(double));
	printf("size of array is %d\n",sizeof(arr));
}
