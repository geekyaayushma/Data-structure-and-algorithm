//Combination Formula
#include <stdio.h>
//1st method
int fact(int n)
{
 if(n==0)return 1;
 return fact(n-1)*n;
}

int nCr(int n,int r)
{
 int num,den;

 num=fact(n);
 den=fact(r)*fact(n-r);

 return num/den;
}
//Using Pascals triangle
int NCR(int n,int r)
{
 if(n==r || r==0)
 return 1;
 return NCR(n-1,r-1)+NCR(n-1,r);

}
int main()
{
 printf("%d \n",nCr(5,2));
 // The time complexity is O(n).
 printf("%d \n",NCR(5,3));
 // The time complexity for pascals method is O(2^n).
 return 0;
}