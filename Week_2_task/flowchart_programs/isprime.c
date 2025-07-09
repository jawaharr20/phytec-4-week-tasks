#include <stdio.h>

int main() {
    int count = 0, num = 2, i, isPrime;

    printf("First 20 prime numbers:\n");
    while(count < 20) {
        isPrime = 1;
        for(i = 2; i <= num / 2; i++) {
            if(num % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if(isPrime) {
            printf("%d ", num);
            count++;
        }

        num++;
    }

    printf("\n");
    return 0;
}

