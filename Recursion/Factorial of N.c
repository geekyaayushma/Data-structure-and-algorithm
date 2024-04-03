//Factorial of N
#include<stdio.h>
int fact(int n)
{
 if(n==0)
 return 1;
 return fact(n-1)*n;
}
// Usong Iteration 
int Ifact(int n)
{
 int f=1,i;
 for(i=1;i<=n;i++)
 f=f*i;
 return f;
}
int main()
{
 int r=Ifact(5);
 int a=fact(6);
 printf("%d\n%d",r,a);
 return 0;
} 