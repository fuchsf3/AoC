#include <stdbool.h>
#include <stdio.h>

enum STATE { NONE, DECREASING, INCREASING };

int main() {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    int tmp = 0;
    enum STATE state = NONE;
    bool is_safe = true;

    int line[50] = {0};
    int lineIndex = 0;

    int total = 0;

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == '\n') {
            is_safe = true;
            state = NONE;

            line[lineIndex++] = tmp;
            tmp = 0;

            int div[50] = {0};
            for (int i = 0; i < lineIndex - 1; i++) {
                div[i] = line[i + 1] - line[i];
                if (div[i] == 0 || (div[i] < -3 || div[i] > 3)) {
                    is_safe = false;
                }
            }

            if (is_safe) {
                for (int i = 0; i < lineIndex - 1; i++) {
                    if (state == NONE) {
                        state = (div[i] > 0) ? INCREASING : DECREASING;
                    } else if ((state == INCREASING && div[i] <= 0) ||
                               (state == DECREASING && div[i] >= 0)) {
                        is_safe = false;
                    }
                }
            }

            if (is_safe) {
                total++;
            }

            for (int i = 1; i < lineIndex; i++) {
                line[i] = 0;
            }
            lineIndex = 0;
            continue;
        }

        if (c == ' ') {
            line[lineIndex++] = tmp;
            tmp = 0;
            continue;
        }

        if (c >= '0' && c <= '9') {
            tmp = tmp * 10 + (c - '0');
            continue;
        }
    }

    printf("Total: %d\n", total);
    fclose(fptr);
    return 0;
}
