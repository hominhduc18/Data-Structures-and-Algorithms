/*
1. Định nghĩa một cấu trúc Sinh viên bao gồm các trường thông tin như sau : Mã Sinh viên(kiểu số nguyên), tên Sinh viên(kiểu chuỗi ký tự), lớp(kiểu chuỗi ký tự), điểm tổng kết(kiểu số thực), hạnh kiểm(Tốt, khá, trung bình, yếu).
2. Cài đặt một cấu trúc danh sách kề cho kiểu dữ liệu Sinh viên, với các thao tác : 
1) Khởi tạo danh sách; 
2) kiểm tra rỗng, kiểm tra đầy 
3) thêm phần tử 
4) Tìm kiếm phần tử trong danh sách;
5) Xóa phần tử cuối cùng khỏi danh sách;
6) Duyệt danh sách.
3. Chương trình chính : Sử dụng cấu trúc danh sách kề và các thao tác ở trên để :
– Nhập vào một danh sách liên kết kề gồm n Sinh viên(n bất kỳ).
– Hiển thị danh sách đã nhập ra màn hình.
- Liệt kê ra màn hình danh sách tất cả những Sinh viên thuộc lớp “D13CNPM”.
– Xóa phần tử cuối cùng khỏi danh sách.
Hiển thị lại danh sách sau khi xóa ra màn hình */
#include <iostream>
#include <malloc.h>
#include <string.h>
using namespace std;
#define MAX 100
struct  SinhVien
{
    int maSV;
    char tenSV;
    char lop;
    float diem;
    char hk[15];
};
// dinh nghia so luong phan tu cua mang co the luu tru
typedef struct DSKe
{
   SinhVien A[MAX];// mang A voi kich thuoc max=100
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
void nhapds(DSKe& ds)
{
    cout << "Nhập số sinh viên: ";
    cin >> ds.n;
    for (int i = 0; i < ds.n; i++)
    {
        cout << "Nhập mã sinh viên ";
        fflush(stdin);
        cin >> ds.A[i].maSV;
        cout << "Nhập tên sinh viên: ";
        fflush(stdin);
        cin >> ds.A[i].tenSV;
        cout << "Nhập vào lớp của sinh viên: ";
        fflush(stdin);
        cin >> ds.A[i].lop;
        cout << "Nhập vào điểm của sinh viên: ";
        fflush(stdin);
        cin >> ds.A[i].diem;
        cout << "Nhập vào hạnh kiểm của sinh viên: ";
        fflush(stdin);
        cin >> ds.A[i].hk;
        cout << "\n \n ";
    }
}
void duyet(DSKe ds)
{
    cout << "%-20s %-20s %-15s %-20s %-15s\n", "Ma sinh vien", "Ho ten ", "Lop", "Diem tong ket", "Hanh kiem";
    for (int i = 0; i < ds.n; i++)
        cout << "%-20s %-20s %-15s %-20s %-15s\n", ds.A[i].maSV, ds.A[i].tenSV, ds.A[i].lop, ds.A[i].diem, ds.A[i].hk;
}
void timkiem(DSKe ds)
{
    // khia báo vị trí p ban đầu 
    int p = 0;
    int d = 0;// khai bao biến đếm
    int B[10];// khai báo mangh chưa địa chỉ tìm thấy
    // duỵet qua danh sách
    while (p < ds.n)
    {
        //neu có phần tư trong mảng =x
        if (ds.A[p].lop == 0)
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
        cout << "\n DANH SACH SINH VIEN LOP DD13CNPM\n";
        cout << "%-20s %-20s %-15s %-20s %-15s\n", "Ma sinh vien", "Ho ten ", "Lop", "Diem tong ket", "Hanh kiem";
        //duyệt mảng B
        for (int i = 0; i < d; i++)
        {
            cout << "%-20s %-20s %-15s %-20s %-15s\n", ds.A[B[i]].maSV, ds.A[B[i]].tenSV, ds.A[B[i]].lop, ds.A[B[i]].diem, ds.A[B[i]].hk;
        }
    }
    else
    {
        cout << "Không có phần tử được tìm thấy! \n";
    }

}
void xoaPhanTuCuoi(DSKe& ds)
{
    //dịch chuyển 
    for (int i = ds.n - 1; i < ds.n - 1; i++)
        ds.A[i] = ds.A[i + 1];
    ds.n = ds.n - 1;
}

int main()
{
    // KHAI BIEN DS CÓ Kieu dulieu DSKE
    DSKe ds;
    khoitao(ds);
    nhapds(ds);
    cout << "\n DANH SACH SINH VIÊN\n:";
    duyet(ds);
    timkiem(ds);
    xoaPhanTuCuoi(ds);
    cout << "\n DANH SACH SAU KHI XOA PHAN TU CUOI\n";
    duyet(ds);
}

