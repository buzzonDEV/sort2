#pragma once

class sort
{
public:
	sort(); //�����������
	~sort(); //����������

	//��... ����� ������� ���� ����� ����������
	void quick(int a[], long lb, long hb, bool more_memory = false)
	{
		if (lb < hb) {
			long p = GetPiv(a, lb, hb);
			if (more_memory)
			{
				//���������
				this->quick(a, lb, p, more_memory);
				this->quick(a, p + 1, hb, more_memory);
			}
			else
			{
				//������

			}
		}
	}
	void shell()
	{
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
};

sort::sort()
{
}

sort::~sort()
{
}
