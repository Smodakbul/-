#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

node* newnode(int data)
{
    node* new = (node*)malloc(sizeof(node));

    new->next = NULL;
    new->data = data;

    return new;
}

void add(node* N, int data)
{
    node* new = newnode(data);
    node* temp = N;

    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new;
}

int subset(node* A, node* B, int a, int b)
{
    int result = 0, num, i, j;
    node* tmp1, * tmp2;
    node* prev;


    num = a;
    tmp1 = A;

    for (i = 0; i < a; i++)
    {
        tmp2 = B;
        for (j = 0; j < b; j++)
        {
            if (tmp1->data == tmp2->data)
            {
                num--;
                break;
            }
            tmp2 = tmp2->next;
        }

        if (j == b)
        {
            result = tmp1->data;
            return result;
        }

        tmp1 = tmp1->next;
    }

    return result;
}

void main()
{
    node* A = NULL, * B = NULL;
    int a, b, data, i;

    scanf("%d", &a);

    if (a == 0)
    {
        A = newnode(NULL);
    }
    else {
        for (i = 0; i < a; i++)
        {
            scanf("%d", &data);

            if (i == 0)
            {
                A = newnode(data);
            }

            else
            {
                add(A, data);
            }
        }
    }
    scanf("%d", &b);

    if (b == 0)
    {
        B = newnode(NULL);
    }
    else {
        for (i = 0; i < b; i++)
        {
            scanf("%d", &data);
            if (i == 0)
            {
                B = newnode(data);
            }

            else
            {
                add(B, data);
            }
        }
    }
    printf("%d", subset(A, B, a, b));
    return 0;

}
