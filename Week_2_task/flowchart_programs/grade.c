#include<stdio.h>
int main()
{

	int a,s1,s2,s3,s4,s5;
	printf("enter mark one by one \n");
	scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);
	a=(s1+s2+s3+s4+s5)/5;
	printf(" a is %d \n",a);
	if(a<=100 && a>=80)
		printf("grade A");
	else if(a<=79 && a>=60)
		printf("grade b");
	else if(a>=40 && a<=59)
		printf("grade c");
	else
		printf("grade d");
	return 0;
}
