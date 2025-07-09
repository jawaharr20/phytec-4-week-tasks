#include<stdio.h>
int main(){

	int a,b,c;
	printf("enter 3 number \n");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b && a>c){
	printf("a is bigger");
	}
	else if(b>a && b>c){
	printf("b is bigger");
	}
	else{
	printf("c is big");
	}
	return 0;
}
