#include <stdio.h>

#define MAX 100

struct Sparse {
    int row;
    int col;
    int value;
};

int main() {
    printf("Saksham 08021102024");

    int matrix[10][10], rows, cols;
    struct Sparse sparse[MAX];
    int k = 1;

    printf("\nEnter number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    printf("Enter elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = k - 1;

    printf("\nSparse Matrix (Triplet Format):\n");
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }

    return 0;
}
