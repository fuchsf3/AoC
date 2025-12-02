#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    bool section1 = true;
    bool rules[100][100] = {0};

    int number1 = 0;
    int tmp = 0;

    int statments[60] = {0};
    int statmentIndex = 0;

    int total = 0;

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (section1) {
            if (c == '\n') {
                if (number1 == 0 && tmp == 0) {
                    section1 = false;
                    continue;
                }
                rules[number1][tmp] = true;
                number1 = 0;
                tmp = 0;
                continue;
            }

            if (c == '|') {
                number1 = tmp;
                tmp = 0;
                continue;
            }

            if (c >= '0' && c <= '9') {
                tmp = tmp * 10 + c - '0';
                continue;
            }
        } else {
            if (c == '\n') {
                statments[statmentIndex++] = tmp;
                tmp = 0;
                bool updated = false;
                for (int i = 0; i < statmentIndex; i++) {
                    for (int j = 0; j < i; j++) {

                        if (rules[statments[i]][statments[j]] == true) {
                            statments[i] = statments[i] ^ statments[(i - 1)];
                            statments[(i - 1)] = statments[i] ^ statments[(i - 1)];
                            statments[i] = statments[i] ^ statments[(i - 1)];
                            // restart loops
                            i = 0;
                            j = 0;
                            updated = true;
                        }
                    }
                }
                if (updated) {
                    total += statments[statmentIndex / 2];
                }
                tmp = 0;
                for (int i = 0; i < 60; i++) {
                    statments[i] = 0;
                }
                statmentIndex = 0;
                continue;
            }

            if (c == ',') {
                statments[statmentIndex++] = tmp;
                tmp = 0;
                continue;
            }

            if (c >= '0' && c <= '9') {
                tmp = tmp * 10 + c - '0';
                continue;
            }
        }
    }

    printf("%d\n", total);

    fclose(fptr);
    return 0;
}
