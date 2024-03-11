#include <stdio.h>

int areCompatible(int r1, int c1, int r2, int c2) {
    return (r1 == r2 && c1 == c2);
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumMatrices(int rows, int cols, int a[rows][cols], int b[rows][cols], int res[rows][cols]) {
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            res[i][j] = a[i][j] + b[i][j];
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
    int r1, c1, r2, c2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (!areCompatible(r1, c1, r2, c2)) {
        printf("Matrices are not compatible for addition.\n");
        return 1;
    }

    int a[r1][c1];
    printf("Enter elements of the first matrix:\n");
    inputMatrix(r1, c1, a);

    int b[r2][c2];
    printf("Enter elements of the second matrix:\n");
    inputMatrix(r2, c2, b);

    int res[r1][c1];
    sumMatrices(r1, c1, a, b, res);
    printf("resant matrix after addition:\n");
    printMatrix(r1, c1, res);

    return 0;
}

