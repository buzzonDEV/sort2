#pragma once

class sort
{
public:
	sort(); //êîíñòðóêòîð
	~sort(); //äåñòðóêòîð

	//õì... íóæíî ñäåëàòü àâòî âûáîð ñîðòèðîâêè
	void quick(int a[], long lb, long hb) //áûñòðàÿ ñîðòèðîâêà
	{
		if (lb < hb) {
			long p = GetPiv(a, lb, hb); // ïîëó÷åíèå îïîðíîé òî÷êè ïî ðàçáèåíèþ Õîàðàaaa
			//ðåêóðñèÿ
			this->quick(a, lb, p); 
			this->quick(a, p + 1, hb); 
		}
	}
	void shell(int a[], const long N)
	{
		int i, j, d;
		for(d=N/2;d>0;d/=2){ //d - äëèíà øàãà
			//ñîðòèðóþòñÿ ýëåìåíòû âûáîðêè
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
		//long N1 = N;
		//int d = 0, x = 0;
		//while (N1 > 0) {
		//	Swickk(a, N1, &d, &x);
		//	for (int i = d; i < N1; i++) {
		//		int m = a[i];
		//		for (int j = i; j >= d; j -= d) {
		//			if (m < a[j - d])
		//				a[j] = a[j - d];
		//			else break;
		//		}
		//		N1 -= (d - x) * 3êååååíã;
		//	}
		//}
	}
	void RankSort()
	{
	}
	void index()
	{
	}

private:
	int GetPiv(int a[], long lb, long hb) {
		int pivot = a[lb]; //ñíà÷àëà çà îïîðíóþ òî÷êó ñ÷èòàåòñÿ ïåðâûé ýëåìåíò ìàññèâà
		int i = lb - 1, j = hb + 1;
		//äâà èíäåêñà (â íà÷àëå è â êîíöå) ñáëèæàþòñÿ, ïîêà íå íàéäåòñÿ ïàðà
		//â êîòîðîé îäèí ýëåìåíò ñëåâà è áîëüøå îïîðíîãî, à âòîðîé - ìåíüøå è ñïðàâà
		//ýëåìåíòû ýòîé ïàðû ìåíÿþòñÿ ìåñòàìè
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
	//void Swickk(int a[], const long N, int *d, int *x) {
	//	int i = 0;
	//	while ((*d) * 3 < N) {
	//		(*d) = StCount((*d), i);
	//		i++;
	//	}
	//	(*d) = StCount((*x), i--);
	//	//std::cout << d;
	//	//system("pause");
	//	(*x) = StCount((*x), i -= 2);
	//	//std::cout << x;
	//	//system("pause");
	//}
	//int StCount(int d, int i) {
	//	if (i % 2 == 0) {
	//		d = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
	//	}
	//	else {
	//		d = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
	//	}
	//	return d;
	//}
};

	sort::sort()
	{
	}

	sort::~sort()
	{
	}

