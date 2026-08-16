#include <stdio.h>

#define MAX 100

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n)
{
    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[MAX][MAX], A12[MAX][MAX];
    int A21[MAX][MAX], A22[MAX][MAX];

    int B11[MAX][MAX], B12[MAX][MAX];
    int B21[MAX][MAX], B22[MAX][MAX];

    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX];
    int M4[MAX][MAX], M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];

    int T1[MAX][MAX], T2[MAX][MAX];

    int C11[MAX][MAX], C12[MAX][MAX];
    int C21[MAX][MAX], C22[MAX][MAX];

    // Divide matrices into 4 parts
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    // 7 multiplications

    sub(B12, B22, T1, k);
    strassen(A11, T1, M1, k);

    add(A11, A12, T1, k);
    strassen(T1, B22, M2, k);

    add(A21, A22, T1, k);
    strassen(T1, B11, M3, k);

    sub(B21, B11, T1, k);
    strassen(A22, T1, M4, k);

    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M5, k);

    sub(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M6, k);

    sub(A11, A21, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M7, k);

    // Calculate C11, C12, C21, C22

    add(M5, M4, T1, k);
    sub(T1, M2, T2, k);
    add(T2, M6, C11, k);

    add(M1, M2, C12, k);

    add(M3, M4, C21, k);

    add(M5, M1, T1, k);
    sub(T1, M3, T2, k);
    sub(T2, M7, C22, k);

    // Combine the four parts

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }
    }
}

int main()
{
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter size of matrix: ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("\nResult:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}