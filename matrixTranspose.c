#include <stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int rows, int cols, int matrix[rows][cols], int transpose[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int r, c;

    printf("Enter the number of r and columns for the matrix: ");
    scanf("%d %d", &r, &c);

    int matrix[r][c];
    printf("Enter elements of the matrix:\n");
    inputMatrix(r, c, matrix);

    printf("Original matrix:\n");
    printMatrix(r, c, matrix);

    int transpose[c][r];
    transposeMatrix(r, c, matrix, transpose);
    printf("\n");

    printf("Transpose matrix:\n");
    printMatrix(c, r, transpose);

    return 0;
}
