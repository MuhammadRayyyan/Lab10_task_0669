#include <stdio.h>

int main() {
    FILE *file;
    char cat[15], cat1[15], cat2[15];
    float amt, amt1, amt2, new_amt, total = 0.0;
    int entry;

    file = fopen("expenses.txt", "w");
    fprintf(file, "%-12s %9.2f\n", "Food", 1200.00);
    fprintf(file, "%-12s %9.2f\n", "Transport", 500.00);
    fprintf(file, "%-12s %9.2f\n", "Books", 850.00);
    fprintf(file, "%-12s %9.2f\n", "Mobile", 300.00);
    fclose(file);

    printf("Category: ");
    scanf("%s", cat);
    printf("Amount: ");
    scanf("%f", &amt);

    file = fopen("expenses.txt", "ab");
    fprintf(file, "%-12s %9.2f\n", cat, amt);
    fclose(file);

    file = fopen("expenses.txt", "rb+");

    fseek(file, -2 * 23, SEEK_END);
    fscanf(file, "%s %f", cat1, &amt1);
    fscanf(file, "%s %f", cat2, &amt2);
    printf("Latest two: %s %.2f, %s %.2f\n", cat1, amt1, cat2, amt2);

    printf("Entry to fix: ");
    scanf("%d", &entry);
    printf("Correct amount: ");
    scanf("%f", &new_amt);

    fseek(file, (entry - 1) * 23, SEEK_SET);
    fscanf(file, "%s %f", cat, &amt);
    fseek(file, (entry - 1) * 23, SEEK_SET);
    fprintf(file, "%-12s %9.2f\n", cat, new_amt);

    rewind(file);
    while (fscanf(file, "%s %f", cat, &amt) == 2) {
        printf("%s %.2f\n", cat, amt);
        total += amt;
    }
    printf("Total: %.2f\n", total);

    fclose(file);
    return 0;
}