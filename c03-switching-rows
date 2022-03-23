#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 6

void fillArray(int array[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            *(array[i]+j) = rand()%10;
        }
    }
}

void printArray(int array[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", *(*(array+i)+j));
        }
        printf("\n");
    }
}

void switchRows(array[N][N]) {
    int u,o,temp;
    printf("Podaj pierwszy wiersz ktory chcesz zamienic: ");
    scanf("%d", &u);
    printf("Podaj drugi wiersz ktory chcesz zamienic: ");
    scanf("%d", &o);

    for(int i=0; i<N; i++) {
        temp = *(*(array+(u-1))+i);
        *(*(array+(u-1))+i) = *(*(array+(o-1))+i);
        *(*(array+(o-1))+i) = temp;
    }
}



void main() {
    int c;
    int arr[N][N];
    srand(time(NULL));

    fillArray(arr);
    printArray(arr);
    switchRows(arr);
    printArray(arr);

}