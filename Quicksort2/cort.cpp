#include "stdafx.h"
#include "sort.h"
#include <iostream>
#include <cmath>

using namespace std;

// Быстрая
void sort::Quick(int a[], long lb, long hb)
{
	if (lb < hb)
	{
		long p = GetPiv(a, lb, hb); // получение опорной точки по разбиению Хоара
		//рекурсия
		Quick(a, lb, p);
		Quick(a, p + 1, hb);
	}
};

// Шелла
void sort::Shell(int a[], const long N)
{
	int i, j, d;
	for (d = N / 2; d > 0; d /= 2) { //d - длина шага
		//сортируются элементы выборки
		for (i = d; i < N; i++) {
			int c = a[i];
			for (j = i; j >= d; j -= d) {
				if (c < a[j - d])
					a[j] = a[j - d];
				else break;
			}
			a[j] = c;
		}
	}
};

// Подсчетом
void sort::CountSort(int a[], int N, int rank, int g[])
{
	
	int b[10];// Вспомогательный массив 0-9
	for (int i = 0; i < 10; i++) // Зануляем массив
		b[i] = 0;

	for (int i = 0; i < N; i++) // Считаем количество элементов n-го разряда
		b[(a[i] / (int)(pow(10, rank))) % 10]++;

	for (int i = 0; i < 9; i++) // Пересчет массива
		b[i + 1] += b[i];

	for (int m = N-1; m >= 0; m--) 
	{
		int num = (a[m] / (int)(pow(10, rank))) % 10; // сортируемый ранг
		g[--b[num]] = a[m];
	}
};

// Поразрядная
void sort::RankSort(int a[], int N, int g[])
{
	int max = MaxElem(a, N); //ищем максимальный элемент массива
	int mrank = MaxRank(max); //ищем максимальный разряд
	for (int i = 0; i < mrank; i++) {
		CountSort(a, N, i, g);
		for (int i = 0; i < N; i++)
		{
			a[i] = g[i];
		}
	}
};

int sort::GetPiv(int a[], long lb, long hb) {
	int pivot = a[lb]; //сначала за опорную точку считается первый элемент массива
	int i = lb - 1, j = hb + 1;
	//два индекса (в начале и в конце) сближаются, пока не найдется пара
	//в которой один элемент слева и больше опорного, а второй - меньше и справа
	//элементы этой пары меняются местами
	while (1) {
		do {
			i++;
		} while (a[i] < pivot);

		do {
			j--;
		} while (a[j] > pivot);

		if (i >= j)
			return j;
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
	}
}

//поиск максимального элемента массива
int sort::MaxElem(int a[], int N)
{
	int max;
	for (int i = 1; i < N; i++) {
		if (a[i] >= a[i - 1])
			max = a[i];
	}
	return max;
};

//поиск максимального разряда
int sort::MaxRank(int num)
{
	int rank = 0; //разряд 
	while (num != 0) {
		num /= 10;
		rank++;
	}
	return rank;
};