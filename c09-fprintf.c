#include <stdio.h>

long long fib(int n) {
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

void main() {
    FILE *fp;
    fp = fopen("/Users/oskarmichta/CLionProjects/untitled/tekst.csv", "w+");

    int n;
    printf("Ile wyrazow ciagu chcesz policzyc: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        fprintf(fp, "%lld, ", fib(i));
    }
    fclose(fp);
}