#include<stdio.h>
int main(){

	int a,b;
	printf(" enter 2 number \n");
	scanf("%d %d",&a,&b);
	if(a==b){
	printf("both are equal");
	}
	else if(a>b){
	
		printf("a is bigger");
	}
	else{
	printf("b is big");
	}

	return 0;
}
