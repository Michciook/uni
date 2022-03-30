#include <stdio.h>

int myStrlen(char str1[]) {
    int l;
    for(l=0; str1[l] != '\0'; l++);
    return l;
}

void printString(char str1[]) {
    for(int i=0; str1[i] != '\0'; i++) {
        printf("%c", str1[i]);
    }
    printf("\n");
}

int myStrend(char str1[], char str2[]) {
    int i = myStrlen(str1) - myStrlen(str2);
    int j= 0;
    while(1) {
        if(str1[i] == NULL & str2[j] == NULL) {
            return 0;
        }
        if (str1[i] != str2[j]) {
            return 1;
        }
        i++;
        j++;
    }
}

void main() {
    char str1[100] = "Mus meski blues", str2[100] = " blues";
    printString(str1);
    printString(str2);
    switch(myStrend(str1, str2)) {
        case 1:
            printf("Pierwszy ciag znakow nie konczy sie drugim ciagiem znakow");
            break;
        case 0:
            printf("Pierwszy ciag znakow konczy sie drugim ciagiem znakow");
            break;
        default:
            printf("Error");
            break;
    }


}