// Quicksort2.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <iostream>

using namespace std;

class sort
{
public:
	sort(); //конструктор
	~sort(); //деструктор

	void quick(int a[], long lb, long hb, bool more_memory = false)
	{
		if (lb < hb) {
			long p = GetPiv(a, lb, hb);
			if (more_memory)
			{
				//рекурсией
				this->quick(a, lb, p, more_memory);
				this->quick(a, p + 1, hb, more_memory);
			}
			else
			{
				//циклом
			}
		}
	}

private:
	int GetPiv(int a[], long lb, long hb) {
		int pivot = a[lb];
		int i = lb - 1, j = hb + 1;
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
};

sort::sort()
{
}

sort::~sort()
{
}

int main() {
	const long N=10;
	long	low = 0,
			high = N - 1;
	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 10 + 1;
		cout << a[i] << " ";
	}
	system("pause");
	cout << endl;

	sort sort;
	sort.quick(a, low, high, true);

	for (int i =0; i<N;i++)
		cout << a[i] << " ";
	system("pause");
}