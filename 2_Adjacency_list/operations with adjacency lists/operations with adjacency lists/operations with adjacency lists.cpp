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
void chencuoi(DSKe& ds, int x)
{
    // nếu đầy thì không được chèn 
    if (KiemTraDay(ds) == 1)
    {
        return ;
    }
    // truy cap vao phan tu cuoi cung cua danh sach và chèn X vao
    ds.A[ds.n] = x;
    //tang phan tu trong danh sach len
    ds.n += 1;
}
void duyet(DSKe ds)
{
    // duyet pha tu dau tien
    int p = 0;
    //chưa đến địa chỉ cuối cùng trong danh sach thì tiêóp tục duyệt 
    while (p<ds.n)
    {
        //xư lý các phần tử được xét
        cout << ds.A[p];
        //tang phantu tiep theo trong danh sach
        p++;
    }
}
void timkiem(DSKe ds, int x)
{
    // khia báo vị trí p ban đầu 
    int p = 0;
    int d = 0;// khai bao biến đếm
    int B[10];// khai báo manghr chưa địa chỉ tìm thấy
    // duỵet qua danh sách
    while (p < ds.n)
    {
        //neu có phần tư trong mảng =x
        if ( ds.A[p]==x)
        {
            // thêm vị trí p vào mảng chứa địa chỉ tìm thấy
            B[d] = p;
            // tăng biến đếm lên 1 đơn vị
            d++;
        }
        p += 1;
    }
    // nếu biến đếm lớn hơn 0
    if (d > 0)
    {
        // hiển thị các phần tử được lưu trong mảng 
        cout << "\n Các vị trí tìm thấy : ";
        //duyệt mảng B
        for (int i = 0; i < d; i++)
        {
            cout << B[i] << endl;
        }
    }
    else
    {
        cout << "Không có phần tử được tìm thấy! \n";
    }
      
}

int main()
{
    // KHAI BIEN DS CÓ Kieu dulieu DSKE
    DSKe ds;
    khoitao(ds);
    // nhập số lượng n phần tử của danh sách cần chèn 
    int n;
    cout<<" Nhập vào N: ";
    cin >> n;
    // nhập giá trị từng phần tử X
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhập phần tử thứ [%d] trong danh sách :" ;
        cin >> x;
        chencuoi(ds, x);
    }
    // gọi hàm duyệt danh sách
    cout << "\n DANH SACH BAN DAU : ";
    duyet(ds);
    int x;
    // nhập giá trị cần tìm trong danh sách
    cout << "\n Nhập giá trị cần tìm kiếm : ";
    cin >> x;
    //gọi hàm cần tìm kiếm 
    timkiem(ds, x);

}

