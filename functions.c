#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
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

// Function to remove a specific character from a queue
void removeCharFromQueue(Queue* q, char ch) {
    Node* current = q->front;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == ch) {
            Node* temp = current;
            if (prev == NULL) {
                q->front = current->next;
            } else {
                prev->next = current->next;
            }
            if (current->next == NULL) {
                q->rear = prev;
            }
            current = current->next;
            free(temp);
            q->size--;
        } else {
            prev = current;
            current = current->next;
        }
    }
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

    // Array to track characters that need to be removed
    char toRemove1[100] = {0};
    char toRemove2[100] = {0};

    Node* current1 = q1.front;
    while (current1 != NULL) {
        char ch1 = current1->data;
        Node* current2 = q2.front;
        while (current2 != NULL) {
            if (ch1 == current2->data) {
                toRemove1[strlen(toRemove1)] = ch1;
                toRemove2[strlen(toRemove2)] = ch1;
                break;
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }

    // Remove common characters from both queues
    for (int i = 0; toRemove1[i]; i++) {
        removeCharFromQueue(&q1, toRemove1[i]);
        removeCharFromQueue(&q2, toRemove1[i]);
    }

    // Count remaining elements in both queues
    int leftoverCount = q1.size + q2.size;

    return leftoverCount;
}

// Function to get the FLAMES result using a linear search
char* getFlamesResult(int count) {
    char* flames[] = {"Friends", "Lovers", "Anger", "Marriage", "Engagement", "Soulmates"};
    int index = (count - 1) % 6;
    return flames[index];
}
