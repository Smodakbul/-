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
	s->stack = (char*)malloc(1000 * sizeof(char));
}

int isEmpty(Stack* s)
{
	if (s->top == -1)
	{
		return 1;
	}
	return 0;
}

void push(Stack* s, char data)
{
	if (s->top >= 999)
	{
		printf("Stack FULL\n");
		return;
	}
	s->top++;
	s->stack[s->top] = data;

}

char pop(Stack* s)
{
	if (s->top <= -1)
	{
		printf("Stack Empty\n");
		return;
	}
	return s->stack[s->top--];
}

int function(Stack* s, char* str)
{
	char ch;
	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
		{
			push(s, str[i]);
		}
		else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}'))
		{
			if (isEmpty(s))
			{
				return 0;
			}
			else
			{
				ch = pop(s);
				if (str[i] == ')')
				{
					if (ch != '(')
					{
						return 0;
					}
				}
				else if (str[i] == ']')
				{
					if (ch != '[')
					{
						return 0;
					}
				}
				else if (str[i] == '}')
				{
					if (ch != '{')
					{
						return 0;
					}
				}
			}
		}
	}
	return isEmpty(s);
}

void main()
{
	Stack s;
	initstack(&s);
	int cnt = 0;
	char* str;
	str = (char*)malloc(1000 * sizeof(char));

	gets(str);

	for (int i = 0; i < strlen(str); i++)
	{
		if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}') || (str[i] == '(') || (str[i] == '[') || (str[i] == '{'))
		{
			cnt++;
		}
	}
	if (function(&s, str) == 1)
	{
		printf("OK_%d", cnt);
	}
	else
	{
		printf("Wrong_%d", cnt);
	}
	free(str);

	return 0;
}