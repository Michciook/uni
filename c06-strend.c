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
	int i = myStrlen(str2);
	int j=0;
	while(1) {
		if(str1[i] != str2[j]) {
			return 0;
		} else if (str1[i] == "\0" && str2[i] == "\0") {
			return 1;
		}
		i++;
		j++;
	}
}

void main()
{   
	char str1[100] = "Mus meski blues", str2[100] = "meski blues";
	printf("%d", myStrend(str1, str2));
	
}