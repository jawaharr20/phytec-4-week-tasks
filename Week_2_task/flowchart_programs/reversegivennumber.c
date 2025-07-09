#include<stdio.h>
int main(){
    int n, rev=0;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != 0) {
        int a = n % 10;          
        rev = rev * 10 + a; 
        n = n / 10;                 
    }

    printf("Reversed number: %d\n", rev);
    
	return 0;
}
