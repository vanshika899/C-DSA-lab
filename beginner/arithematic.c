#include <stdio.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2, i, j, k, choice;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Sum & Subtraction\n2. Product of 2 Matrices\n3. Transpose of Matrix\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 4) return 0;

        printf("Enter rows and columns of matrix A: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter Matrix A:\n");
        for(i=0; i<r1; i++)
            for(j=0; j<c1; j++)
                scanf("%d", &a[i][j]);

        if(choice == 1 || choice == 2) {
            printf("Enter rows and columns of matrix B: ");
            scanf("%d %d", &r2, &c2);

            printf("Enter Matrix B:\n");
            for(i=0; i<r2; i++)
                for(j=0; j<c2; j++)
                    scanf("%d", &b[i][j]);
        }

        switch(choice) {

            case 1:
                if(r1 == r2 && c1 == c2) {
                    printf("\nSum:\n");
                    for(i=0; i<r1; i++) {
                        for(j=0; j<c1; j++) {
                            c[i][j] = a[i][j] + b[i][j];
                            printf("%d ", c[i][j]);
                        }
                        printf("\n");
                    }

                    printf("\nSubtraction:\n");
                    for(i=0; i<r1; i++) {
                        for(j=0; j<c1; j++) {
                            c[i][j] = a[i][j] - b[i][j];
                            printf("%d ", c[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Matrix dimensions do not match!\n");
                }
                break;

            case 2:
                if(c1 == r2) {
                    printf("\nProduct:\n");
                    for(i=0; i<r1; i++) {
                        for(j=0; j<c2; j++) {
                            c[i][j] = 0;
                            for(k=0; k<c1; k++)
                                c[i][j] += a[i][k] * b[k][j];
                            printf("%d ", c[i][j]);
                        }
                        printf("\n");
                    }
                } else {
                    printf("Multiplication not possible!\n");
                }
                break;

            case 3:
                printf("\nTranspose of A:\n");
                for(i=0; i<c1; i++) {
                    for(j=0; j<r1; j++)
                        printf("%d ", a[j][i]);
                    printf("\n");
                }
                break;
        }
    }
}
