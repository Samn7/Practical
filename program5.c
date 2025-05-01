#include <stdio.h>



int binarySearch(int arr[], int size, int target) { int low = 0, high = size - 1, mid;
while (low <= high) { mid = (low + high) / 2; if (arr[mid] == target)
return mid;
else if (arr[mid] < target) low = mid + 1;
else
high = mid - 1;
}
return -1;
}


int main() {
printf("Saksham 08021102024\n");
 
int arr[100], n, key, position;



printf("Enter number of elements: "); scanf("%d", &n);
printf("Enter %d elements in sorted order:\n", n); for (int i = 0; i < n; i++)
scanf("%d", &arr[i]);
printf("Enter element to search: "); scanf("%d", &key);
position = binarySearch(arr, n, key); if (position != -1)
printf("Element %d found at index %d (position %d)\n", key, position, position + 1);
else
printf("Element %d not found in the array.\n", key);


return 0;
}
