//Taylor Series
#include <stdio.h>
double ea(int x, int n)
{
 static double p=1,f=1;
 double r;

 if(n==0)
 return 1;
 r=ea(x,n-1);
 p=p*x;
 f=f*n;
 return r+p/f;
}
//Taylor Series Horner’s Rule
double eb(int x, int n)
{
 static double s;
 if(n==0)
 return s;
 s=1+x*s/n;
 return eb(x,n-1);
}
//Taylor Serie Iterative
double e(int x, int n)
{
 double s=1;
 int i;
 double num=1;
 double den=1;

 for(i=1;i<=n;i++)
 {
 num*=x;
 den*=i;
 s+=num/den;
 }
 return s;
}
int main()
{
 printf("%lf Taylor series\n",ea(3,10));
 printf("%lf Taylor series using Horner's\n",eb(2,10)); 
 printf("%lf Taylor series using Iterative \n",e(1,10));
 return 0;
}