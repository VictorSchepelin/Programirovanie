#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE 
#include "windows.h"
#include <locale>
#include <iostream>
using namespace std;

FILE* f; // указатель на файл
int N;  // количество записей в файле

struct HUMAN
{
	char surname[50];		//фамилия
	char name[50];			//имя
	char patronymic[50];	//отчество
	char address[60];		//домашний адрес
	int age;				//возраст
	char telephone[11];		//телефон
};

HUMAN newHUMAN() //функция создания нового элемента
{
	HUMAN s;
	cout << "Фамилия: ";
	cin >> s.surname;
	cout << "Имя: ";
	cin >> s.name;
	cout << "Отчество: ";
	cin >> s.patronymic;
	cout << "Домашний адрес: ";
	cin >> s.address;
	cout << "Возраст: ";
	cin >> s.age;
	cout << "Телефон: ";
	cin >> s.telephone;
	return s;
}

void createFile() //процедура формирования файла
{
	f = fopen("f.dat", "wb");
	if (f == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	cout << "____________________ Формирование файла ____________________" << endl;
	N = 0;
	HUMAN en;
	int answer;
	do
	{
		en = newHUMAN();
		fwrite(&en, sizeof(HUMAN), 1, f);
		if (ferror(f) != NULL)
		{
			cout << "ОШИБКА ПРИ ЗАПИСИ В ФАЙЛ!";
			exit(2);
		}
		N++;
		answer = 0;
		do
		{
			cout << "Записать следующую структуру? ДА - 1	НЕТ - 0		Ответ: ";
			cin >> answer;
		} while (answer != 1 && answer != 0);
	} while (answer != 0);
	fclose(f);
}

void readFile()  //процедура чтения записей из файла
{
	cout << "\n____________________ Содержимое файла ____________________" << endl;
	f = fopen("f.dat", "rb");
	if (f == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	HUMAN en;
	int k = 0;
	while (!feof(f) && k < N)
	{
		fread(&en, sizeof(HUMAN), 1, f);
		if (ferror(f) != NULL)
		{
			cout << "ОШИБКА ПРИ ЧТЕНИИ ИЗ ФАЙЛА!";
			exit(4);
		}
		k++;
		cout << "Фамилия: " << en.surname << endl;
		cout << "Имя: " << en.name << endl;
		cout << "Отчество: " << en.patronymic << endl;
		cout << "Домашний адрес: " << en.address << endl;
		cout << "Возраст: " << en.age << endl;
		cout << "Телефон: " << en.telephone << endl << endl;
	}
	fclose(f);
}

void addFile() //процедура добавления элемента в файл
{
	cout << "\n____________________ Добавление элемента в файл ____________________\n";
	HUMAN newEn;
	cout << "\n-----Новый элемент: \n";
	newEn = newHUMAN();
	int num;
	cout << "После элемента с каким номером добавить новый элемент? Ответ: ";
	cin >> num;
	f = fopen("f.dat", "rb");
	if (f == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	FILE* t;
	t = fopen("t.dat", "wb");
	if (t == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	HUMAN en;
	for (int i = 1; i <= N; i++)
	{
		fread(&en, sizeof(HUMAN), 1, f);
		if (ferror(f) != NULL)
		{
			cout << "ОШИБКА ПРИ ЧТЕНИИ ИЗ ФАЙЛА!";
			exit(4);
		}
		fwrite(&en, sizeof(HUMAN), 1, t);
		if (ferror(t) != NULL)
		{
			cout << "ОШИБКА ПРИ ЗАПИСИ В ФАЙЛ!";
			exit(2);
		}
		if (i == num)
		{
			fwrite(&newEn, sizeof(HUMAN), 1, t);
			if (ferror(t) != NULL)
			{
				cout << "ОШИБКА ПРИ ЗАПИСИ В ФАЙЛ!";
				exit(2);
			}
		}

	}
	N++;
	fclose(f);
	fclose(t);
	remove("f.dat");
	rename("t.dat", "f.dat");
}

void deleteFile()  //процедура удаления элемента из файла
{
	cout << "\n____________________ Удаление элемента из файла ____________________\n";
	int ageDel;
	cout << "Элементы с каким возрастом будем удалять? Ответ: ";
	cin >> ageDel;
	f = fopen("f.dat", "rb");
	if (f == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	FILE* t;
	t = fopen("t.dat", "wb");
	if (t == NULL)
	{
		cout << "ОШИБКА ПРИ ОТКРЫТИИ ФАЙЛА!";
		exit(1);
	}
	HUMAN en;
	int countDel = 0;
	for (int i = 1; i <= N; i++)
	{
		fread(&en, sizeof(HUMAN), 1, f);
		if (ferror(f) != NULL)
		{
			cout << "ОШИБКА ПРИ ЧТЕНИИ ИЗ ФАЙЛА!";
			exit(4);
		}
		if (ageDel != en.age) //если возраст не подходит под условие, записываем структуру в файл.
		{
			fwrite(&en, sizeof(HUMAN), 1, t);
			if (ferror(t) != NULL)
			{
				cout << "ОШИБКА ПРИ ЗАПИСИ В ФАЙЛ!";
				exit(2);
			}
		}
		else  //Иначе пропускаем, увеличивая счетчик удаленных
			countDel++;
	}
	N = N - countDel; //уменьшаем число записей в файле
	fclose(f);
	fclose(t);
	remove("f.dat"); //удаляем старый файл
	rename("t.dat", "f.dat"); //переименовываем вспомогательный файл в наш рабочий
}

void main()
{
	setlocale(LC_ALL, "Russian"); // чтобы на консоли отображались русские буквы
	SetConsoleCP(1251);			//устанавливаем на консоль кодировку для ввода
	SetConsoleOutputCP(1251);	//кодировку для вывода
	createFile();
	readFile();
	addFile();
	cout << "\nФайл после добавления новых элементов: \n";
	readFile();
	deleteFile();
	cout << "\nФайл после удаления элементов: \n";
	readFile();
	system("pause"); // чтобы после выполнения программы консоль не исчезала сразу же
}