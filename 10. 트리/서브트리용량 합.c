#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int id;
	int data;
	struct node* left;
	struct node* right;
} node;

void lefttree(struct node* p, int element, int n) {

	node* createnode = (node*)malloc(sizeof(node));
	createnode->id = n;
	createnode->data = element;
	createnode->left = NULL;
	createnode->right = NULL;
	p->left = createnode;
}

void righttree(struct node* p, int element, int n) {

	node* createnode = (node*)malloc(sizeof(node));
	createnode->id = n;
	createnode->data = element;
	createnode->left = NULL;
	createnode->right = NULL;
	p->right = createnode;
}


int travel1(node* tree) {

	if (tree == NULL) {

		return 0;
	}
	else
		return tree->data + travel1(tree->left) + travel1(tree->right);

} //전위순회

void travel(node* tree, int id) {

	if (tree == NULL) {

		return;
	}

	if (tree->id == id) {

		printf("%d", travel1(tree));
	}
	else {
		travel(tree->left, id);
		travel(tree->right, id);
	}
} //아이디 찾기 위한 함수


void freetree(node* tree) {

	if (tree == NULL) {

		return;

	}

	freetree(tree->left);
	freetree(tree->right);
	free(tree);

} //할당 해제

void main() {

	int num, id;

	node* tree, * p;

	tree = (node*)malloc(sizeof(node));
	p = tree;

	tree->data = 20;
	tree->id = 1;
	tree->left = NULL;
	tree->right = NULL;

	lefttree(tree, 30, 2);
	righttree(tree, 50, 3);

	lefttree(tree->left, 70, 4);
	righttree(tree->left, 90, 5);

	righttree(tree->right, 120, 6);

	lefttree(tree->right->right, 130, 7);
	righttree(tree->right->right, 80, 8);

	scanf("%d", &id);

	if ((id > 0) && (id < 9)) {


		travel(p, id);
	}
	else {

		printf("-1");

	}

	freetree(tree);

	return 0;
}