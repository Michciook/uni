#include <stdio.h>
#include <stdlib.h>

void arrayCreator(int x1, int x2, int xArr[], int size) {
    int range;
    if(x1 > 0 && x2 > 0 || x1 < 0 && x2 < 0) {
        range = abs(x1) - abs(x2);
    } else {
        range = abs(x1) + abs(x2)+1;
    }
    int jump = abs(range)/size;
    for(int i=0; i < abs(range)/jump-1; i++) {
        xArr[i] = x1 + i*jump;
    }
    xArr[size-1] = x2;
}

squareFunction(int a, int b, int c, int arr[], int size) {
    int y;
    FILE *fp;
    fp = fopen("/Users/oskarmichta/CLionProjects/untitled/tekst.csv", "w+");
    for(int i=0; i<size; i++) {
        y = arr[i]*arr[i]*a+b*arr[i]+c;
        fprintf(fp, "%d\t", arr[i]);
        fprintf(fp, "%d\n", y);
    }
    fclose(fp);
}

void main() {
    int x1,x2,x;
    printf("Ile chcesz wyswietlic liczb: ");
    scanf("%d", &x);
    int xArr[x];
    printf("Podaj x1: ");
    scanf("%d", &x1);
    printf("Podaj x2: ");
    scanf("%d", &x2);
    arrayCreator(x1, x2, xArr, x);
    squareFunction(-1,1,1,xArr, x);
}