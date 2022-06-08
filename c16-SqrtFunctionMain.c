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

int main(int argc, char** argv) {
    if(argc==7) {
        int x, x1, x2, a, b, c;
        char *p;

        long conv = strtol(argv[1], &p, 10);
        x = conv;
        conv = strtol(argv[2], &p, 10);
        x1 = conv;
        conv = strtol(argv[3], &p, 10);
        x2 = conv;
        conv = strtol(argv[4], &p, 10);
        a = conv;
        conv = strtol(argv[5], &p, 10);
        b = conv;
        conv = strtol(argv[6], &p, 10);
        c = conv;

        double xArr[x];
        arrayCreator(x1, x2, xArr, x);
        squareFunction(a, b, c, xArr, x);
    } else {
        int x1, x2, x = 0, a, b, c;
        printf("Program otwawrty bez parametrów lub została podana błędna ilość parametrów\n");
        while (x <= 0) {
            printf("Ile chcesz wyswietlic liczb: ");
            scanf("%d", &x);
            if (x <= 0) {
                printf("Podaj poprawną liczbę\n");
            }
        }
        double xArr[x];
        printf("Podaj x1: ");
        scanf("%d", &x1);
        printf("Podaj x2: ");
        scanf("%d", &x2);
        printf("Podaj parametr a: ");
        scanf("%d", &a);
        printf("Podaj parametr b: ");
        scanf("%d", &b);
        printf("Podaj parametr c: ");
        scanf("%d", &c);
        arrayCreator(x1, x2, xArr, x);
        squareFunction(a, b, c, xArr, x);
    }
    return 0;
}
