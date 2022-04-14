#include <iostream>
using namespace std;
#define MAX 100
int Random(int min, int max)
{
    int a = min + rand() % (max - min + 1);
    return a;
}
int TimTuyenTinh(int a[],int n,int x,int *SLSS)
{
    *SLSS = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            (* SLSS) += 1;
            return i;
        }
        else
        {
            (* SLSS) += 1;
        }
    }
    return -1;
}
int KiemTraGiam(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
            return 0;
    }
    return 1;
}
void PhatSinhMang(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = Random(1, 100);
    }
    // sapXepmang
}
void nhapmang(int a[], int n) 
{
    cout << "nhập các phần tử trong mảng";
    for (int i = 0; i < n; i++)
    {
        cout << "nhập giá trị cho phần tử thứ a[" << i << "]";
        cin >> a[i];
    }
}
void xuatmang(int a[], int n)
{
    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}
void hoanvi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
void copyMang(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}
void sapXepMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] > a[j])
            {
                hoanvi(a[i], a[j]);
            }
        }
    }
}
void selectionsort(int a[], int n, int* SLSS, int* SLgan)// chọn trực tiếp 
{
    int min;
    *SLSS = 0;
    *SLgan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                (*SLgan)++;
                (*SLSS)++;
                min = j;
            }
        }
        hoanvi(a[min], a[i]);
        (*SLSS)++;
    }
}
void insertionsort(int a[], int n, int* SLSS, int* SLgan)// chèn trực tiếp 
{
    int pos, i;
    int x;
    *SLSS = 0;
    *SLgan = 0;
    for (i = 1; i < n; i++)
    {
        x = a[i]; pos = i - 1;
        (*SLgan)++;
        while ((pos >= 0) && (a[pos] > x)) 
        {
            (*SLSS)++;
            (*SLgan)++;
            a[pos + 1] = a[pos];
            pos--; 
        }
        a[pos + 1] = x;
        (*SLgan)++;
        (*SLSS)++;
    }
}
void innterchangesort(int a[], int n,int *SLSS,int *SLgan)// đổi chổ trực tiếp 
{
    *SLSS = 0;
    *SLgan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                (* SLgan)++;
                (* SLSS)++;
                hoanvi(a[i], a[j]);
            }
            else
            {
               (* SLSS)++;
               
            }
        }
    }
}
void bubblesort(int a[], int n, int* SLSS, int* SLgan)// nổi bọt
{
    *SLSS = 0;
    *SLgan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            (*SLSS)++;
            if (a[j] < a[j - 1])
            {
                hoanvi(a[j], a[j - 1]);
                (*SLgan)++;
                
            }
        }
    }
}
void quicksort(int a[], int left, int right, int* SLSS, int* SLgan)
{
    int i, j, x;
    *SLSS = 0;
    *SLgan = 0;
    int k = a[(left + right) / 2]; /// chonj x pivot
    i = left;
    j = right; (*SLgan)++;
    do
    {
        while (a[i] < k)
        {
            i++;
            (*SLSS)++;
            (*SLgan)++;
        }
        while (a[j] > k)
        {
            j--;
            (*SLSS)++;
            (*SLgan)++;
        }
        if (i <= j)
        {
            hoanvi(a[i], a[j]);
            i++;
            j--;
            (*SLgan)++;
            (*SLSS)++;
        }

    } 
    while (i <= j);
    (*SLSS)--;
    if (left < j)
        quicksort(a, left, j, SLSS, SLgan);
       
    if (i < right)
        quicksort(a, i, right, SLSS, SLgan);
    
}
int main()
{
    int a[MAX], n, x, SLSS, SLgan, b[MAX];
    do
    {
        cout << "NHAP SO PHAN TU  n = ";
        cin >> n;
    } 

    // TH PHAT SIN MANG NGAU NHIEN
    while (n<1 || n>MAX);
    PhatSinhMang(a, n);
    copyMang(a, b, n);
    cout << "\nMANG SAU KHI DUOC PHAT SINH LA:\n ";
    xuatmang(a, n);
    cout << "\n TRUONG HOP MANG PHAT SINH NGAU NHIEN :\n";
    xuatmang(a, n);
   quicksort(a,0,n-1, & SLSS, & SLgan);
    cout << "\nSO LAN SO SANH:\n"<<SLSS;
    cout << "\nSO PHEP GAN LA:\n"<<SLgan;
   

    // TH XAU NHAT MANG XAU NHAT 
    cout << "\n TRUONG HOP XAU NHAT:\n";
    sapXepMang(b, n);
    xuatmang(b, n);
    quicksort (b,0, n-1, &SLSS, &SLgan);
    cout << "\nSO LAN SO SANH:\n" << SLSS;
    cout << "\nSO PHEP GAN LA:\n" << SLgan;


    // TH PHAT SINH MANG TOT NHAT 
    cout << "\n TRUONG HOP PHAT TOT NHAT:\n";
    xuatmang(a, n);
    quicksort(a, 0,n-1, & SLSS, & SLgan);
    cout << "\nSO LAN SO SANH:\n" << SLSS;
    cout << "\nSO PHEP GAN LA:\n" << SLgan;
    
    
   
  
}



