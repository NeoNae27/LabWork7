#include <conio.h> 
#include <stdio.h> 
#include <process.h> 
#include <string.h>
#include <stdlib.h> 

int ContentsFile(char*, char*);
int* InitMassive(char*, char*, unsigned);
void BubbleSort(int*, unsigned);
void AddFile(char*, char*, int*, unsigned);

int ContentsFile(char* String, char* Mode) {
	unsigned Number = 0, Term;
	FILE* FilePointer = fopen_s(&FilePointer, String, Mode);
	if (FilePointer == NULL) {
		return Number;
	}
	while (!feof(FilePointer)) {
		fscanf_s(FilePointer, "%d\n", &Term);
		printf(" %d", Term);
		Number++;
	}
	fclose(FilePointer);

	return Number;
}

int main() {
	char FileName[20];
	int* Arr;
	unsigned Number;

	printf("\nEnter the name of file: ");
	gets(FileName);
	system("cls");

	printf("\n The contents of the File <<%s>>:",FileName);
	Number = ContentsFile(FileName, "r");
}
