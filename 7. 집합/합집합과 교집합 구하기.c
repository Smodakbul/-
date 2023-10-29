#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;

typedef struct LinkedList
{
    struct node* header;
}List;

node* newnode(int data)
{
    node* new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->data = data;
    return new;
}

void add(List* N, int data)
{
    node* new = newnode(data);
    node* temp = N->header;

    if (N->header == NULL)
        N->header = new;

    else {

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new;
    }
}

List* Union(List* A, List* B) {

    List* result = (List*)malloc(sizeof(List));
    node* tmp1, * tmp2;
    tmp1 = A->header;
    tmp2 = B->header;
    result->header = NULL;

    while (tmp1 && tmp2) {

        if (tmp1->data == tmp2->data) {

            add(result, tmp1->data);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        else if (tmp1->data < tmp2->data) {

            add(result, tmp1->data);
            tmp1 = tmp1->next;
        }

        else
        {
            add(result, tmp2->data);
            tmp2 = tmp2->next;
        }
    }

    for (; tmp1; tmp1 = tmp1->next)
    {
        add(result, tmp1->data);
    }

    for (; tmp2; tmp2 = tmp2->next)
    {
        add(result, tmp2->data);
    }

    return result;
}

List* Intersect(List* A, List* B)
{
    List* ans = (List*)malloc(sizeof(List));
    node* temp1, * temp2;

    temp1 = A->header;
    temp2 = B->header;
    ans->header = NULL;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            add(ans, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        else if (temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }

        else
        {
            temp2 = temp2->next;
        }
    }

    return ans;
}

int main()
{
    List* A, * B;
    List* Uni;
    node* temp;
    int a, b;
    int data;
    A = (List*)malloc(sizeof(List));
    A->header = NULL;

    B = (List*)malloc(sizeof(List));
    B->header = NULL;


    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &data);
        add(A, data);
    }

    scanf("%d", &b);
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &data);
        add(B, data);
    }

    Uni = Union(A, B);
    temp = Uni->header;

    if (temp == NULL)
    {
        printf(" 0");
    }

    while (temp)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");

    List* intersect = Intersect(A, B);
    temp = intersect->header;

    if (temp == NULL)
    {
        printf(" 0");
    }

    while (temp)
    {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}