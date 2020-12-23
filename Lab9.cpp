#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE 
#include "windows.h"
#include <locale>
#include <iostream>
using namespace std;

FILE* in, * out;
const int MAXLINE = 255;  // максимальная длина строки

void task1()
{
	in = fopen("F1.txt", "r");
	out = fopen("F2.txt", "w");
	char buf[MAXLINE];
	for (int i = 1; i <= 3; i++) //цикл работает 3 итерации, считываем первые три строки, доходим до 4-ой
		fgets(buf, MAXLINE, in);
	//далее до конца файла считываем оставшиеся и записываем во второй файл
	while (!feof(in))
	{
		fgets(buf, MAXLINE, in);
		fputs(buf, out);
	}
	fclose(in);
	fclose(out);
}

void task2()
{
	out = fopen("F2.txt", "r");
	char buf[MAXLINE];
	//считываем по порядку все строки файла, добираясь до последней
	while (!feof(out))
		fgets(buf, MAXLINE, out);
	//теперь в buf хранится последняя строка
	int i = 0;
	int countSymb = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != ' ' &&buf[i] != '.')
			countSymb++;
		if (buf[i] == ' ')
			countSymb = 0;
		i++;
	}
	cout << "Число символов последнего слова: " << countSymb << endl;
}

void main()
{
	setlocale(LC_ALL, "russian"); // чтобы на консоли отображались русские буквы
	task1();
	task2();
	system("pause"); // чтобы после выполнения программы консоль не исчезала сразу же
}