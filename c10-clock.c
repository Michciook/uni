#include <stdio.h>
#include <time.h>

long long fib(int n) {
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

void main() {
    clock_t start = clock();
    fib(50);
    clock_t stop = clock();
    double time_spend = (double)(stop-start)/CLOCKS_PER_SEC;
    printf("%lf seconds", time_spend);
}

