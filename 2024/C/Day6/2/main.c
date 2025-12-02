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

    int total = 0;

    int stepsOnVisited = 0;
    int mapClone[MAX][MAX] = {0};
    int positionSecurityXClone = 0;
    int positionSecurityYClone = 0;

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

    for (int i = 0; i < MAX * MAX; i++) {
        direction = 1;
        positionSecurityYClone = positionSecurityY;
        positionSecurityXClone = positionSecurityX;
        stepsOnVisited = 0;
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                if ((j * (MAX - 1)) + k == i && map[j][k] != 2) {
                    mapClone[j][k] = 1;
                    continue;
                }
                mapClone[j][k] = map[j][k];
            }
        }
        while (true) {
            switch (direction) {
            case 1:
                positionSecurityYClone--;
                break;
            case 2:
                positionSecurityXClone++;
                break;
            case 3:
                positionSecurityYClone++;
                break;
            case 4:
                positionSecurityXClone--;
                break;
            }

            if (positionSecurityXClone < 0 || positionSecurityYClone < 0 ||
                positionSecurityXClone > MAX || positionSecurityYClone > MAX) {
                break;
            }

            if (mapClone[positionSecurityYClone][positionSecurityXClone] == 1) {
                switch (direction) {
                case 1:
                    direction = 2;
                    positionSecurityYClone++;
                    break;
                case 2:
                    direction = 3;
                    positionSecurityXClone--;
                    break;
                case 3:
                    direction = 4;
                    positionSecurityYClone--;
                    break;
                case 4:
                    direction = 1;
                    positionSecurityXClone++;
                    break;
                default:
                    printf("Invalid direction\n");
                    return 1;
                }
                continue;
            }

            if (mapClone[positionSecurityYClone][positionSecurityXClone] == 0) {
                mapClone[positionSecurityYClone][positionSecurityXClone] = 2;
                continue;
            }

            if (mapClone[positionSecurityYClone][positionSecurityXClone] == 2) {
                stepsOnVisited++;
                if (stepsOnVisited == 10000) {
                    stepsOnVisited = 0;

                    total++;
                    break;
                }
            } else {
                stepsOnVisited = 0;
                continue;
            }
        }
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
