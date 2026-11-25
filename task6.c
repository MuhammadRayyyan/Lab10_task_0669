#include <stdio.h>

void grow(int heights[], int n) {
    if (n == 0) return;
    heights[n - 1] += (int)(heights[n - 1] * 0.10);
    grow(heights, n - 1);
}

int tallest(int heights[], int n) {
    if (n == 1) return 0;
    int max_pos = tallest(heights, n - 1);
    if (heights[n - 1] > heights[max_pos]) {
        return n - 1;
    }
    return max_pos;
}

int search(int heights[], int n, int target) {
    if (n == 0) return -1;
    if (heights[n - 1] == target) return n - 1;
    return search(heights, n - 1, target);
}

int main() {
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};
    int i, t_pos, target, s_pos;

    grow(heights, 6);

    printf("New heights: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", heights[i]);
    }
    printf("\n");

    t_pos = tallest(heights, 6);
    printf("Tallest: tower %d (%d m)\n", ids[t_pos], heights[t_pos]);

    printf("Height to search: ");
    scanf("%d", &target);
    s_pos = search(heights, 6, target);

    if (s_pos != -1) {
        printf("Tower %d is %d m\n", ids[s_pos], target);
    } else {
        printf("No tower has that height\n");
    }

    return 0;
}