#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    
    if (age <= 5) {
        printf("Nice child\n");
    } else if (age <= 10) {
        printf("Nice kid\n");
    } else if (age <= 15) {
        printf("Teenager\n");
    } else if (age <= 25) {
        printf("Young Dynamic\n");
    } else if (age <= 50) {
        printf("Middle Age\n");
    } else {
        printf("Old\n");
    }

    return 0;
}

