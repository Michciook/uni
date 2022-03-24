#include <stdio.h>

void myStrcat(char str1[], char str2[]) {
	//calculating length of first string
	int l, i=0, j=0;
	for(l=0; str1[l] != '\0'; l++);
	
	//concatenating two strings and leaving null as last character in array
	while(str2[i] != '\0') {
		str1[l] = str2[i];
		l++;
		i++;
	}
	
	str1[l] = '\0';
}

void printString(char str1[]) {
	for(int i=0; str1[i] != '\0'; i++) {
		printf("%c", str1[i]);
	}
	printf("\n");
}

void main()
{   
	char str1[100] = "Mus ", str2[100] = "meski blues";
	
	printString(str1);
	myStrcat(str1, str2);
	printString(str1);
	
}