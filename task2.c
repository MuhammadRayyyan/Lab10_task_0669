#include <stdio.h>

int main() {
    FILE *file;
    int r, extra, std_roll, classes;
    char std_name[20];
    float avg;

    file = fopen("attendance.txt", "w");
    fprintf(file, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(file, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(file, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(file, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(file, "%-3d %-15s %3d\n", 5, "Zainab", 16);
    fclose(file);

    file = fopen("attendance.txt", "rb+");

    printf("Roll number: ");
    scanf("%d", &r);

    fseek(file, (r - 1) * 24, SEEK_SET);
    fscanf(file, "%d %s %d", &std_roll, std_name, &classes);

    avg = (classes / 20.0) * 100;
    printf("%s: %d / 20 (%.1f%%)", std_name, classes, avg);
    if (avg < 75.0) {
        printf(" Short attendance");
    }
    printf("\n");

    printf("Roll number for leave: ");
    scanf("%d", &r);
    printf("Lectures: ");
    scanf("%d", &extra);

    fseek(file, (r - 1) * 24, SEEK_SET);
    fscanf(file, "%d %s %d", &std_roll, std_name, &classes);

    classes = classes + extra;

    fseek(file, (r - 1) * 24, SEEK_SET);
    fprintf(file, "%-3d %-15s %3d\n", std_roll, std_name, classes);

    avg = (classes / 20.0) * 100;
    printf("%s: now %d / 20 (%.1f%%)\n", std_name, classes, avg);

    fseek(file, -24, SEEK_END);
    fscanf(file, "%d %s %d", &std_roll, std_name, &classes);
    printf("Last record: %d %s %d\n", std_roll, std_name, classes);

    fclose(file);
    return 0;
}