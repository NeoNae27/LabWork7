МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ
федеральное государственное бюджетное образовательное учреждение
высшего образования
«САНКТ-ПЕТЕРБУРГСКИЙ ГОСУДАРСТВЕННЫЙ
ЛЕСОТЕХНИЧЕСКИЙ  УНИВЕРСИТЕТ
имени С.М. Кирова»

Институт леса и природопользования
Кафедра информационных систем и технологий



Лабораторная работа №7

На тему «Файлы»


Направление подготовки 09.03.02 «Информационные системы и технологии»
        	
Номер зачетной книжки: 300275.
Обучающийся: Романов Никита Олегович
Группа: ИСиТ 20-3
Преподаватель: к.т.н., доцент Колмогорова Светлана Сергеевна

Оценка:

Задание №1
	Отсортировать одномерный целочисленный массив, находящийся в текстовом файле, методом «пузырька». Отсортированный массив дописать в конец исходного файла.
Демонстрация работы программы:
Пишем название файла(в данном случаи “test.txt”)
Получаем содержимое файла и сортируем его. Ответ записываем в конец.

Код:
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


Задание №2
На основе структуры вида «Человек» (фамилия, имя, отчество, пол, возраст) создать бинарный файл. Вывести на экран содержимое файла. Удалить из файла элемент с заданным номером, изменяя при этом размер файла. Добавить элемент в конец файла.
Демонстрация работы программы:
Вводим имя файла, с которым мы будем работать.
Выбираем операцию
Операция №1. Форматируем содержимое файла и добавляем туда новые данные.
Операция №2. Показывает содержимое файла.
Операция №3. Добавляем новые данные в файл.
Операция №4. Удаляем один элемент в файле.

Код:
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
		printf("Enter the number - the mode of operations with file : " 
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
				printf("Enter the number of persons:"); 
				scanf("%ld", &Number);
				if (Number > 0) break;
				printf("\nNumber is incorrect! Try again!!!\n"); 
			}
			InitFile(FileName, "wb", Number);
			printf("Press any key to return in the menu...\n");
			getch();
			system("cls");
			break;
		case '2':
			DisplayFile(FileName, "rb");
			printf("\nPress any key to return in the menu...\n");
			getch();
			system("cls");
			break;
		case '3':
			while (TRUE) {
				printf("\nEnter the number of persons to addition:"); 
				scanf("%ld", &Number);
				if (Number > 0) break;
				printf("\nNumber is incorrect! Try again!!!\n"); 
			}
			AddToEndFile(FileName, "ab", Number);
			printf("\nPress any key to return in the menu...");
			getch();
			system("cls");
			break;
		case '4':
			printf("Enter number of element from removing:\n"); 
			scanf("%ld", &Number);
			RemoveElementFromFile(FileName, "r+b", Number);
			printf("Press any key to return in the menu...\n");
			getch();
			system("cls");
			break;
		case '5': 
			return 0;
		default:
			system("cls");
			break;
		}
	}
}

void InitFile(char* String, char* Mode, long n) {
	long i;
	int BufSize = sizeof(Person);
	Person* Man = NULL;
	FILE* FileStruct = fopen(String, Mode);
	if (FileStruct == NULL) {
		printf("Can't open file to write.");
		abort();
	}
	for (i = 1; i <= n; i++) {
		printf("Enter information for the person number % ld \n", i); 
		Man = InitPerson();
		fwrite(Man, BufSize, 1, FileStruct);
	}
	free(Man);
	fclose(FileStruct);
}

void AddToEndFile(char* String, char* Mode, long n) {
	long i;
	int BufSize = sizeof(Person);
	Person* Man = NULL;
	FILE* FileStruct = fopen(String, Mode);

	if (FileStruct == NULL) {
		printf("Can't open file to write.");
		abort();
	}

	for (i = 1; i <= n; i++) {
		printf("\nEnter information for the person number % ld \n", i); 
		Man = InitPerson();
		fwrite(Man, BufSize, 1, FileStruct);
	}

	free(Man);
	fclose(FileStruct);
}

void RemoveElementFromFile(char* String, char* Mode, long Position) {
	FILE* FileStruct = fopen(String, Mode);
	int DescriptorFile = fileno(FileStruct);
	long LengthFile = filelength(DescriptorFile);
	int BufSize = sizeof(Person);
	Person* Man = (Person*)malloc(BufSize);
	long NewLength = LengthFile - BufSize;

	if (FileStruct == NULL) {
		printf("Can't open file to write.");
		abort();
	}

	fseek(FileStruct, Position * BufSize, SEEK_SET);
	while (fread(Man, BufSize, 1, FileStruct) != 0) {
		fseek(FileStruct, -2 * (long)BufSize, SEEK_CUR);
		fwrite(Man, BufSize, 1, FileStruct);
		fseek(FileStruct, (long)BufSize, SEEK_CUR);
	}

	DescriptorFile = chsize(DescriptorFile, NewLength);
	free(Man);
	fclose(FileStruct);
}

Person* InitPerson() {
	Person* Man = (Person*)malloc(sizeof(Person));
	printf("\nEnter first name:");
	scanf("%s", Man->FirstName);

	printf("\nEnter second name:");
	scanf("%s", Man->SecondName);

	printf("\nEnter last name:");
	scanf("%s", Man->LastName);

	printf("\nEnter age:");
	scanf("%d", &Man->Age);

	printf("\nEnter sex:");
	scanf("%s", Man->Sex);

	return Man;
}

void DisplayFile(char* String, char* Mode) {
	int BufSize = sizeof(Person);
	Person* Man = (Person*)malloc(BufSize);
	FILE* FileStruct = fopen(String, Mode);

	if (FileStruct == NULL) {
		printf("Can't open file to read.");
		getch();
		abort();
	}

	while (fread(Man, BufSize, 1, FileStruct) != 0)	{
		DisplayPerson(Man);
	}
	free(Man);
	fclose(FileStruct);
}

void DisplayPerson(Person* Man) {
	printf("\n%s %s %s, %d year, %s ", Man->FirstName,
		Man->SecondName, Man->LastName, Man->Age,
		Man->Sex);
}

