#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *first = NULL; 

void Create(int A[], int n)
{
	int i=0;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for ( i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Max(struct Node *p)
{
    int max = INT32_MIN;

    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int main()
{
    int A[] = {2, 4, 6, 11, 99, 66};
    Create(A, 6);
    printf("Linked List: ");
    Display(first);
    printf("Max is %d\n", Max(first));
    return 0;
}
//The time complexity is O(n).
