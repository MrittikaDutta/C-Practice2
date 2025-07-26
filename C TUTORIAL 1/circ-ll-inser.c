#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node* lastNode = *head;
        while (lastNode->next != *head) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    if (*head == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* lastNode = *head;
    while (lastNode->next != *head) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    newNode->next = *head;
}

void insertInMiddle(struct Node** head, int data, int position) {
    if (*head == NULL || position == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* currentNode = *head;
    int count = 1;
    while (count < position && currentNode->next != *head) {
        currentNode = currentNode->next;
        count++;
    }
    struct Node* newNode = createNode(data);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* currentNode = head;
    do {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    } while (currentNode != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, i, choice, data, position;

    printf("Enter no. of Nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data for Node%d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("1. Insert at beginning\n2. Insert at end\n3. Insert in middle\n\nYour option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the number: ");
        scanf("%d", &data);
        insertAtBeginning(&head, data);
    } else if (choice == 2) {
        printf("Enter the number: ");
        scanf("%d", &data);
        insertAtEnd(&head, data);
    } else if (choice == 3) {
        printf("Enter position to insert: ");
        scanf("%d", &position);
        printf("Enter the number: ");
        scanf("%d", &data);
        insertInMiddle(&head, data, position);
    }

    printf("After inserting, the list is: ");
    displayList(head);

    return 0;
}