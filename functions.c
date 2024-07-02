#include <stdio.h>
// Queue node structure
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Initialize the queue

// Function to convert a string to lowercase
void toLowercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to remove spaces from a string
void removeSpaces(char str[]) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Enqueue an element
void enqueue(Queue* q, char element) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = element;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Dequeue an element
char dequeue(Queue* q) {
    if (q->front == NULL) {
        return '\0';
    }
    Node* temp = q->front;
    char element = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return element;
}

// Function to count the number of common characters and leftover characters
int countLeftover(char name1[], char name2[]) {
    Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    for (int i = 0; name1[i]; i++) {
        enqueue(&q1, name1[i]);
    }

    for (int i = 0; name2[i]; i++) {
        enqueue(&q2, name2[i]);
    }

    // Array to mark the used characters in name2
    int used[100] = {0};
    int count = 0;

    // Process the first queue
    Node* current1 = q1.front;
    while (current1 != NULL) {
        char ch1 = current1->data;
        int found = 0;

        // Look for a matching character in name2
        Node* current2 = q2.front;
        int pos = 0;
        while (current2 != NULL) {
            if (ch1 == current2->data && !used[pos]) {
                used[pos] = 1; // Mark the character as used
                found = 1;
                break;
            }
            current2 = current2->next;
            pos++;
        }

        if (!found) {
            count++;
        }

        current1 = current1->next;
    }

    // Count the remaining characters in name2 that were not used
    Node* current = q2.front;
    int pos = 0;
    while (current != NULL) {
        if (!used[pos]) {
            count++;
        }
        current = current->next;
        pos++;
    }

    return count;
}

// Function to get the FLAMES result using a linear search
char* getFlamesResult(int count) {
    char* flames[] = {"Friends", "Lovers", "Affectionate", "Marriage", "Enemies", "Soulmates"};
    int index = (count - 1) % 6;
    return flames[index];
}
