#include<stdio.h>
int main(){

	const int x=10;
	 x=20;
	printf("%d",x); //  nothing will print here because of const
	return 0;

}
