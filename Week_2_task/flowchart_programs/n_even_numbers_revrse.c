#include<stdio.h>
int main(){

	int n,count=0;
	scanf("%d",&n);
	for(int i=n;i>=2;i-=2){
		printf("%d \n",i);
	count++;
	}
	printf(" count %d",count);
	return 0;
}
