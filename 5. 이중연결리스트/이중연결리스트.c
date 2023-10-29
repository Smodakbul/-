#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int nodecount = 0;

typedef struct Node {
    char elem;
    struct Node* prev;
    struct Node* next;
}node;

node* head;
node* trail;

void add(node* head, node* trail, int rank, char e)
{
    if ((nodecount < rank - 1) || (rank < 1))
    {
        printf("invalid position\n");
        return -1;
    }
    node* tmp = head;
    node* newnode = (node*)malloc(sizeof(node));

    newnode->elem = e;
    newnode->next = NULL;
    newnode->prev = NULL;


    if (nodecount == 0)
    {
        head->next = newnode;
        trail->prev = newnode;
        newnode->next = trail;
        newnode->prev = head;
        nodecount++;
    }

    else
    {
        for (int i = 0; i < rank; i++)
        {
            tmp = tmp->next;
        }


        newnode->prev = tmp->prev;
        newnode->next = tmp;
        tmp->prev->next = newnode;
        tmp->prev = newnode;
        nodecount++;
    }
}


void delete(node* head, node* trail, int rank)
{
    if ((nodecount < rank) || (rank < 1))
    {
        printf("invalid position\n");
        return-1;
    }
    node* p = head;

    for (int i = 0; i < rank; i++)
    {
        p = p->next;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;

    nodecount--;
}


char get(node* head, node* trail, int rank)
{
    if ((nodecount < rank) || (rank < 1))
    {
        printf("invalid position");
        return NULL;
    }
    node* tmp = head;

    for (int i = 0; i < rank; i++)
        tmp = tmp->next;
    return tmp->elem;
}

void print(node* head, node* trail)
{
    node* p;
    p = head->next;
    while (p != trail)
    {
        printf("%c", p->elem);
        p = p->next;
    }
    printf("\n");
}



int main()
{
    head = (node*)malloc(sizeof(node));
    trail = (node*)malloc(sizeof(node));
    head->next = trail;
    trail->prev = head;
    head->prev = NULL;
    trail->next = NULL;

    int N, rank;
    char command, e;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        getchar();
        scanf("%c", &command);
        if (command == 'A')
        {
            scanf("%d %c", &rank, &e);
            add(head, trail, rank, e);
        }

        else if (command == 'D')
        {
            scanf("%d", &rank);
            delete(head, trail, rank);
        }

        else if (command == 'G')
        {
            scanf("%d", &rank);
            char temp = get(head, trail, rank);
            if (temp != NULL)
            {
                printf("%c\n", temp);
            }
        }

        else if (command == 'P')
        {
            print(head, trail);
        }

    }

    return 0;
}