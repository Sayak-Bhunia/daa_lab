#include <stdio.h>

int areCompatible(int r1, int c1, int r2, int c2) {
    return (c1 == r2);
}

void multiplyMatrices(int rows1, int cols1, int a[rows1][cols1], int rows2, int cols2, int b[rows2][cols2], int res[rows1][cols2]) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
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
    int r1, c1, r2, c2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (!areCompatible(r1, c1, r2, c2)) {
        printf("Matrices are not compatible for multiplication.\n");
        return 1;
    }

    int a[r1][c1];
    printf("Enter elements of the first matrix:\n");
    inputMatrix(r1, c1, a);

    int b[r2][c2];
    printf("Enter elements of the second matrix:\n");
    inputMatrix(r2, c2, b);

    int res[r1][c2];
    multiplyMatrices(r1, c1, a, r2, c2, b, res);
    printf("Resultant matrix after multiplication:\n");
    printMatrix(r1, c2, res);

    return 0;
}
