#include<stdio.h>
int add(int a,int b){

	return a+b;
}
int sub(int a,int b){

	return a-b;
}
int mul (int a,int b)
{

	return a*b;
}
int div(int a,int b){

	if(b!=0){
	
		return a/b;
	}
}

int main(){

	int (* fp[4])={add,sub,mul,div};
	int ch;
	scanf("%d",&ch);
	int a=5,b=5;
	printf("%d",fp[ch](a,b));
	return 0;

}

