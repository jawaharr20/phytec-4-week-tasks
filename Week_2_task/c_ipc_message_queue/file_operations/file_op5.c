#include <stdio.h>

int main() {
    FILE *file = fopen("sample.txt", "r");
    if (file == NULL) {
        printf("Can't open file.\n");
        return 1;
    }

    int lines = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') lines++;
    }

    printf("Number of lines: %d\n", lines + 1);  // Last line may not end in '\n'
    fclose(file);
    return 0;
}

