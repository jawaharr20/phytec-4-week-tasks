#include <stdio.h>

int main() {
    char item[30];
    int qty;
    float price, total;

    printf("Enter item name: ");
    scanf("%s", item);
    printf("Enter quantity: ");
    scanf("%d", &qty);
    printf("Enter unit price: ");
    scanf("%f", &price);

    total = qty * price;

    printf("Item: %s\nQuantity: %d\nUnit Price: ₹%.2f\nTotal: ₹%.2f\n", item, qty, price, total);

    return 0;
}

