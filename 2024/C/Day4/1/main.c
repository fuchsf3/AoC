#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    char search[4] = "XMAS";

    char input[140][140] = {0};

    int total = 0;

    int x = 0, y = 0;
    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == '\n') {
            x = 0;
            y++;
            continue;
        }

        if (y == 140) {
            printf("array too small\n");
            break;
        }
        input[y][x] = c;
        x++;
    }

    for (y = 0; y < 140; y++) {
        for (x = 0; x < 140; x++) {
            if (input[y][x] == search[0]) {
                // right
                for (int i = 1; i < 4; i++) {
                    if (x + i >= 140) {
                        break;
                    }
                    if (input[y][x + i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // left
                for (int i = 1; i < 4; i++) {
                    if (x - i < 0) {
                        break;
                    }
                    if (input[y][x - i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // up
                for (int i = 1; i < 4; i++) {
                    if (y - i < 0) {
                        break;
                    }
                    if (input[y - i][x] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // down
                for (int i = 1; i < 4; i++) {
                    if (y + i >= 140) {
                        break;
                    }
                    if (input[y + i][x] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // diagonal up-left
                for (int i = 1; i < 4; i++) {
                    if (y - i < 0 || x - i < 0) {
                        break;
                    }
                    if (input[y - i][x - i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // diagonal up-right
                for (int i = 1; i < 4; i++) {
                    if (y - i < 0 || x + i >= 140) {
                        break;
                    }
                    if (input[y - i][x + i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // diagonal down-left
                for (int i = 1; i < 4; i++) {
                    if (y + i >= 140 || x - i < 0) {
                        break;
                    }
                    if (input[y + i][x - i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
                // diagonal down-right
                for (int i = 1; i < 4; i++) {
                    if (y + i >= 140 || x + i >= 140) {
                        break;
                    }
                    if (input[y + i][x + i] != search[i]) {
                        break;
                    }
                    if (i == 3) {
                        total++;
                    }
                }
            }
        }
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
