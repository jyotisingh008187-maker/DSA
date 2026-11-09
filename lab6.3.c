#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *temp, *newNode;
    struct Node *prev = NULL;
    int n, i, value, key, found = 0;

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

    // Input key
    scanf("%d", &key);

    temp = head;

    // Delete first occurrence
    while (temp != NULL) {

        if (temp->data == key) {

            found = 1;

            if (temp == head) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if (found == 0) {
        printf("Not found");
    } else {

        // Display linked list
        temp = head;

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }

    return 0;
}
