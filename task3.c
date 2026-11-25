#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char city[15], hot_city[15];
    float temp, new_temp, max_temp = -999.0;
    int num, i;

    file = fopen("temperature.txt", "w");
    for (i = 0; i < 5; i++) {
        printf("Enter city %d name and temp: ", i + 1);
        scanf("%s %f", city, &temp);
        fprintf(file, "%-10s %5.1f\n", city, temp);
    }
    fclose(file);

    file = fopen("temperature.txt", "rb+");

    printf("City number: ");
    scanf("%d", &num);
    fseek(file, (num - 1) * 17, SEEK_SET);
    fscanf(file, "%s %f", city, &temp);
    printf("%s %.1f\n", city, temp);

    printf("City number to correct: ");
    scanf("%d", &num);
    printf("New temperature: ");
    scanf("%f", &new_temp);

    fseek(file, (num - 1) * 17, SEEK_SET);
    fscanf(file, "%s %f", city, &temp);
    fseek(file, (num - 1) * 17, SEEK_SET);
    fprintf(file, "%-10s %5.1f\n", city, new_temp);
    printf("%s updated to %.1f\n", city, new_temp);

    rewind(file);
    for (i = 0; i < 5; i++) {
        fscanf(file, "%s %f", city, &temp);
        if (temp > max_temp) {
            max_temp = temp;
            strcpy(hot_city, city);
        }
    }
    printf("Hottest city: %s (%.1f)\n", hot_city, max_temp);

    fclose(file);
    return 0;
}