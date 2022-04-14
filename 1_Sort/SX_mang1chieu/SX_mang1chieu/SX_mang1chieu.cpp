/*
Viết chương trình cài đặt 2 giải thuật tìm kiếm: tuyến tính và nhị phân (giả sử dãy số
đầu vào có thứ tự tăng dần).
Hướng dẫn: Xây dựng các hàm sau:
i) Tạo ngẫu nhiên mảng một chiều số nguyên có thứ tự tăng dần gồm N phần tử cho 
trước: void PhatSinhMangTang(int a[], int N)
ii) Xem mảng phát sinh: void XuatMang(int a[], int N)
iii) Tìm tuyến tính: int TimTuyenTinh(int a[], int N, int X)
iv) Tìm nhị phân: int TimNhiPhan(int a[], int N, int X)
v) Hàm chính (main()):
- Phát sinh mảng tăng a với kích thước N cho trước (không phải sắp xếp).
- Xuất mảng xem kết quả phát sinh.
- Nhập giá trị cần tìm x.
2
- Tìm x theo 2 phương pháp.
- In kết quả tìm: Nếu tìm thấy thì cho biết vị trí tìm thấy, ngược lại in kết quả
không tìm thấy cho từng phương pháp
*/
#include<string>
#include<iostream>
using namespace std;
#define MAX 100
// Mảng phát sinh tăng
int random(int min, int max)
{
	int a = min + rand() % (max - min + 1);
	return a;
}
void PhatSinhMang(int a[], int n)
{
	// khởi tảo tham số ngẫu nhiên
	srand(time(NULL));
	//khơi tạo ngẫu nhiên từng phần tử 
		for (int i = 0; i < n ; i++)
		{
			a[i] = random(1, 100);
		}
}
void NhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhập giá trị cho phần tử thứ a[" << i << "]";
		cin >> a[i];
	}
}
void XuatMang(int a[], int n)
{
	cout << "\nMảng sau khi được phát sinh: ";
	srand(time(NULL));
	for (int i = 0; i < n ; i++)
	{
		cout <<"\n DANH SACH MANG : " <<a[i];
	}
}
void hoanvi(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
// DAY TANG
void innterchangesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
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

int TimTuyenTinh(int a[], int n, int X)
{
	int i = 0;
	while (i < n && a[i] != X)
		i++;
	if (i < n)
		return i;// a[i] có phần tử là x
	return -1;//tìm hết mảng nhưng không có x
}
int SoSanhTimTuyenTinh(int a[], int n, int X, int& ss1)
{
	ss1 = 0;
	for (int i = 0; i < n; i++)
	{

		if (a[i] == X)
		{
			ss1++;
			return i;
		}
		ss1++;
	}
	return -1;
}
int TimNhiPhan(int a[], int n, int X)
{
	int left = 0, right = n-1, mid = 0;
	do 
	{
		mid = (right+left) / 2;
		if (a[mid] == X)
			return mid;
		else if (a[mid] < X)
			left = mid + 1;
		else
			right = mid - 1;
	} 
	while (left <= right);
	
}
//Tìm tuyến tính có chèn vào giá trị ss tính số lần so sánh với phần tử cần tìm:
int sosanhTimNhiPhan(int a[], int n, int X, int& ss)
{
	ss = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (a[i] == X)
		{
			ss++;
			return i;
		}
		ss++;
	}
	return -1;
}
// đẹ quy 
int binarySearch(int* a, int l, int r, int data) {
	int mid = l + (r - l) / 2;
	if (l > r) {
		return -1;
	}
	if (a[mid] == data) {
		return mid;
	}
	return (a[mid] > data) ? binarySearch(a, l, mid - 1, data) : binarySearch(a, mid + 1, r, data);
}

int main()
{
	int a[MAX], N;
	do
	{
		cout << "\n Nhập số phần tử :";
		cin >> N;
	}
	while (N<1 || N>MAX);


	PhatSinhMang(a, N);
	XuatMang(a, N);


	cout << " \n Mảng sắp xếp :";
	innterchangesort(a, N);
	XuatMang(a, N);
	int x;
	cout << "\n NHAP :";
	cin >> x;


	TimNhiPhan(a, N, x);
	cout << "\n VI TRI TIM KIEM NHI PHAN LA : " <<TimNhiPhan(a, N, x);
	
	TimTuyenTinh(a, N, x);
	cout<<"\n VI TRI TIM KIEM TUYEN TINH LA :";
	cout << TimTuyenTinh(a, N, x);
	
	
	int ss=0;
	if (x == -1)
	{
		cout << "\n KHONG TIM THAY ";
	}
	else
	{
		cout << "\n TIM THAY SO SANH NHI PHAN:" << sosanhTimNhiPhan(a, N, x, ss);
		cout <<"\n SO LAN SO SANH SO SANH NHI PHAN :" << ss;
	}


	int ss1 = 0;
	if (x == -1)
	{
		cout << "\n KHONG TIM THAY ";
	}
	else
	{
		cout << "\n TIM THAY SO SANH TUYEN TINH:" << SoSanhTimTuyenTinh(a, N, x, ss1);
		cout << "\n SO LAN SO SANH SO SANH TUYEN TINH :" << ss1;
	}

	
	return 0;
}