#include<stdio.h>
int fact(int a){
	 if (a == 0 || a == 1) 
        return 1;
    else
return a*fact(a-1);
}
int main(){

	int n;
	printf("enter a number ");
	scanf("%d",&n);
	printf("the factorial of a given number is %d ",fact(n));
		return 0;
}

