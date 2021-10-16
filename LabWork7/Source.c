#include <conio.h> 
#include <stdio.h> 
#include <process.h> 
#include <string.h>
#include <stdlib.h> 

int ContentsFile(char*, char*);
int* InitMassive(char*, char*, unsigned);
void BubbleSort(int*, unsigned);
void AddFile(char*, char*, int*, unsigned);

int main() {
	char FileName[20];
	int* Arr;
	unsigned Number;

	printf("\nEnter the name of file: ");
	gets(FileName);
	system("cls");

	printf("\n The contents of the File <<%s>> “ “:\n",FileName); 
}