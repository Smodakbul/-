#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack
{
	char* stack;
	int top;
}Stack;

void initstack(Stack* s)
{
	s->top = -1;
	s->stack = (char*)malloc(100 * sizeof(char));
}

void push(Stack* s, char data)
{
	s->top++;
	s->stack[s->top] = data;
}

char pop(Stack* s)
{
	return s->stack[s->top--];
}

int func(char arr)
{
	if (arr == '+')
	{
		return 1;
	}
	else if (arr == '-')
	{
		return 2;
	}
	else if (arr == '*')
	{
		return 3;
	}
	else if (arr == '/')
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

void main()
{
	Stack s;
	initstack(&s);

	int i, j, n, num, a, b;
	char arr[100];

	scanf("%d", &n);
	getchar();

	for (i = 0; i < n; i++)
	{
		s.top = -1;
		num = 0;
		scanf("%s", arr);
		getchar();

		while (num != strlen(arr))
		{
			if (func(arr[num]) == 0)
			{
				push(&s, arr[num] - '0');
			}
			else
			{
				if (func(arr[num]) == 1)
				{
					a = pop(&s);
					b = pop(&s);
					push(&s, a + b);
				}
				else if (func(arr[num]) == 2)
				{
					a = pop(&s);
					b = pop(&s);
					push(&s, b - a);
				}
				else if (func(arr[num]) == 3)
				{
					a = pop(&s);
					b = pop(&s);
					push(&s, a * b);
				}
				else if (func(arr[num]) == 4)
				{
					a = pop(&s);
					b = pop(&s);
					push(&s, b / a);
				}
			}
			num++;
		}
		printf("%d\n", pop(&s));
	}

	return 0;
}
