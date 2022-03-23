#include <stdio.h>

double dataAvr(int arr[], int c) {
	double res=0;
	for(int i=0; i<c;i++) {
		res = res+arr[i];
	}
	res = res/c;
	return res;
}

void dataInput(int arr[], int c) {
	for(int i=0; i<c; i++) {
		printf("Wprowadz dane nr %d: ", i+1);
		scanf("%d", &arr[i]);
	}
}



void main() {
	int c;
	
	printf("Ile danych chcesz wprowadzic: ");
	scanf("%d", &c);
	
	int * arr;
	arr = malloc(sizeof(int)*c);
	
	dataInput(arr, c);
		
	printf("Srednia arytmetyczna podanych danych wynosi: %.2f", dataAvr(arr, c));
	free(arr);

}