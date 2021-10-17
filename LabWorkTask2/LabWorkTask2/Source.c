#pragma warning(disable:4996)
#include <io.h> 
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <process.h> 
#define TRUE 1

typedef struct {
	char FirstName[15], SecondName[15], LastName[15];
	unsigned Age;
	char Sex[7];
} Person;

void InitFile(char*, char*, long);
Person* InitPerson();
void DisplayFile(char*, char*);
void DisplayPerson(Person*);
void AddToEndFile(char*, char*, long);
void RemoveElementFromFile(char*, char*, long);

int main(void) {
	char FileName[20];
	char Key;
	long Number;
	
	puts("Enter the name of file: ");
	gets(FileName);

	system("cls");

	while(TRUE) {
		printf("\n Enter the number - the mode of “ “operations with file : " 
			"\n 1 - FORMATION OF THE FILE"
			"\n 2 - VIEWING OF CONTENTS OF THE FILE"
			"\n 3 - ADD AN ELEMENT TO AND OF FILE"
			"\n 4 - REMOVE THE ELEMENT IN THE FILE"
			"\n 5 - EXIT\n");

		fflush(stdin);
		scanf("%c", &Key);
		system("cls");

		switch (Key) {
		case '1':
			while (TRUE) {
				printf("\nEnter the number of “ “persons:"); 
				scanf("%ld", &Number);
				if (Number > 0) break;
				printf("\n Number is incorrect!” “ Try again!!!\n"); 
			}
			InitFile(FileName, "wb", Number);
			printf("\n\nPress any key to return in “ “the menu..."); 
			system("cls");
			break;
		case '2':
			DisplayFile(FileName, "rb");
			printf("\n\nPress any key to return in “the menu..."); 
			system("cls");
			break;
		case '3':
			while (TRUE) {
				printf("\nEnter the number of “ “persons to addition : "); 
				scanf("%ld", &Number);
				if (Number > 0) break;
				printf("\n Number is incorrect!” “ Try again!!!\n"); 
			}
			AddToEndFile(FileName, "ab", Number);
			printf("\n\nPress any key to return in “ “the menu..."); 
			system("cls");
			break;
		case '4':
			printf("\nEnter number of element from “ “removing :"); 
			scanf("%ld", &Number);
			RemoveElementFromFile(FileName, "r+b", Number);
			printf("\n\nPress any key to return in “ “the menu..."); 

				getch();

			clrscr();

			break;

		case '5': return 0;

		default:

			printf("\nIncorrect input!” 

				“ Try again!!!"); 

				printf("\n\nPress any key to return in” 

					“ the menu..."); 

					getch();

			clrscr();

			break;

		}

	}

}