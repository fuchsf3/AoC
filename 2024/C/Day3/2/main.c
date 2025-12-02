#include <stdbool.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    // I think regex would be better and a made a patern for it("mul\(([^,]+),([^,]+)\)"), but I
    // don't know how to use it in C and I think it's not cool enough

    char mulSequence[4] = "mul(";
    char doSequence[4] = "do()";
    char dontSequence[7] = "don't()";

    short mulSequenceIndex = 0;
    short doSequenceIndex = 0;
    short dontSequenceIndex = 0;

    unsigned int total = 0;

    bool is_On = true;
    bool is_Valid = true;

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == mulSequence[mulSequenceIndex] && is_On) {
            mulSequenceIndex++;
            if (mulSequenceIndex == 4) {
                mulSequenceIndex = 0;
                bool is_Valid = true;

                int var1 = 0, var2 = 0;

                for (c = fgetc(fptr); c != ','; c = fgetc(fptr)) {
                    if (c >= '0' && c <= '9') {
                        var1 = var1 * 10 + c - '0';
                    } else {
                        printf("invalid Character\n");
                        is_Valid = false;
                        break;
                    }
                }
                if (!is_Valid) {
                    continue;
                }

                for (c = fgetc(fptr); c != ')'; c = fgetc(fptr)) {
                    if (c >= '0' && c <= '9') {
                        var2 = var2 * 10 + c - '0';
                    } else {
                        printf("invalid Character\n");
                        is_Valid = false;
                        break;
                    }
                }
                if (!is_Valid) {
                    continue;
                }

                if (var1 == 0 || var2 == 0) {
                    printf("something is 0\n");
                    continue;
                }

                printf("a: %d b: %d = ", var1, var2);
                printf("%d\n", var1 * var2);
                total += var1 * var2;
            }
            continue;
        } else {
            mulSequenceIndex = 0;
        }

        if (c == doSequence[doSequenceIndex] && !is_On) {
            doSequenceIndex++;
            if (doSequenceIndex == 4) {
                is_On = true;
                doSequenceIndex = 0;
            }
            continue;
        } else {
            doSequenceIndex = 0;
        }

        if (c == dontSequence[dontSequenceIndex] && is_On) {
            dontSequenceIndex++;
            if (dontSequenceIndex == 7) {
                is_On = false;
                dontSequenceIndex = 0;
            }
            continue;
        }

        dontSequenceIndex = 0;
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
