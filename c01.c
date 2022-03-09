#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 6

void printArray(int arr[N][N])
{
    int i, j;
    for (i = 0; i < N; i++) {
    	for (j = 0; j < N; j++) {
        	printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillArray(int *arr[N][N]) {
	int r;
	srand(time(NULL));
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			r = rand()%10;
			arr[i][j] = r;	
		}
	}
}


void main() {
	int tab[N][N];
	int c, u;
	
	fillArray(*tab);
	printArray(tab);
	
	printf("Co chcesz zrobic?\n");
	printf("1 - Wyswietl przekatna\n");
	printf("2 - Wyswietl wiersz\n");
	printf("3 - Wyswietl kolumne\n");
	
	scanf("%d", &c);
	
	switch(c) {
		case 1:
			for(int i=0;i<N;i++) {
				printf("%d ", tab[i][i]);
			}
			break;
		case 2:
			printf("Ktory wiersz chcesz wyswietlic? ");
			scanf("%d", &u);
			for(int i=0;i<N;i++) {
				printf("%d ", tab[u-1][i]);
			}
			break;
		case 3:
			printf("Ktora kolumne chcesz wyswietlic? ");
			scanf("%d", &u);
			for(int i=0;i<N;i++) {
				printf("%d ", tab[i][u-1]);
			}
			break;
		default:
			printf("ERROR");
	}

}

