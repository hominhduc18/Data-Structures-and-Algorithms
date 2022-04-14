#include <iostream>
using namespace std;
#define MAX 100
// dinh nghia so luong phan tu cua mang co the luu tru
typedef struct DSKe
{
    int A[MAX];// mang A voi kich thuoc max=100
    int n;
}DSKe;
// ham khoi tao
void khoitao(DSKe& ds)
{
    // ban đầu danh sách rông
    ds.n = 0;
}
int kiemtrarong(DSKe ds)//ktra rong
{
    if (ds.n == 0)// nêu ds =0 thi rong
    {
        return 1;
    }
    return 0;
}
//kiem tra day 
int KiemTraDay(DSKe ds)
{
    if (ds.n == MAX)
    {
        return 1;
    }
    return 0;
}

int main()
{
   // KHAI BIEN DS CÓ Kieu dulieu DSKE
    DSKe ds;
    khoitao(ds);
}

