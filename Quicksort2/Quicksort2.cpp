#pragma once
#include "stdafx.h"
#include <iostream>
#include "sort.h"

using namespace std;

int main() {
	const long N = 15;
	long	low = 0,
			high = N - 1;
	int a[N];
	int g[N];

	for (int i = 0; i < N; i++) {
		a[i] = rand() % 1001;
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");

	sort sort;
	//sort.quick(a, low, high);		// Работаает
	//sort.shell(a, N);				// Работаает
	//sort.CountSort(a, N, 0, g);	// Работаает
	sort.RankSort(a, N, g);			// Работаает

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}cout << "\n";

	system("pause");
}