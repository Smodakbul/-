#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int size;
int* q;
int rear;
int front;

void initqueue() {

	front = 0;
	rear = 0;
	q = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		q[i] = 0;
	}
}
void print() {

	for (int i = 0; i < size; i++)
	{
		printf(" %d", q[i]);
	}
	printf("\n");
}

void insert(int value) {

	if ((rear + 1) % size == front % size) {

		printf("overflow");
		print();
		free(q);
		exit(1);
	}
	rear = (++(rear)) % size;
	q[rear] = value;
}

void delete() {

	int value;
	if (rear % size == front % size) {

		printf("underflow");
		free(q);
		exit(1);
	}
	else {

		front = (++(front)) % size;
		value = q[front - 1];
		q[front] = 0;
		return value;
	}
}

void main() {

	char cmd;
	int n, e
		, m;

	scanf("%d", &size);

	initqueue();

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {

		getchar();

		scanf("%c", &cmd);

		if (cmd == 'I') {

			scanf("%d", &e);
			insert(e);
		}
		else if (cmd == 'D') {

			delete();
		}
		else if (cmd == 'P') {

			print();
		}
	}
	free(q);

}