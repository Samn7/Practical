#include <stdio.h>

#define MAX 100

void inputMatrix(int mat[MAX][MAX], int row, int col, const char* name) {
    printf("Enter elements of %s (%dx%d):\n", name, row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] + B[i][j];
}

void subtractMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = A[i][j] - B[i][j];
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
                result[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main() {
    printf("Saksham 08021102024\n");

    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d%d", &row1, &col1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d%d", &row2, &col2);

    inputMatrix(A, row1, col1, "Matrix A");
    inputMatrix(B, row2, col2, "Matrix B");

    if (row1 == row2 && col1 == col2) {
        addMatrix(A, B, result, row1, col1);
        printf("\nAddition of matrices:\n");
        displayMatrix(result, row1, col1);

        subtractMatrix(A, B, result, row1, col1);
        printf("\nSubtraction of matrices:\n");
        displayMatrix(result, row1, col1);
    } else {
        printf("\nAddition and Subtraction not possible (dimension mismatch).\n");
    }

    if (col1 == row2) {
        multiplyMatrix(A, B, result, row1, col1, col2);
        printf("\nMultiplication of matrices:\n");
        displayMatrix(result, row1, col2);
    } else {
        printf("\nMultiplication not possible (columns of A must equal rows of B).\n");
    }

    return 0;
}
