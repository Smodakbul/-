#pragma warning(disable:4996)
#include<stdio.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

void left_func(node* p, int n) {
	node* createnode = (node*)malloc(sizeof(node));
	createnode->data = n;
	createnode->left = NULL;
	createnode->right = NULL;
	p->left = createnode;
}

void right_func(node* p, int n) {
	node* createnode = (node*)malloc(sizeof(node));
	createnode->data = n;
	createnode->left = NULL;
	createnode->right = NULL;
	p->right = createnode;
}

void main() {
	int n, cnt = 0, x = 0;
	node* tree = (node*)malloc(sizeof(node));


	tree->data = 20; //tree
	tree->left = NULL;
	tree->right = NULL;

	left_func(tree, 30); //F2
	right_func(tree, 50); //F3
	left_func(tree->left, 70); //F4
	right_func(tree->left, 90); //F5
	right_func(tree->right, 120); //F6
	left_func(tree->right->right, 130); //F7
	right_func(tree->right->right, 80); //F8


	node* T[8];
	T[0] = tree;
	T[1] = tree->left;
	T[2] = tree->right;
	T[3] = tree->left->left;
	T[4] = tree->left->right;
	T[5] = tree->right->right;
	T[6] = tree->right->right->left;
	T[7] = tree->right->right->right;

	scanf("%d", &n);

	x = n - 1;

	for (int i = 0; i < 8; i++) {
		if (i == x) {
			printf("%d", T[i]->data);

			if (T[i]->left != NULL) {
				printf(" %d", T[i]->left->data);
			}

			if (T[i]->right != NULL) {
				printf(" %d", T[i]->right->data);
			}

			printf("\n");

			cnt++;
			break;
		}
	}
	if (cnt == 0) {
		printf("-1\n");
	}
	for (int i = 0; i < 8; i++) {
		free(T[i]);
	}
}