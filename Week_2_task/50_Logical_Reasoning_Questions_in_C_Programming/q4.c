#include<stdio.h>
int main(){

	int a = 5, b = 5;
if (a++ == ++b) // not equal because of post increment operator 
printf("Equal");
else
printf("Not Equal"); 
	return 0;
}
