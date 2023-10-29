#pragma warning(disable:4996)
#include<stdio.h>
#include  <stdlib.h>

void swap(int* X, int front, int back) {

    int n = (back - front) / 2 + 1, tmp;

    for (int i = 0;i < n;i++) {

        tmp = X[front + i];
        X[front + i] = X[back - i];
        X[back - i] = tmp;
    }
}

int main() {
    int N;
    int* X;
    scanf("%d", &N);

    X = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }
    int rvs_c;

    scanf("%d", &rvs_c);

    int* rvs_arr = (int*)malloc(sizeof(int) * (rvs_c * 2));

    for (int i = 0; i < (rvs_c * 2); i += 2) {
        scanf("%d %d", &rvs_arr[i], &rvs_arr[i + 1]);
    }

    for (int i = 0; i < rvs_c * 2; i += 2) {
        swap(X, rvs_arr[i], rvs_arr[i + 1]);
    }

    for (int i = 0; i < N; i++) {
        printf(" %d", X[i]);
    }

    return 0;

}