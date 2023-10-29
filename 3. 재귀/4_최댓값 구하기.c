#pragma warning(disable:4996) 
#include <stdio.h>


int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int maxarr(int arr[20], int N) {

	if (N == 1)
		return arr[0];

	else
		return max(arr[N - 1], maxarr(arr, N - 1));

}

int main() {

	int N;
	int	arr[20];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("%d", maxarr(arr, N));

	return 0;

}