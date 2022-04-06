#include <stdio.h>

int factorial(int n) {
    if(n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

void main() {
    int f;
    printf("Podaj liczbe: ");
    scanf("%d", &f);
    printf("%d", factorial(f));
}