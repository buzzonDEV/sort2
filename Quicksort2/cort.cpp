#include "stdafx.h"
#include "sort.h"

// Ѕыстра€
void sort::Quick(int a[], long lb, long hb)
{
	if (lb < hb)
	{
		long p = GetPiv(a, lb, hb); // получение опорной точки по разбиению ’оара
		//рекурси€
		quick(a, lb, p);
		quick(a, p + 1, hb);
	}
};

// Ўелла
void sort::Shell(int a[], const long N)
{
	int i, j, d;
	for (d = N / 2; d > 0; d /= 2) { //d - длина шага
		//сортируютс€ элементы выборки
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

// ѕодсчетом
void sort::CountSort(int a[], int N, int rank)
{
	//	void CountSort(int a[],int N, int rank) {  //сортировка подсчетом
	//		int b[10];//вспомогательный массив
	//
	//
	//		for (int j = 0; j < 10; j++) //занул€ем массив
	//			b[j] = 0;
	//
	//		for (int i = 0; i < N; i++) {//считаем количество элементов n-го разр€да
	//				b[(a[i] / (int)(pow(10,rank))) % 10]++;
	//		}
	//
	//		Fibon(b, 10); //
	//
	//		for (int k = 0; k < 10; ++k) {
	//			std::cout << b[k] << "  ";
	//			}
	//
	//		for (int j = 0; j < N; j++) {
	//			int r = a[j] / (int)(pow(10, rank)) % 10; // значение rank ранга j-го элемента массива
	//			if (b[r] - b[r - 1] == 0) {
	//				std::swap(a[j], a[b[r]]);
	//				b[r]--;
	//			}
	//			else j++;
	//		}
	//		std::cout << "\n";
	//		for (int i = 0; i < N; i++)
	//			std::cout << a[i] << " ";
	//		//std::cout << "\n";
	//		//for (int k = 0; k < desyat; ++k) {
	//		//	std::cout << b[k] << " ";
	//		//}
	//
	//	}
};

// ѕоразр€дна€
void sort::RankSort(int a[], int N)
{
	int max = MaxElem(a, N); //ищем максимальный элемент массива
	int mrank = MaxRank(max); //ищем максимальный разр€д
	for (int i = 0; i < mrank; i++) {
		CountSort(a, N, mrank);
	}
};



int sort::GetPiv(int a[], long lb, long hb) {
	int pivot = a[lb]; //сначала за опорную точку считаетс€ первый элемент массива
	int i = lb - 1, j = hb + 1;
	//два индекса (в начале и в конце) сближаютс€, пока не найдетс€ пара
	//в которой один элемент слева и больше опорного, а второй - меньше и справа
	//элементы этой пары мен€ютс€ местами
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

//поиск максимального разр€да
int sort::MaxRank(int num)
{
	int rank = 0; //разр€д 
	while (num != 0) {
		num /= 10;
		rank++;
	}
	return rank;
};