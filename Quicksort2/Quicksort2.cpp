// Quicksort2.cpp : Defines the entry point for the console application.
//
#pragma once

#include "stdafx.h"
#include <iostream>

template <typename T>
void printArray(T arr)
{
	cout << arr << "  \n\n";
}



using namespace std;

void quicksort(int a[], long lb, long hb);
int GetPiv(int a[], long lb, long hb);

int main() {
	const long N=10;
	int a[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 9 + 1;
		cout << a[i] << " ";
	}
	system("pause");
	cout << endl;


	float f = 1;
	printArray(f);

	long low = 0;
	long high = N - 1;

	quicksort(a, low, high);

	for (int i =0; i<N;i++)
		cout << a[i] << " ";
	system("pause");
}

void quicksort(int a[], long lb, long hb) {
	if (lb < hb) {
		long p = GetPiv(a, lb, hb);
		quicksort(a, lb, p);
		quicksort(a, p + 1, hb);
	}

}

int GetPiv(int a[], long lb, long hb) {
	int i = lb-1, j = hb+1;
	int pivot = a[lb];
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
//11