#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int staticQueue[MAX];
int frontStatic = -1, rearStatic = -1;

void staticEnqueue(int value) {
    if (rearStatic == MAX - 1) {
        printf("Static Queue Overflow\n");
        return;
    }
    if (frontStatic == -1) frontStatic = 0;
    staticQueue[++rearStatic] = value;
    printf("Inserted %d into Static Queue\n", value);
}

void staticDequeue() {
    if (frontStatic == -1 || frontStatic > rearStatic) {
        printf("Static Queue Underflow\n");
        return;
    }
    printf("Deleted %d from Static Queue\n", staticQueue[frontStatic++]);
    if (frontStatic > rearStatic)
        frontStatic = rearStatic = -1;
}

void displayStaticQueue() {
    if (frontStatic == -1) {
        printf("Static Queue is Empty\n");
        return;
    }
    printf("Static Queue: ");
    for (int i = frontStatic; i <= rearStatic; i++)
        printf("%d ", staticQueue[i]);
    printf("\n");
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* frontDynamic = NULL;
struct Node* rearDynamic = NULL;

void dynamicEnqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rearDynamic == NULL) {
        frontDynamic = rearDynamic = newNode;
    } else {
        rearDynamic->next = newNode;
        rearDynamic = newNode;
    }
    printf("Inserted %d into Dynamic Queue\n", value);
}

void dynamicDequeue() {
    if (frontDynamic == NULL) {
        printf("Dynamic Queue Underflow\n");
        return;
    }

    struct Node* temp = frontDynamic;
    printf("Deleted %d from Dynamic Queue\n", temp->data);
    frontDynamic = frontDynamic->next;
    if (frontDynamic == NULL)
        rearDynamic = NULL;
    free(temp);
}

void displayDynamicQueue() {
    if (frontDynamic == NULL) {
        printf("Dynamic Queue is Empty\n");
        return;
    }
    printf("Dynamic Queue: ");
    struct Node* temp = frontDynamic;
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
        printf("\nChoose Queue Type:\n");
        printf("1. Static Queue\n");
        printf("2. Dynamic Queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &type);

        if (type == 3)
            break;

        while (1) {
            printf("\nQueue Operations:\n");
            printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Switch Queue Type\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if (choice == 4)
                break;

            switch (choice) {
                case 1:
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    if (type == 1)
                        staticEnqueue(value);
                    else
                        dynamicEnqueue(value);
                    break;
                case 2:
                    if (type == 1)
                        staticDequeue();
                    else
                        dynamicDequeue();
                    break;
                case 3:
                    if (type == 1)
                        displayStaticQueue();
                    else
                        displayDynamicQueue();
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
