#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int staticCQ[MAX];
int frontS = -1, rearS = -1;

void staticCQEnqueue(int value) {
    if ((frontS == 0 && rearS == MAX - 1) || ((rearS + 1) % MAX == frontS)) {
        printf("Static Circular Queue Overflow\n");
        return;
    }
    if (frontS == -1)
        frontS = rearS = 0;
    else
        rearS = (rearS + 1) % MAX;

    staticCQ[rearS] = value;
    printf("Inserted %d into Static Circular Queue\n", value);
}

void staticCQDequeue() {
    if (frontS == -1) {
        printf("Static Circular Queue Underflow\n");
        return;
    }
    printf("Deleted %d from Static Circular Queue\n", staticCQ[frontS]);
    if (frontS == rearS)
        frontS = rearS = -1;
    else
        frontS = (frontS + 1) % MAX;
}

void displayStaticCQ() {
    if (frontS == -1) {
        printf("Static Circular Queue is Empty\n");
        return;
    }
    printf("Static Circular Queue: ");
    int i = frontS;
    while (1) {
        printf("%d ", staticCQ[i]);
        if (i == rearS)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

struct Node {
    int data;
    struct Node* next;
};

struct Node *frontD = NULL, *rearD = NULL;

void dynamicCQEnqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (frontD == NULL) {
        frontD = rearD = newNode;
        rearD->next = frontD;
    } else {
        rearD->next = newNode;
        rearD = newNode;
        rearD->next = frontD;
    }
    printf("Inserted %d into Dynamic Circular Queue\n", value);
}

void dynamicCQDequeue() {
    if (frontD == NULL) {
        printf("Dynamic Circular Queue Underflow\n");
        return;
    }

    struct Node* temp = frontD;

    if (frontD == rearD) {
        printf("Deleted %d from Dynamic Circular Queue\n", temp->data);
        free(temp);
        frontD = rearD = NULL;
    } else {
        printf("Deleted %d from Dynamic Circular Queue\n", temp->data);
        frontD = frontD->next;
        rearD->next = frontD;
        free(temp);
    }
}

void displayDynamicCQ() {
    if (frontD == NULL) {
        printf("Dynamic Circular Queue is Empty\n");
        return;
    }

    printf("Dynamic Circular Queue: ");
    struct Node* temp = frontD;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != frontD);
    printf("\n");
}

int main() {
    int choice, type, value;

    printf("Saksham 08021102024\n");

    while (1) {
        printf("\nChoose Queue Type:\n");
        printf("1. Static Circular Queue\n");
        printf("2. Dynamic Circular Queue\n");
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
                        staticCQEnqueue(value);
                    else
                        dynamicCQEnqueue(value);
                    break;
                case 2:
                    if (type == 1)
                        staticCQDequeue();
                    else
                        dynamicCQDequeue();
                    break;
                case 3:
                    if (type == 1)
                        displayStaticCQ();
                    else
                        displayDynamicCQ();
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}
