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
	int i2 = 0, j2 = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			arr[i][j] = 0;
	}
	i = 0, j = 0;
	arr[i][j] = 1;
	int num = 1;

	while (j2 + 1 < M && arr[i2][j2 + 1] == 0) {

		j2++;
		num++;
		i = i2;
		j = j2;
		arr[i][j] = num;
		while (i + 1 < N && j - 1 >= 0 && arr[i + 1][j - 1] == 0) {
			num++;
			arr[i + 1][j - 1] = num;
			i++;
			j--;
		}
	}
	while (i2 + 1 < N && arr[i2 + 1][j2] == 0) {

		i2++;
		num++;
		i = i2;
		j = j2;
		arr[i][j] = num;
		while (i + 1 < N && j - 1 >= 0 && arr[i + 1][j - 1] == 0) {
			num++;
			arr[i + 1][j - 1] = num;
			i++;
			j--;
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