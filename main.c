#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "functions.c"

int main() {
    char name1[100], name2[100];
    printf("Enter name1: ");
    fgets(name1, 100, stdin);
    name1[strcspn(name1, "\n")] = '\0';  // Remove newline character

    printf("Enter name2: ");
    fgets(name2, 100, stdin);
    name2[strcspn(name2, "\n")] = '\0';  // Remove newline character

    toLowercase(name1);
    toLowercase(name2);
    removeSpaces(name1);
    removeSpaces(name2);

    int leftoverCount = countLeftover(name1, name2);

    printf("Leftover letters in total: %d\n", leftoverCount);
    printf("Result: %s\n", getFlamesResult(leftoverCount));

    return 0;
}
