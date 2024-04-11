//Displaying linked list using Recursion
#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;
void Create(int A[],int n )
{
    int i;
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void RecursionDisplay(struct Node *p)
{
    if (p!=NULL)
    printf("%d\t",p->data);
    RecursionDisplay(p=p->next);
}
int main()
{
    int A[]={2,4,6,7,9,55};
    Create(A,6);
    RecursionDisplay(first);
    return 0;
}
//The time complexity is O(n).
