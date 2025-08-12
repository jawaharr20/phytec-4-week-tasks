#include <stdio.h>

int main() {
    FILE *file = fopen("sample.txt", "r");  // Open file for reading
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) { // EOF =end of the file 
        putchar(ch);  // Print each character
    }

    fclose(file);  // Close file
    return 0;
}

