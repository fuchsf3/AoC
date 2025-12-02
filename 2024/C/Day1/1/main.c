#include <stdio.h>

void sortList(int *list, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                // learned that lately and I really like it
                list[i] = list[i] ^ list[j];
                list[j] = list[i] ^ list[j];
                list[i] = list[i] ^ list[j];
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fptr = fopen("../input.txt", "r");
    if (fptr == NULL) {
        printf("File not found\n");
        return 1;
    }

    int total = 0;
    int number1 = 0;
    int tmp = 0;
    int count = 0;

    // Assuming that there are only 1000 numbers
    int list1[1000] = {0};
    int list2[1000] = {0};

    // Assuming that the numbers are 5 digits long and don't start with 0
    for (char c = fgetc(fptr); c != EOF; c = fgetc(fptr)) {
        if (c == ' ') {
            if (tmp != 0) {
                number1 = tmp;
                tmp = 0;
            }
            continue;
        }

        if (c == '\n') {
            list1[count] = number1;
            list2[count] = tmp;

            printf("Number1: %d\n", number1);
            printf("Number2: %d\n", tmp);
            number1 = 0;
            tmp = 0;

            count++;
            continue;
        }

        // theoretically unnecessary but I like to be safe
        if (c >= '0' && c <= '9') {
            // I don't know why but I love transforming characters to numbers like this
            tmp = tmp * 10 + (c - '0');
            continue;
        }

        printf("Somthing went wrong!\n");
        printf("Character: %d\n", c);
        return 1;
    }

    sortList(list1, count);
    sortList(list2, count);

    for (int i = 0; i < count; i++) {
        total += list1[i] >= list2[i] ? list1[i] - list2[i] : list2[i] - list1[i];
    }

    printf("Total: %d\n", total);

    fclose(fptr);
    return 0;
}
