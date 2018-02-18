// Quicksort2.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <iostream>

#include "sort.h"

using namespace std;

int main() {
	const long N = 35;
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

	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	system("pause");
}