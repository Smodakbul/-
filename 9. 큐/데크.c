#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int size;

typedef struct node {

	int e;
	struct node* prev;
	struct node* next;
}node;

struct node* q;
struct node* rear;
struct node* front;

void initqueue(int value) {

	q = (node*)malloc(sizeof(node));

	q->e = value;
	q->prev = NULL;
	q->next = NULL;

	rear = q;
	front = q;
}


void add_front(int value) {

	node* createnode = (node*)malloc(sizeof(node));

	createnode->e = value;
	createnode->prev = NULL;
	createnode->next = front;
	createnode->next->prev = createnode;
	front = createnode;
}

void add_rear(int value) {

	node* createnode = (node*)malloc(sizeof(node));

	createnode->e = value;
	createnode->prev = rear;
	createnode->next = NULL;
	createnode->prev->next = createnode;
	rear = createnode;

}


void delete_front() {

	node* p;
	if (size == 0) {

		printf("underflow");
		exit(1);
	}
	else {

		p = front;
		if (size == 1) {

			free(p);
		}
		else {

			front = front->next;
			front->prev = NULL;
			free(p);
		}
		return p->e;
	}
}
void delete_rear() {

	node* p;
	if (size == 0) {

		printf("underflow");
		exit(1);
	}
	else {

		p = rear;
		if (size == 1) {

			free(p);
		}
		else {

			rear = rear->prev;
			rear->next = NULL;
			free(p);
		}
		return p->e;
	}
}

void print() {

	node* p = front;
	while (p != NULL) {

		printf(" %d", p->e);
		p = p->next;
	}
	printf("\n");
}

void free_q() {

	node* p;
	p = front;

	while (p != NULL) {

		front = front->next;
		free(p);
		p = front;
	}
}

void main() {

	int value, m;
	char order[3];
	size = 0;

	scanf("%d", &m);

	getchar();

	for (int i = 0; i < m; i++) {

		scanf("%s", &order);

		if (strcmp(order, "AF") == 0) {

			scanf(" %d", &value);

			if (size == 0) {

				q = (node*)malloc(sizeof(node));

				q->e = value;
				q->prev = NULL;
				q->next = NULL;

				rear = q;
				front = q;
				size++;
			}
			else {

				add_front(value);
				size++;
			}
		}
		else if (strcmp(order, "AR") == 0) {

			scanf(" %d", &value);

			if (size == 0) {

				q = (node*)malloc(sizeof(node));

				q->e = value;
				q->prev = NULL;
				q->next = NULL;

				rear = q;
				front = q;
				size++;
			}
			else {

				add_rear(value);
				size++;
			}
		}

		else if (strcmp(order, "DF") == 0) {

			delete_front();
			size--;
		}

		else if (strcmp(order, "DR") == 0) {

			delete_rear();
			size--;
		}

		else if (strcmp(order, "P") == 0) {

			if (size == 0) {

				continue;
			}
			print();
		}
	}
	free_q();

}