#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    printf("Saksham 08021102024");

    int arr[100], n, key, position;

    printf("\nEnter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    position = linearSearch(arr, n, key);

    if (position != -1)
        printf("Element %d found at index %d (position %d)\n", key, position, position + 1);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
