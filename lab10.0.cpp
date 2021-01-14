#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <cstdlib> 
#include <iostream> 
#include <math.h>
#include <ctime>
#include <locale>
using namespace std;

int* createArray(int n)	// функция выделения памяти и заполнения массива
{
	srand(time(0)); // автоматическая рандомизация
	int* a;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
	return a;
}

void printArray(int* a, int n) // печать массива в файл и параллельно на консоль
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void deleteArray(int* a, int n)  // освобождение памяти
{
	delete[]a;
}

bool deleteTask(int*& ar, int n)
{
	int k;
	cout << "Введите номер элемента для удаления: ";
	cin >> k;
	if (k > n || k < 1)
	{
		cout << "Выход за границы массива!\n";
		return false;
	}
	int* newAr = new int[n - 1];
	for (int i = 0; i < k - 1; i++)
		newAr[i] = ar[i];
	for (int i = k; i < n; i++)
		newAr[i - 1] = ar[i];
	deleteArray(ar, n);
	ar = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
		ar[i] = newAr[i];
	deleteArray(newAr, n - 1);
	return true;
}

int addTask(int* ar, int n)
{
	srand(time(0)); // автоматическая рандомизация
	int pos, k;
	cout << "Введите номер позиции, после которого будем вставлять новые элементы: ";
	cin >> pos;
	if (pos > n || pos < 1)
	{
		cout << "Выход за границы массива!\n";
		return n;
	}
	cout << "Введите количество новых элементов: ";
	cin >> k;

	int* newAr = new int[n + k];
	for (int i = 0; i < pos; i++)
		newAr[i] = ar[i];
	for (int i = pos; i < pos + k; i++)
		newAr[i] = 0;
	for (int i = pos + k; i < n + k; i++)
		newAr[i] = ar[i - k];

	deleteArray(ar, n);
	ar = new int[n + k];
	for (int i = 0; i < n + k; i++)
		ar[i] = newAr[i];
	deleteArray(newAr, n + k);
	cout << "Результат: " << endl;
	printArray(ar, n + k);
	return n + k;
}

int main()
{
	setlocale(LC_ALL, "russian");
	int N = 0;
	cout << "Введите размер массива: ";
	cin >> N;
	int* mas = createArray(N);
	cout << "Исходный массив: " << endl;
	printArray(mas, N);
	if (deleteTask(mas, N))
		N--;
	cout << "Результат: " << endl;
	printArray(mas, N);
	cout << endl;
	N = addTask(mas, N);
	/*cout << "Результат: " << endl;
	printArray(mas, N);
	deleteArray(mas, N);*/
	system("pause");
}