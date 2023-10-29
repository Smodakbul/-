#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack {
	char* stack;
	int size;
	int top;
}Stack;

void initstack(Stack* s) {
	s->top = -1;
	s->size = 1;
	s->stack = (char*)malloc(s->size * sizeof(char));
}

int isFULL(Stack* s) {
	if (s->top >= s->size - 1)
	{
		return 1;
	}
	return 0;
}

int isEmpty(Stack* s) {
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(Stack* s, char c) {
	if (isFULL(s) == 1)
	{
		printf("Stack FULL\n");
	}
	else if (!isFULL(s))
	{
		s->top++;
		s->stack[s->top] = c;
	}
}

char pop(Stack* s) {
	if (isEmpty(s) == 1)
	{
		printf("Stack Empty\n");
	}
	else if (!isEmpty(s))
	{
		char temp = s->stack[s->top];
		s->top--;
		return temp;
	}
}

void peek(Stack* s) {
	if (isEmpty(s) == 1)
	{
		printf("Stack Empty\n");
	}
	else if (!isEmpty(s))
	{
		printf("%c\n", s->stack[s->top]);
	}
}

void print(Stack* s) {
	for (int i = (s->top); i > -1; i--)
	{
		printf("%c", s->stack[i]);
	}
	printf("\n");
}

void duplicate(Stack* s) {
	if (s->top >= s->size)
	{
		printf("Stack FULL\n");
		return;
	}
	push(s, pop(s));
	push(s, s->stack[s->top]);
}

void upRotate(Stack* s, int n) {
	char* tmp = (char*)malloc(n * sizeof(char));
	if (n > (s->top + 1))
	{
		free(tmp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		tmp[i] = pop(s);
	}
	push(s, tmp[0]);
	for (int i = n - 1; i > 0; i--)
	{
		push(s, tmp[i]);
	}
	free(tmp);
}

void downRotate(Stack* s, int n) {
	char* tmp = (char*)malloc(n * sizeof(char));
	if (n > (s->top + 1))
	{
		free(tmp);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		tmp[i] = pop(s);
	}
	for (int i = n - 2; i > -1; i--)
	{
		push(s, tmp[i]);
	}
	push(s, tmp[n - 1]);
	free(tmp);
}

void main() {
	Stack s;
	initstack(&s);
	int n, m, num;
	char order[100], c;

	scanf("%d", &n);
	s.size = n;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%s", order);
		if (strcmp(order, "POP") == 0)
		{
			pop(&s);
		}
		else if ((strcmp(order, "PUSH") == 0))
		{
			scanf(" %c", &c);
			getchar();
			push(&s, c);
		}
		else if (strcmp(order, "PRINT") == 0)
		{
			print(&s);
		}
		else if (strcmp(order, "PEEK") == 0)
		{
			peek(&s);
		}

		else if (strcmp(order, "UpR") == 0)
		{
			scanf(" %d", &num);
			getchar();
			upRotate(&s, num);
		}
		else if (strcmp(order, "DownR") == 0)
		{
			scanf(" %d", &num);
			getchar();
			downRotate(&s, num);
		}

		else if (strcmp(order, "DUP") == 0)
		{
			duplicate(&s);
		}

	}
	return 0;
}