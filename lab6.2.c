#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, i, value, x, p;

    scanf("%d", &n);

    // Create linked list
    for (i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input value and position
    scanf("%d %d", &x, &p);

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;

    // Insert at position 1
    if (p == 1) {
        newNode->next = head;
        head = newNode;
    } 
    else {
        temp = head;

        for (i = 1; i < p - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Display linked list
    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");

    return 0;
}