#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


typedef struct polynomials
{
	int coef;
	int exp;
	struct polynomials* next;
} poly;

void appendTerm(poly* k, int c, int e)
{
	poly* p, * t;
	t = (poly*)malloc(sizeof(poly));
	t->coef = c;
	t->exp = e;
	t->next = NULL;

	if (k->next == NULL)
	{
		k->next = t;
		return -1;
	}

	p = k->next;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = t;
}

poly* addPoly(poly* x, poly* y)
{
	poly* i, * j, * k;
	poly* result;
	int sum = 0;

	result = (poly*)malloc(sizeof(poly));
	result->next = NULL;

	i = x->next;
	j = y->next;
	k = result;

	while ((i != NULL) && (j != NULL))
	{
		if (i->exp > j->exp)
		{
			appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if ((i->exp < j->exp))
		{
			appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else
		{
			sum = i->coef + j->coef;
			if (sum != 0)
			{
				appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL)
	{
		appendTerm(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL)
	{
		appendTerm(k, j->coef, j->exp);
		j = j->next;
	}

	return k;
}

void main()
{
	int n, m, i, c, e; //c는 계수, e는 차수

	poly* x, * y, * z;

	x = (poly*)malloc(sizeof(poly));
	y = (poly*)malloc(sizeof(poly));
	z = (poly*)malloc(sizeof(poly));
	x->next = NULL;
	y->next = NULL;
	z->next = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &e);
		appendTerm(x, c, e);
	}

	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &c, &e);
		appendTerm(y, c, e);
	}

	z = addPoly(x, y);

	z = z->next;
	while (z != NULL)
	{
		printf(" %d %d", z->coef, z->exp);
		z = z->next;
	}

	return 0;
}