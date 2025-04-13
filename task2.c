#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert after a specific value
void insertAfter(struct Node* head, int target, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL) {
        printf("Target not found!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main menu
int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Node\n");
        printf("4. Delete a Node\n");
        printf("5. Traverse the List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
        case 3:
            printf("Enter target value: ");
            scanf("%d", &target);
            printf("Enter new value: ");
            scanf("%d", &value);
            insertAfter(head, target, value);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(&head, value);
            break;
        case 5:
            traverse(head);
            break;
        case 6:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
