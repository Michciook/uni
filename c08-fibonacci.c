#include <stdio.h>

long long fib(int n) {
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

void main() {
    int f;
    printf("Ktory wyraz ciagu fibonacciego chcesz wyswietlic: ");
    scanf("%d", &f);
    printf("%lld", fib(f));
}