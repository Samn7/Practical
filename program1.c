#include <stdio.h>

#define MAX_SIZE 100

void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insert(int arr[], int *size, int element, int position) {
    if (*size >= MAX_SIZE || position < 0 || position > *size) {
        printf("Insertion failed: Invalid position or array full.\n");
        return 0;
    }
    for (int i = *size; i > position; i--)
        arr[i] = arr[i - 1];

    arr[position] = element;
    (*size)++;
    return 1;
}

int delete(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Deletion failed: Invalid position.\n");
        return 0;
    }
    for (int i = position; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
    return 1;
}

void reverse(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array reversed.\n");
}

int merge(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i;
    for (i = 0; i < size1; i++)
        result[i] = arr1[i];
    for (int j = 0; j < size2; j++, i++)
        result[i] = arr2[j];
    return size1 + size2;
}

int main() {
    printf("Bhoomi 06621102024\n");

    int arr1[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size1 = 5;

    printf("Initial array:\n");
    traverse(arr1, size1);

    insert(arr1, &size1, 10, 2);
    printf("\nAfter insertion at position 2:\n");
    traverse(arr1, size1);

    delete(arr1, &size1, 3);
    printf("\nAfter deletion at position 3:\n");
    traverse(arr1, size1);

    reverse(arr1, size1);
    printf("\nAfter reversing:\n");
    traverse(arr1, size1);

    int arr2[] = {100, 200, 300};
    int size2 = 3;

    int merged[MAX_SIZE];
    int mergedSize = merge(arr1, size1, arr2, size2, merged);
    printf("\nAfter merging with second array:\n");
    traverse(merged, mergedSize);

    return 0;
}
