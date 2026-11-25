#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    int r, room_no, nights, i, k, found = 0;
    char status, g_name[21], search_name[21];
    float rate;
    char guests[10][21];
    int rooms[10];

    file = fopen("hotel.txt", "w");
    for (i = 101; i <= 110; i++) {
        fprintf(file, "%3d %c %-20s %2d %8.2f\n", i, 'F', "-", 0, 8000.00);
    }
    fclose(file);

    file = fopen("hotel.txt", "rb+");

    for (k = 0; k < 2; k++) {
        printf("Check-in room: ");
        scanf("%d", &r);
        printf("Name: ");
        scanf("%s", g_name);
        printf("Nights: ");
        scanf("%d", &nights);

        fseek(file, (r - 101) * 39, SEEK_SET);
        fscanf(file, "%d %c %s %d %f", &room_no, &status, search_name, &i, &rate);

        if (status == 'F') {
            fseek(file, (r - 101) * 39, SEEK_SET);
            fprintf(file, "%3d %c %-20s %2d %8.2f\n", r, 'B', g_name, nights, 8000.00);
            printf("Room %d booked\n", r);
        } else {
            printf("Room already booked\n");
        }
    }

    rewind(file);
    for (i = 0; i < 10; i++) {
        fscanf(file, "%d %c %s %d %f", &rooms[i], &status, guests[i], &nights, &rate);
    }

    printf("Search name: ");
    scanf("%s", search_name);
    for (i = 0; i < 10; i++) {
        if (strcmp(guests[i], search_name) == 0) {
            printf("%s is in room %d\n", search_name, rooms[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Guest not found\n");
    }

    printf("Check-out room: ");
    scanf("%d", &r);
    fseek(file, (r - 101) * 39, SEEK_SET);
    fscanf(file, "%d %c %s %d %f", &room_no, &status, g_name, &nights, &rate);
    printf("Bill: %d x %.2f = %.2f\n", nights, rate, nights * rate);

    fseek(file, (r - 101) * 39, SEEK_SET);
    fprintf(file, "%3d %c %-20s %2d %8.2f\n", r, 'F', "-", 0, 8000.00);

    fclose(file);
    return 0;
}