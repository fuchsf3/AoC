#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
    }

    fclose(fptr);
    return 0;
}
