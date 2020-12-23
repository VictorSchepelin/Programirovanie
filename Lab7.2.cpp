#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale>
#include <iostream>;
using namespace std;

int sum(int k, ...)
{
	int* p = &k;
	int s = 0;
	int p1, p2;
	for (; k != 0; k = k - 2)
	{
		p1 = *(++p);
		p2 = *(++p);
		s += p1 * p2;
	}
	return s;
}

void main()
{
	setlocale(LC_ALL, "russian");
	cout << "Сумма(8, 1, 2, 3, 4, 5, 6, 7, 8) = " << sum(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;
	cout << "\nСумма(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) = " << sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
	cout << "\nСумма(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) = " << sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
	system("pause");
}