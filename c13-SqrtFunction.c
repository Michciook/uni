#include <stdio.h>
#include <stdlib.h>

void arrayCreator(int x1, int x2, double xArr[], int size) {
    int range;
    if(x1 > 0 && x2 > 0 || x1 < 0 && x2 < 0) {
        range = abs(x1) - abs(x2);
    } else {
        range = abs(x1) + abs(x2);
    }
    double jump = (double)abs(range)/(size-1);
    for(int i=0; i < abs(range)/jump; i++) {
        xArr[i] = x1 + i*jump;
    }
    xArr[size-1] = x2;
}

void squareFunction(int a, int b, int c, double arr[], int size) {
    double y;
    FILE *fp;
    fp = fopen("tekst.csv", "w+");
    for(int i=0; i<size; i++) {
        y = (double)arr[i]*arr[i]*a+b*arr[i]+c;
        fprintf(fp, "%f\t", arr[i]);
        fprintf(fp, "%f\n", y);
    }
    fclose(fp);
}

int main() {
    int x1,x2,x=0;
    while(x<=0) {
        printf("Ile chcesz wyswietlic liczb: ");
        scanf("%d", &x);
        if(x<=0) {
            printf("Podaj poprawną liczbę\n");
        }
    }
    double xArr[x];
    printf("Podaj x1: ");
    scanf("%d", &x1);
    printf("Podaj x2: ");
    scanf("%d", &x2);
    arrayCreator(x1, x2, xArr, x);
    squareFunction(-1,1,1,xArr, x);
    return 0;
}