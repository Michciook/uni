#include <stdio.h>
#include <time.h>


void main() {
    FILE *fp;
    fp = fopen("/Users/oskarmichta/CLionProjects/untitled/tekst.csv", "w+");

    int n;
    long long l1=0, l2=1, l3;
    printf("Ile wyrazow ciagu chcesz policzyc: ");
    scanf("%d", &n);
    for(int i=2; i<=n; i++) {
        fprintf(fp, "%d\t", i);
        clock_t start = clock();
        l3=l1+l2;
        l1=l2;
        l2=l3;
        clock_t stop = clock();
        fprintf(fp, "%lld\t", l3);
        double time_spend = (double)(stop-start)/CLOCKS_PER_SEC;
        fprintf(fp, "%lf\t", time_spend);
        fprintf(fp, "\n");
    }
    fclose(fp);
}