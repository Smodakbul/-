#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

void addtree(node* tree, int elem1, int elem2, int elem3) {
	if (tree == NULL) {
		return -1;
	}

	node* lefttree = (node*)malloc(sizeof(node));
	node* righttree = (node*)malloc(sizeof(node));

	lefttree->data = elem2;
	righttree->data = elem3;
	lefttree->left = NULL;
	lefttree->right = NULL;
	righttree->left = NULL;
	righttree->right = NULL;

	if (tree->data == elem1) {
		if (elem2 == 0) {
			tree->left = NULL;
			free(lefttree);
		}
		else {
			tree->left = lefttree;
		}

		if (elem3 == 0) {
			tree->right = NULL;
			free(righttree);
		}

		else {
			tree->right = righttree;
		}
	}
	else {
		free(lefttree);
		free(righttree);
	}
	addtree(tree->left, elem1, elem2, elem3);
	addtree(tree->right, elem1, elem2, elem3);
}

void travel(node* tree) {
	if (tree == NULL) {
		return -1;
	}
	printf(" %d", tree->data);
	travel(tree->left);
	travel(tree->right);
}

void search(node* p, char tree[100]) {
	printf(" %d", p->data);
	for (int i = 0; i < strlen(tree); i++) {
		if (tree[i] == 'R') {
			p = p->right;
		}
		else if (tree[i] == 'L') {
			p = p->left;
		}
		else {
			return -1;
		}
		printf(" %d", p->data);
	}
	printf("\n");
}

void freetree(node* tree) {
	if (tree == NULL) {
		return -1;
	}
	freetree(tree->left);
	freetree(tree->right);
	free(tree);
}

void main() {
	node* root, * tree;
	tree = (node*)malloc(sizeof(node));

	char search_arr[100];
	int nodenum, elem1, elem2, elem3, search_num;

	root = tree;
	scanf("%d", &nodenum);
	for (int i = 0; i < nodenum; i++) {
		scanf("%d %d %d", &elem1, &elem2, &elem3);
		if (i == 0) {
			node* lefttree = (node*)malloc(sizeof(node));
			node* righttree = (node*)malloc(sizeof(node));

			tree->data = elem1;
			lefttree->data = elem2;
			righttree->data = elem3;

			lefttree->left = NULL;
			lefttree->right = NULL;
			righttree->left = NULL;
			righttree->right = NULL;

			if (elem2 != 0) {
				root->left = lefttree;
			}
			else {
				free(lefttree);
			}
			if (elem3 != 0) {
				root->right = righttree;
			}
			else {
				free(righttree);
			}
		}
		else {
			addtree(root, elem1, elem2, elem3);
		}
	}
	scanf("%d", &search_num);

	for (int i = 0; i < search_num; i++) {
		getchar();
		scanf("%s", search_arr);
		search(root, search_arr);
	}

	freetree(root);
}