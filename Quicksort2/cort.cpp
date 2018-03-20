#include "stdafx.h"
#include "sort.h"

// �������
void sort::Quick(int a[], long lb, long hb)
{
	if (lb < hb)
	{
		long p = GetPiv(a, lb, hb); // ��������� ������� ����� �� ��������� �����
		//��������
		quick(a, lb, p);
		quick(a, p + 1, hb);
	}
};

// �����
void sort::Shell(int a[], const long N)
{
	int i, j, d;
	for (d = N / 2; d > 0; d /= 2) { //d - ����� ����
		//����������� �������� �������
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

// ���������
void sort::CountSort(int a[], int N, int rank)
{
	//	void CountSort(int a[],int N, int rank) {  //���������� ���������
	//		int b[10];//��������������� ������
	//
	//
	//		for (int j = 0; j < 10; j++) //�������� ������
	//			b[j] = 0;
	//
	//		for (int i = 0; i < N; i++) {//������� ���������� ��������� n-�� �������
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
	//			int r = a[j] / (int)(pow(10, rank)) % 10; // �������� rank ����� j-�� �������� �������
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

// �����������
void sort::RankSort(int a[], int N)
{
	int max = MaxElem(a, N); //���� ������������ ������� �������
	int mrank = MaxRank(max); //���� ������������ ������
	for (int i = 0; i < mrank; i++) {
		CountSort(a, N, mrank);
	}
};



int sort::GetPiv(int a[], long lb, long hb) {
	int pivot = a[lb]; //������� �� ������� ����� ��������� ������ ������� �������
	int i = lb - 1, j = hb + 1;
	//��� ������� (� ������ � � �����) ����������, ���� �� �������� ����
	//� ������� ���� ������� ����� � ������ ��������, � ������ - ������ � ������
	//�������� ���� ���� �������� �������
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

//����� ������������� �������� �������
int sort::MaxElem(int a[], int N)
{
	int max;
	for (int i = 1; i < N; i++) {
		if (a[i] >= a[i - 1])
			max = a[i];
	}
	return max;
};

//����� ������������� �������
int sort::MaxRank(int num)
{
	int rank = 0; //������ 
	while (num != 0) {
		num /= 10;
		rank++;
	}
	return rank;
};