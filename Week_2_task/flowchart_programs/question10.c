#include<stdio.h>
int main(){

	int a,b,i1,i2,i3,i4,i5,i6;
	printf("enter value for i from i1 to i6 one by one \n");
	scanf("%d %d %d %d %d %d",&i1,&i2,&i3,&i4,&i5,&i6);
	a=i1+i2+i4;
	b=i3+i5+i6;
	int c=a-b;
	printf("%d",c);
	return 0;
}
