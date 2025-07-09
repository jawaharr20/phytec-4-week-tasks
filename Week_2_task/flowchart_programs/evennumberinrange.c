#include<stdio.h>
int main(){

	int n,count=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i+=2){
		printf("the even numbers in a range %d \n",i);
	count++;
	}
	printf(" count is %d",count);
	return 0
		;

}
