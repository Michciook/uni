#include <stdio.h>
#include <time.h>

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
        fprintf(fp, "%d\t", i);
        clock_t start = clock();
        fprintf(fp, "%lld\t", fib(i));
        clock_t stop = clock();
        double time_spend = (double)(stop-start)/CLOCKS_PER_SEC;
        fprintf(fp, "%lf\t", time_spend);
        fprintf(fp, "\n");
    }
    fclose(fp);
}