#include <stdio.h>

int is_prime(int a) {
    if (a <= 1) {
        return 0; 
    }
    
    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    if (is_prime(n)) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}

