
#include <iostream>
using namespace std;
void nhapmang(int a[], int n)
{
	cout << "Nhập các phần tử trong mảng";
	for (int i = 0; i < n; i++)
	{
		cout<<"Nhập giá trị cho phần tử a[" <<i<<"]";
		cin >> a[i];

	}
}
void xuatmang(int a[], int n)
{
	cout << "Mảng được sắp xếp \n";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ";";
	}
}
void hoanvi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void interchangeort( int a[],int n)
{
	for (int i = 1; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				hoanvi(a[i], a[j]);
			}
		}
	}
}
void main()
{
	int *a;
	int n;
	cout << "nhập vào số phần tử n=";
	cin >> n;
	a = new int[n];
	nhapmang(a, n);
	cout << "Mảng sau khi nhập \n";
	xuatmang(a, n);
	cout << "mảng sau khi sắp xếp \n";
	interchangeort(a,n);
}



