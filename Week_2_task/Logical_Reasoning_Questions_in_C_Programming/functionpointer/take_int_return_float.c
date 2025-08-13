#include<stdio.h>
float add(int a,int b){

	return a+b;
}
int main(){

	float (* af)(int ,int);
	af=add;
	printf(" %f  \n",af(5,5));

	return 0;
}
