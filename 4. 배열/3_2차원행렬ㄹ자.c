#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int* num;
    int N;

    scanf("%d", &N);

    num = (int*)malloc(sizeof(int) * (N * N));
    int right = 1, left = 0, start = 0, end = N - 1;

    for (int i = 0; i < (N * N); i++)
        num[i] = i + 1;

    for (int k = 0; k < N; k++) {
        if (right == 1 && left == 0) {
            for (int i = start; i <= end; i++) {
                printf(" %d", num[i]);
            }

            printf("\n");
            start = end + N;
            end++;
            right = 0;
            left = 1;
        }
        else if (left == 1 && right == 0) {
            for (int i = start;i >= end; i--) {
                printf(" %d", num[i]);
            }
            printf("\n");
            end = start + N;
            start++;
            right = 1;
            left = 0;
        }
    }

    return 0;
}