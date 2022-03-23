#import <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 6

void fillArray(int array[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            array[i][j] = rand()%10;
        }
    }
}

void printArray(int array[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void diagArray(int array[N][N]) {
    for(int i=0;i<N;i++) {
        printf("%d ", array[i][i]);
    }
}

void rowArray(int array[N][N]) {
    int u;
    printf("Ktory wiersz chcesz wyswietlic? ");
    scanf("%d", &u);
    for(int i=0;i<N;i++) {
        printf("%d ", array[u-1][i]);
    }
}

void colArray(int array[N][N]) {
    int u;
    printf("Ktora kolumne chcesz wyswietlic? ");
    scanf("%d", &u);
    for(int i=0;i<N;i++) {
        printf("%d ", array[i][u-1]);
    }

}


void main() {
    int c;
    int arr[N][N];
    srand(time(NULL));

    fillArray(arr);
    printArray(arr);

    printf("Co chcesz zrobic?\n");
    printf("1 - Wyswietl przekatna\n");
    printf("2 - Wyswietl wiersz\n");
    printf("3 - Wyswietl kolumne\n");

    scanf("%d", &c);

    switch(c) {
        case 1:
            diagArray(arr);
            break;
        case 2:
            rowArray(arr);
            break;
        case 3:
            colArray(arr);
            break;
        default:
            printf("ERROR");
    }

}