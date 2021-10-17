#pragma warning(disable:4996)
#include <conio.h> 
#include <stdio.h> 
#include <process.h> 
#include <stdlib.h> 

int ContentsFile(char*, char*);
int* InitMassive(char*, char*, unsigned);
void BubbleSort(int*, unsigned);
void AddFile(char*, char*, int*, unsigned);

int ContentsFile(char* String, char* Mode) {
	unsigned Number = 0, Term;
	FILE* FilePointer = fopen(String, Mode);
	if (FilePointer == NULL) return Number;
	while (!feof(FilePointer)) {
		fscanf(FilePointer, "%d\n", &Term);
		printf(" %d", Term);
		Number++;
	}

	fclose(FilePointer);
	return Number;
}

int* InitMassive(char* String, char* Mode, unsigned Number) {
	unsigned i;
	int* Pointer = (int*)malloc(Number * sizeof(int));
	FILE* FilePointer = fopen(String, Mode);
	if (FilePointer == NULL) return NULL;
	for (i = 0; i < Number; i++) {
		fscanf(FilePointer, "%d\n", &Pointer[i]);
	}
	fclose(FilePointer);
	return Pointer;
}

void BubbleSort(int* Pointer, unsigned Number) {
	unsigned i, j;
	int x;

	for (i = 0; i < Number; i++) {
		for (j = Number - 1; j > i; j--) {
			if (Pointer[j] < Pointer[j - 1]) {
				x = Pointer[j];
				Pointer[j] = Pointer[j - 1];
				Pointer[j - 1] = x;
			}
		}
	}
}

void AddFile(char* String, char* Mode, int* Pointer, unsigned Number) {
	unsigned i;
	FILE* FilePointer = fopen(String, Mode);
	if (FilePointer == NULL) {
		printf("Can't open file to addition!");
		exit(1);
	}
	
	for (i = 0; i < Number; i++) {
		fprintf(FilePointer, "%d\n", Pointer[i]);
	}
	fclose(FilePointer);
}

int main(void) {
	char FileName[20];
	int* Arr;
	unsigned Number;

	printf("\nEnter the name of file: ");
	gets(FileName);
	system("cls");

	printf("\n The contents of the File <<%s>>:\n", FileName);
	Number = ContentsFile(FileName, "r");

	if (Number == 0) {
		system("cls");
		printf("\tFile <<%s>> is empty!\n", FileName);
		printf("\n\t Press any key to exit...");
		return 0;
	}

	Arr = InitMassive(FileName, "r", Number);
	if (Arr == NULL) {
		printf("\tDinamic array don't exist!\n");
		printf("\n\t Press any key to exit...");
		return 0;
	}
	BubbleSort(Arr, Number);
	AddFile(FileName, "a", Arr, Number);
	
	free(Arr);
	printf("\n New contents of the File <<%s>> :\n", FileName);
	Number = ContentsFile(FileName, "r");
	printf("\n Press any key to exit...");
	return 0;
}