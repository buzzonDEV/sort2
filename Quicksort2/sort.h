#ifndef __SORT_H__
#define __SORT_H__

class sort
{
public:
	void Quick(int a[], long lb, long hb); // Быстрая
	void Shell(int a[], const long N); // Шелла
	void CountSort(int a[], int N, int rank, int g[]); // Подсчетом
	void RankSort(int a[], int N, int g[]); // Поразрядная

private:
	int GetPiv(int a[], long lb, long hb);
	int MaxElem(int a[], int N);  //поиск максимального элемента массива
	int MaxRank(int num);  //поиск максимального разряда
};

#endif //__SORT_H__