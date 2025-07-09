#include <stdio.h>

int main() {
    int n, rev = 0, a, ori;

    printf("Enter a number: ");
    scanf("%d", &n);

    ori = n;

    while (n != 0) {
        a = n % 10;
        rev = rev * 10 + a;
        n = n / 10;
    }

    if (ori == rev)
        printf("Palindrome \n");
    else
        printf("Not a palindrome \n");

    return 0;
}

