#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Stack
{
	char* stack;
	int top;
	int flag;
}Stack;

void initstack(Stack* s)
{
	s->top = -1;
	s->stack = (char*)malloc(100 * sizeof(char));
	s->flag = 0;
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

int func(Stack* s, char* arr, int i)
{
	if (((arr[i] == '+') || (arr[i] == '-')) && (i == 0) && (s->top != i))
	{
		s->flag = 1;
		return 6;
	}
	else if
		(
			(s->top != -1)
			&& ((arr[i] == '+') || (arr[i] == '-'))
			&& ((arr[i - 1] == '|') || (arr[i - 1] == '&') || (arr[i - 1] == '<')
				|| (arr[i - 1] == '>') || (arr[i - 1] == '-') || (arr[i - 1] == '+')
				|| (arr[i - 1] == '*') || (arr[i - 1] == '/') || (arr[i - 1] == '!'))
			)
	{
		return 6;
	}
	else if (arr[i] == '!')
	{
		return 6;
	}
	else if (arr[i] == '|')
	{
		return 1;
	}
	else if (arr[i] == '&')
	{
		return 2;
	}
	else if (arr[i] == '>' || arr[i] == '<')
	{
		return 3;
	}
	else if (arr[i] == '+' || arr[i] == '-')
	{
		return 4;
	}
	else if (arr[i] == '*' || arr[i] == '/')
	{
		return 5;
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
	int n, num;

	char a[100], b[100];

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		num = 0;
		s.top = -1;
		s.flag = 0;

		for (int j = 0; j < 100; j++)
		{
			b[j] = '\0';
			s.stack[j] = '\0';
		}

		scanf("%s", &a);
		getchar();

		for (int j = 0; j < strlen(a); j++)
		{
			if (a[j] == '(')
			{
				push(&s, a[j]);
			}
			else if (a[j] == ')')
			{
				while (s.stack[s.top] != '(')
				{
					b[num++] = pop(&s);
				}
				pop(&s);
			}
			else if (func(&s, a, j) == 6)
			{
				push(&s, a[j]);
			}
			else if (func(&s, a, j) == 0)
			{
				b[num++] = a[j];
			}
			else
			{
				if (s.flag == 1)
				{
					b[num++] = pop(&s);
				}
				else
				{
					while ((s.top != -1) && (func(&s, a, j) <= func(&s, s.stack, s.top)))
					{
						b[num++] = pop(&s);
					}
				}
				if ((func(&s, a, j) == 1) || (func(&s, a, j) == 2))
				{
					push(&s, a[j++]);
				}
				push(&s, a[j]);
			}
		}

		while (s.top != -1)
		{
			b[num++] = pop(&s);
		}

		printf("%s\n", b);
	}

	return 0;
}
