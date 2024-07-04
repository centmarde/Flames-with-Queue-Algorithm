#include <stdio.h>
void printHeartUI() {
    printf("\t\t\t\t\t\t  ****     ****\n");
    printf("\t\t\t\t\t\t ******   ******\n");
    printf("\t\t\t\t\t\t******** ********\n");
    printf("\t\t\t\t\t\t ****************\n");
    printf("\t\t\t\t\t\t  **************\n");
    printf("\t\t\t\t\t\t    **********\n");
    printf("\t\t\t\t\t\t      ******\n");
    printf("\t\t\t\t\t\t        **\n");
}

void printThumbsUpUI() {
    printf("\t\t\t\t\t\t     |Y___Y| \n");
    printf("\t\t\t\t\t\t    =) ^Y^ (=     \n");
    printf("\t\t\t\t\t\t     )  ^  (\n");
    printf("\t\t\t\t\t\t      )=*=(       \n");
    printf("\t\t\t\t\t\t     /     \\n");
  
}

void printAngerUI() {
    printf("\t\t\t\t\t\t      >:(\n");
}

void printBirdUI() {
    printf("\t\t\t\t\t\t        \\\n");
    printf("\t\t\t\t\t\t       (o>\n");
    printf("\t\t\t\t\t\t       //\\\n");
    printf("\t\t\t\t\t\t      v_/_) \n");
}

void printResultUI(char *result) {
    if (strcmp(result, "Lovers") == 0 || strcmp(result, "Marriage") == 0 || strcmp(result, "Engagement") == 0) {
        printHeartUI();
    } else if (strcmp(result, "Friends") == 0) {
        printThumbsUpUI();
    } else if (strcmp(result, "Anger") == 0) {
        printAngerUI();
    } else if (strcmp(result, "Soulmates") == 0) {
        printBirdUI();
    }
}

void printMenu() {
    printf("\nMENU:\n");
    printf("1. Enter Names\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}