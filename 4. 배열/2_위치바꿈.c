#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

    int N, len;
    int* X;
    int* Y;
    int* inf;
    scanf("%d", &N);

    X = (int*)malloc(sizeof(int) * N);
    Y = (int*)malloc(sizeof(int) * N);


    for (int i = 0; i < N;i++) {
        scanf("%d", &X[i]);

        Y[i] = X[i];
    }
    scanf("%d", &len);

    inf = (int*)malloc(sizeof(int) * len);

    for (int j = 0; j < len;j++)
        scanf("%d", &inf[j]);

    for (int j = 0; j < len - 1;j++)
        X[inf[j + 1]] = Y[inf[j]];



    for (int i = 0;i < N;i++)
        printf(" %d", X[i]);

    return 0;
}