#include <stdio.h>

int main() {
    int A[10], i, j, temp;

    printf("Enter 10 numbers:\n");
    for(i = 0; i < 10; i++) {
        scanf("%d", &A[i]);
    }

    for(i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if(A[i] > A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }

    printf("Sorted \n");
    for(i = 0; i < 10; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}

