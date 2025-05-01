#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int staticStack[MAX];
int topStatic = -1;

void pushStatic(int value) {
    if (topStatic == MAX - 1) {
        printf("Static Stack Overflow!\n");
        return;
    }
    staticStack[++topStatic] = value;
    printf("Pushed %d to static stack.\n", value);
}

void popStatic() {
    if (topStatic == -1) {
        printf("Static Stack Underflow!\n");
        return;
    }
    printf("Popped %d from static stack.\n", staticStack[topStatic--]);
}

void displayStatic() {
    if (topStatic == -1) {
        printf("Static Stack is empty.\n");
        return;
    }
    printf("Static Stack: ");
    for (int i = topStatic; i >= 0; i--)
        printf("%d ", staticStack[i]);
    printf("\n");
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* topDynamic = NULL;

void pushDynamic(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = topDynamic;
    topDynamic = newNode;
    printf("Pushed %d to dynamic stack.\n", value);
}

void popDynamic() {
    if (topDynamic == NULL) {
        printf("Dynamic Stack Underflow!\n");
        return;
    }
    struct Node* temp = topDynamic;
    printf("Popped %d from dynamic stack.\n", temp->data);
    topDynamic = topDynamic->next;
    free(temp);
}

void displayDynamic() {
    if (topDynamic == NULL) {
        printf("Dynamic Stack is empty.\n");
        return;
    }
    printf("Dynamic Stack: ");
    struct Node* temp = topDynamic;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, type, value;

    printf("Saksham 08021102024\n");

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        printf("Select Stack Type: 1. Static 2. Dynamic: ");
        scanf("%d", &type);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (type == 1)
                    pushStatic(value);
                else if (type == 2)
                    pushDynamic(value);
                else
                    printf("Invalid stack type!\n");
                break;

            case 2:
                if (type == 1)
                    popStatic();
                else if (type == 2)
                    popDynamic();
                else
                    printf("Invalid stack type!\n");
                break;

            case 3:
                if (type == 1)
                    displayStatic();
                else if (type == 2)
                    displayDynamic();
                else
                    printf("Invalid stack type!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
