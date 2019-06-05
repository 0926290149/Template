#include<iostream>
using namespace std;

template<typename T>
void InsertionSort(T list[], int size) 
{
	for (int i = 1; i < size; i++)
	{
		T currentElemenst = list[i];
		int k;
		for (k = i - 1; k >= 0 && list[k] > currentElemenst; k--)
		{
			list[k + 1] = list[k];
		}
		list[k + 1] = currentElemenst;
	}
}

template<typename T>
int BinarySearch(const T list[], T key, int size)
{
	int low = 0;
	int high = size - 1;
	while (high >= low)
	{
		int mid = (low + high) / 2;
		if (key < list[mid])
			high = mid - 1;
		else if (key == list[mid])
			return mid;
		else
			low = mid + 1;
	}
	return - 1;
}

template<typename T>
void print(const T list[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		cout << list[i] << ",";
	}
	cout << list[size - 1] << endl;
}

int main()
{
	int list[] = { 1,5,6,2,3,7,9,8,4 };
	int a, b, c;
	double d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	cout << "From: ";
	print(list, 9);
	InsertionSort(list, 9);
	cout << "To: ";
	print(list, 9);
	cout << a << " at " << BinarySearch(list, a, 9) << endl;
	cout << b << " at " << BinarySearch(list, b, 9) << endl;
	cout << c << " at " << BinarySearch(list, c, 9) << endl;
	double list2[] = { 1.1,5.5,6.6,2.2,3.3,7.7,9.9,8.8,4.4 };
	cout << endl;
	cout << "From: ";
	print(list2, 9);
	InsertionSort(list2, 9);
	cout << "To: ";
	print(list2, 9);
	cout << d << " at " << BinarySearch(list2, d, 9) << endl;
	cout << e << " at " << BinarySearch(list2, e, 9) << endl;
	cout << f << " at " << BinarySearch(list2, f, 9) << endl;
	system("pause");
	return 0;
}
