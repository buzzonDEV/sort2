#ifndef __SORT_H__
#define __SORT_H__

class sort
{
public:
	void Quick(int a[], long lb, long hb); // Быстрая
	void Shell(int a[], const long N); // Шелла
	void CountSort(int a[], int N, int rank); // Подсчетом
	void RankSort(int a[], int N); // Поразрядная

private:
	int GetPiv(int a[], long lb, long hb);
	int MaxElem(int a[], int N);  //поиск максимального элемента массива
	int MaxRank(int num);  //поиск максимального разряда
};

#endif //__SORT_H__

//	
//
//	void Fibon(int a[], int N) {
//		for (int i = 1; i < N; i++)
//			a[i] += a[i - 1];
//	}
