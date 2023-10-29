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


void travel1(node* tree) {

	if (tree == NULL) {

		return;
	}

	printf(" %d", tree->data);
	travel1(tree->left);
	travel1(tree->right);

} //������ȸ


void travel2(node* tree) {

	if (tree == NULL) {

		return;
	}

	travel2(tree->left);
	printf(" %d", tree->data);
	travel2(tree->right);
} //������ȸ


void travel3(node* tree) {

	if (tree == NULL) {

		return;
	}

	travel3(tree->left);
	travel3(tree->right);
	printf(" %d", tree->data);

} //������ȸ


void travel(node* tree, int num, int id) {

	if (tree == NULL) {

		return;
	}

	if (tree->id == id) {

		if (num == 1) {

			travel1(tree);
		}
		else if (num == 2) {

			travel2(tree);
		}
		else if (num == 3) {

			travel3(tree);
		}
	}
	else {

		travel(tree->left, num, id);
		travel(tree->right, num, id);

	}
} //���̵� ã�� ���� �Լ�


void freetree(node* tree) {

	if (tree == NULL) {

		return;

	}

	freetree(tree->left);
	freetree(tree->right);
	free(tree);

} //�Ҵ� ����

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

	scanf("%d %d", &num, &id);

	if ((id > 0) && (id < 9)) {


		travel(p, num, id);
	}
	else {

		printf("-1");

	}

	freetree(tree);

}