#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale>
#include <iostream>;
using namespace std;

struct complex
{
	int real;	//действительная часть
	int image;	//мнимая часть
};

int sub(int x, int y)
{
	int rez = x - y;
	return rez;
}

complex sub(complex x, complex y)
{
	complex rez;
	rez.real = x.real - y.real;
	rez.image = x.image - y.image;
	return rez;
}

void main()
{
	setlocale(LC_ALL, "russian");
	int r1, r2;
	cout << "Введите два целых числа: " << endl;
	cout << "Число №1: ";
	cin >> r1;
	cout << "Число №2: ";
	cin >> r2;
	cout << endl;
	complex c1, c2;
	cout << "Введите два комплексных числа: " << endl;
	cout << "---Комплексное число №1: " << endl;
	cout << "Действительная часть: ";
	cin >> c1.real;
	cout << "Мнимая часть: ";
	cin >> c1.image;
	cout << "---Комплексное число №2: " << endl;
	cout << "Действительная часть: ";
	cin >> c2.real;
	cout << "Мнимая часть: ";
	cin >> c2.image;
	cout << endl;
	int rez1 = sub(r1, r2); //вызов функции для целых чисел
	cout << "Вычитание целых чисел: " << r1 << " - " << r2 << " = " << rez1 << endl;
	complex rez2 = sub(c1, c2); //вызов функции для комплексных чисел
	cout << "Вычитание комплексных чисел:" << endl;
	cout << "(" << c1.real << " + " << c1.image << "i) - (" << c2.real << " + " << c2.image << "i) = " << rez2.real << " + " << rez2.image << "i" << endl;
	system("pause"); // чтобы после выполнения программы консоль не исчезала сразу же
}