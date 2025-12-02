#include <stdbool.h>
#include <stdio.h>

#define MAX 130

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    // 0: empty, 1: Wall, 2: visited
    int map[MAX][MAX] = {0};
    int mapColumnIndex = 0;
    int mapRowIndex = 0;

    int positionSecurityX = 0;
    int positionSecurityY = 0;
    int direction = 0; // 1: Up, 2: Right, 3: Down 4: Left

    int total = 1;

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == '.') {
            mapColumnIndex++;
            continue;
        }

        if (c == '#') {
            map[mapRowIndex][mapColumnIndex] = 1;
            mapColumnIndex++;
            continue;
        }

        if (c == '^') {
            positionSecurityX = mapColumnIndex;
            positionSecurityY = mapRowIndex;
            direction = 1;

            map[mapRowIndex][mapColumnIndex] = 2;
            mapColumnIndex++;
            continue;
        }

        if (c == '\n') {
            mapRowIndex++;
            mapColumnIndex = 0;
            continue;
        }
    }

    while (true) {
        switch (direction) {
        case 1:
            positionSecurityY--;
            break;
        case 2:
            positionSecurityX++;
            break;
        case 3:
            positionSecurityY++;
            break;
        case 4:
            positionSecurityX--;
            break;
        }

        if (positionSecurityX < 0 || positionSecurityY < 0 || positionSecurityX > MAX ||
            positionSecurityY > MAX) {
            break;
        }

        if (map[positionSecurityY][positionSecurityX] == 1) {
            switch (direction) {
            case 1:
                direction = 2;
                positionSecurityY++;
                break;
            case 2:
                direction = 3;
                positionSecurityX--;
                break;
            case 3:
                direction = 4;
                positionSecurityY--;
                break;
            case 4:
                direction = 1;
                positionSecurityX++;
                break;
            default:
                printf("Invalid direction\n");
                return 1;
            }
            continue;
        }

        if (map[positionSecurityY][positionSecurityX] == 0) {
            map[positionSecurityY][positionSecurityX] = 2;
            total += 1;
            continue;
        }
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
