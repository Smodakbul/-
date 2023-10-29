#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	int N, M;
	int** arr;
	scanf("%d %d", &N, &M);

	arr = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * M);
	}

	int i = 0, j = 0;
	int num = 2;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			arr[i][j] = 0;
	}
	i = 0, j = 0;
	arr[i][j] = 1;

	while (num <= N * M) {

		while (j + 1 < M && arr[i][j + 1] == 0) {

			j++;
			arr[i][j] = num;
			num++;

		}
		while (i + 1 < N && arr[i + 1][j] == 0) {

			i++;
			arr[i][j] = num;
			num++;

		}
		while (j - 1 >= 0 && arr[i][j - 1] == 0) {
			j--;
			arr[i][j] = num;
			num++;
		}
		while (i - 1 >= 0 && arr[i - 1][j] == 0) {
			i--;
			arr[i][j] = num;
			num++;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}