//Inserting and Deleting in the lisked list
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*head;

void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    last->next = head; // Make it circular
}

void Display(struct Node *h)
{
    struct Node *temp = h;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != h);
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while(p != head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > Length(p))
        return;

    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(i = 0; i < index-1; i++)
            p = p->next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x, i;

    if(index < 0 || index > Length(p))
        return -1;

    if(index == 1)
    {
        while(p->next != head)
            p = p->next;
        x = head->data;
        if(p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for(i = 0; i < index-2; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Create(A, 5);
    Display(head);

    Insert(head, 5, 20); 
    Display(head);

    printf("Deleted element: %d\n", Delete(head, 2)); 
    Display(head);

    return 0;
}
