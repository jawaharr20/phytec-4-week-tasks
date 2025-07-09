#include<stdio.h>
int main(){

	int n,count=0;
	printf("enter a number ");
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		printf("%d \n ",i);

		count++;
	}
	printf("count %d",count);
	
}
