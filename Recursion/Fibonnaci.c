#include <stdio.h>
//using iterative
int fib(int n) {
    int t0=0, t1=1, s=0, i;

    if(n<=1) return n;

    for(i=2; i<=n; i++) {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }

    return s; // Return the Fibonacci number
}
//Using recursion
int rfib(int n) {
    if(n <= 1)
        return n;
    return rfib(n-2) + rfib(n-1);
}
//using memoniztaion
int F[10];

int mfib(int n) {
    if(n<=1) {
        F[n] = n;
        return n;
    }
    else {
        if(F[n-2] == -1)
            F[n-2] = mfib(n-2);
        if(F[n-1] == -1)
            F[n-1] = mfib(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}

int main() {
    int i;

    for(i=0; i<10; i++)
         printf("%d \t", fib(i)); 
        // Print Fibonacci numbers using iterative
    printf("\n%d\n", rfib(4));
    // The time complexity of this recursion is O(2^n).

    for(i = 0; i < 10; i++)
        F[i] = -1; // Initialize F array

    printf("%d \n", mfib(5));
    // The time complexity for memonization is O(n)
    return 0;
}
