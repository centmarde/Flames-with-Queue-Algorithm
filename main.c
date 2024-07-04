#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "functions.c"
#include "UI.c"
int main() {
    char name1[100], name2[100];
    int choice;

    printHeartUI();
    printf("\n");
    printf("\t\t\t\t\t    Welcome to the FLAMES Game\n");

    while (1) {
        printMenu();
        scanf("%d", &choice);
        getchar();  // Consume the newline character left by scanf

        switch (choice) {
            case 1:
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
                char *result = getFlamesResult(leftoverCount);
               /*  printf("Leftover letters in total: %d\n", leftoverCount); */
                printf("\n\n\t\t\t\t\t\t  ---%s---\n\n", result);
                printResultUI(result);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}