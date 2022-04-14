
#include <iostream>
using namespace std;
void nhapmang(int a[], int n)
{
    cout << "Nhập vào các phần tử trong mảng: ";
    for (int i = 0; i <= n-1; i++)
    {
        cout << "Nhập vào giá trị các phần thứ a[" << i << "]";
        cin >> a[i];
    }
}
void xuatmang(int a[], int n)
{
    cout << "Mảng được nhập vào là: \n";
    for (int i = 0; i <= n-1; i++)
    {
        cout << a[i] << ";";
    }
}
void hoanvi(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}
void quicksort(int a[], int L, int R)
{
    int k = a[(L + R) / 2];
    int i = L;
    int j = R;
    do
    {
        while (a[i] < k)
        {
            i++;
        }
        while (a[j] > k)
        {
            j--;
        }
        if (i <= j)
        {
            hoanvi(a[i], a[j]);
            i++;
            j--;
        }

    }    while (i < j);
        if (L < j)
            quicksort(a, L, j);
        if (i < R)
            quicksort(a, i, R);

    }
int  main()
{
    int* a;
    int n;
    cout << "Nhap vao so phan tu n= ";
    cin >> n;
    a = new int [n];
    nhapmang(a, n);
    xuatmang(a, n);
    cout << "Mảng được sắp xếp là: \n";
    cout << "\n";
    quicksort(a,0, n-1);
    xuatmang(a, n);
}

