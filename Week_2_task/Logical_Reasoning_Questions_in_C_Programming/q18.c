#include<stdio.h>
int main(){

	int *ptr;
	*ptr=5;
	printf("%ls",ptr);  // You declared a pointer, but it’s uninitialized.
                            //It points to some random garbage memory.
	return 0;
}
