#include <stdio.h>
#include <string.h>

int countRepeat(char s[], int i) {
    if (s[i] == '\0' || s[i + 1] != s[i]) {
        return 1;
    }
    return 1 + countRepeat(s, i + 1);
}

void compress(char s[], int i, char out[], int j) {
    if (s[i] == '\0') {
        out[j] = '\0';
        return;
    }
    int c = countRepeat(s, i);
    out[j] = s[i];
    out[j + 1] = c + '0';
    compress(s, i + c, out, j + 2);
}

void expand(char in[], int i, char out[], int j) {
    if (in[i] == '\0') {
        out[j] = '\0';
        return;
    }
    int count = in[i + 1] - '0';
    int k;
    for (k = 0; k < count; k++) {
        out[j + k] = in[i];
    }
    expand(in, i + 2, out, j + count);
}

int main() {
    char orig[] = "AAAAAABBBCCCCD";
    char comp[50], exp[50];

    compress(orig, 0, comp, 0);
    expand(comp, 0, exp, 0);

    printf("Original:   %s\n", orig);
    printf("Compressed: %s\n", comp);
    printf("Expanded:   %s\n", exp);

    if (strcmp(orig, exp) == 0) {
        printf("Match: Yes\n");
    } else {
        printf("Match: No\n");
    }

    return 0;
}