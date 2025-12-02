#include <stdbool.h>
#include <stdio.h>

#define MAX 47

struct TURNINGPOINT {
    int x, y, number;
};

// trying to use more functions

// recursion baby!!!
void findTrails(struct TURNINGPOINT turningPoint, int map[MAX][MAX], bool visited[MAX][MAX],
                bool reachable[MAX][MAX]) {
    visited[turningPoint.y][turningPoint.x] = true;

    if (turningPoint.number == 9) {
        reachable[turningPoint.y][turningPoint.x] = true;
        return;
    }

    int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    for (int i = 0; i < 4; i++) {
        int x = turningPoint.x + directions[i][0];
        int y = turningPoint.y + directions[i][1];

        if (x >= 0 && x < MAX && y >= 0 && y < MAX && !visited[y][x] &&
            map[y][x] == turningPoint.number + 1) {
            struct TURNINGPOINT nextPoint = {x, y, turningPoint.number + 1};
            findTrails(nextPoint, map, visited, reachable);
        }
    }

    visited[turningPoint.y][turningPoint.x] = false;
}

int calculateScore(int x, int y, int map[MAX][MAX]) {
    bool visited[MAX][MAX] = {false};
    bool reachable[MAX][MAX] = {false};

    struct TURNINGPOINT start = {x, y, 0};
    findTrails(start, map, visited, reachable);

    int score = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (reachable[i][j]) {
                score++;
            }
        }
    }
    return score;
}

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    int map[MAX][MAX] = {0};
    int x = 0, y = 0;

    int total = 0;

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == '\n') {
            y++;
            x = 0;
            continue;
        }
        map[y][x] = c - '0';
        x++;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (map[i][j] == 0) {
                total += calculateScore(j, i, map);
            }
        }
    }

    printf("Total: %d\n", total);
    fclose(fptr);
    return 0;
}
