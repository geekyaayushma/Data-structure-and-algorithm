//Indirect recursion
#include<stdio.h>

void funA(int n)
{
    if (n>0)
    {
        printf("%d\t",n);
        funB(n-1);
    }
}
void funB(int n)
{
    if (n>0)
    {
        printf("%d\t",n);
        funA(n/2);
    }
}
int main()
{
    int x=20;
    funA(x);
    return 0;
}