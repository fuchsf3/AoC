#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    char input[140][140] = {0};

    int total = 0;

    bool is_TopLeftM = false;
    bool is_TopRightM = false;

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
            if (input[y][x] == 'A') {
                if (y - 1 >= 0 && y + 1 < 140 && x - 1 >= 0 && x + 1 < 140) {
                    if ((input[y - 1][x - 1] == 'M' && input[y + 1][x + 1] == 'S') ||
                        (input[y + 1][x + 1] == 'M' && input[y - 1][x - 1] == 'S')) {
                        if ((input[y - 1][x + 1] == 'M' && input[y + 1][x - 1] == 'S') ||
                            (input[y + 1][x - 1] == 'M' && input[y - 1][x + 1] == 'S')) {
                            total++;
                        }
                    }
                }
            }
        }
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
