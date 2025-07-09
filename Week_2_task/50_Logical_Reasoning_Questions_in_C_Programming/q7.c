#include<stdio.h>
int main(){

	int arr[] = {1, 2, 3, 4};
printf("%d", *(arr + 2));  //because it is accessing by pointer . pointer points to first position 
// defaulty so +2 goes to 3 position
	return 0;
}
