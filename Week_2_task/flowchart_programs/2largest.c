#include <stdio.h>

int main() {
    int a, b, c, d, temp;
    int arr[4];

    printf("Enter 4 numbers: ");
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);

    // Simple bubble sort for 4 elements
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 4; j++) {
            if(arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Second largest number: %d\n", arr[1]);

    return 0;
}

