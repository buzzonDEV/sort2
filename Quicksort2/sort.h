#pragma once

class sort
{
public:
	sort(); //конструктор
	~sort(); //деструктор

	//хм... нужно сделать авто выбор сортировки
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
	void shell(int a[], const long N)
	{
		int d = 0;
		int i = 0;
		while (3 * d < N) {
			if (i % 2 == 0) {
				d = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
				void Swickk(int a[], int d);
			}
			else {
				d = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
				void Swickk(int a[], int d);
			}
			i++;
		}
	}
	void shaker()
	{
	}
	void index()
	{
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
	void Swickk(int a[], int d) {
		for (int i = d; i < d; i++) {
			int m = a[i];
			for (int j = i; j >= d; j -= d) {
				if (m < a[j - d])
					a[j] = a[j - d];
			}
		};
	}
};

sort::sort()
{
}

sort::~sort()
{
}
