#include<stdio.h>
int main(){

	int a,count=0;
	printf("enter a number ");
	scanf("%d",&a);
	while(a!=0){
		a/=10;
		count++;


	}
	printf("%d",count);
	return 0;
}
