#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[100][1000] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < n; i++) {
        char *index = &arr[i][0];
        if (*index != 'B') {
            index++;
        }
        if (!strncmp(index, "Ban_smoking", 11)) {
            printf("%s\n", index);
        }
    }
    return 0;
}
