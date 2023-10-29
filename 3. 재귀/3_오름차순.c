#pragma warning(disable:4996) 
#include <stdio.h>


int printDigits(int N) {

	if (N < 10) {
		printf("%d\n", N);
		return N;

	}
	else {
		printf("%d\n", N % 10);
		printDigits(N / 10);


	}

}

int main() {

	int N;

	scanf("%d", &N);

	printDigits(N);

	return 0;

}