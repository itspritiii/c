#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        printf("list is empty");
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        printf("list is empty");
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int value, int p) {
    if (head == NULL || p <= 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node *newNode = createNode(value);
    struct Node *temp = head;
    int i = 1;
    while (temp != NULL && i < p - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        insertAtEnd(value);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    head = temp->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Deleted from beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Deleted from end.\n");
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

void deleteAtPosition(int p) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (p <= 1) {
        deleteAtBeginning();
        return;
    }
    struct Node *temp = head;
    int i = 1;
    while (temp != NULL && i < p) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position does not exist!\n");
        return;
    }
    if (temp->next == NULL) {
        deleteAtEnd();
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Deleted from position %d.\n", p);
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    int deleted = 0;
    struct Node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            struct Node *nextNode = current->next;

            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }

            free(current);
            current = nextNode;
            deleted++;
        } else {
            current = current->next;
        }
    }
    if (deleted == 0) {
        printf("Value %d not found in the list.\n", value);
    } else {
        printf("Deleted %d occurrence(s) of value %d.\n", deleted, value);
    }
}
void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("\nCurrent Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    int choice, value, position;

    do{
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("7. Delete by Value\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(value, position);
                break;

            case 4:
                deleteAtBeginning();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;

            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);
    return 0;
}
