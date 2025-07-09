#include<stdio.h>
int main(){

	int n,count=0;
	scanf("%d",&n);
	for(int i=5;i<=n;i+=5){
	printf("the series are %d \n",i);
	count++;
	}
	printf("the count is %d",count);
	return 0;

}
