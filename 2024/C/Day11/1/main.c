#include <limits.h>
#include <stdio.h>

int numberOfDigits(int n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

int resolveStone(unsigned long long number, int blinks) {
    if (blinks == 0) {
        return 1;
    }
    if (number == 0) {
        return resolveStone(1, blinks - 1);
    }
    // I did't now that you can assign a value in if statement like this
    int nOD;
    if ((nOD = numberOfDigits(number)) % 2 == 0) {
        int divisor = 1;
        for (int k = 0; k < nOD / 2; k++) {
            divisor *= 10;
        }
        return resolveStone(number / divisor, blinks - 1) +
               resolveStone(number % divisor, blinks - 1);
    }
    if (number > ULLONG_MAX / 2024) {
        // :(
        printf("Overflow detected for number %llu at blinks %d\n", number, blinks);
        return 0;
    }
    return resolveStone(number * 2024, blinks - 1);
}

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    int map[10] = {0};
    int mapIndex = 0;

    int tmp = 0;

    int total = 0;
    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == ' ') {
            map[mapIndex++] = tmp;
            tmp = 0;
            continue;
        }

        if (c >= '0' && c <= '9') {
            tmp = tmp * 10 + (c - '0');
            continue;
        }
    }
    map[mapIndex++] = tmp;
    tmp = 0;

    for (int i = 0; i < mapIndex; i++) {
        printf("Map: %d\n", map[i]);
        total += resolveStone(map[i], 25);
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
