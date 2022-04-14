/*
1. Định nghĩa một cấu trúc Sinh viên bao gồm các trường thông tin như sau: 
Mã Sinh viên (kiểu số nguyên), 
tên Sinh viên (kiểu chuỗi ký tự), 
lớp (kiểu chuỗi ký tự), 
điểm tổng kết (kiểu số thực),
hạnh kiểm (Tốt, khá, trung bình, yếu).
2. Cài đặt một cấu trúc danh sách liên kết đơn cho kiểu dữ liệu Sinh viên, với các thao tác: 
1) Khởi tạo danh sách; 
2) kiểm tra rỗng 
3) thêm phần tử vào cuối (hoặc đầu) danh sách 
4) Tìm kiếm phần tử trong danh sách; 
5) Xóa )phần tử cuối cùng khỏi danh sách; 
6) Duyệt danh sách; 
7) Sắp xếp danh sách
3. Chương trình chính: Sử dụng cấu trúc danh sách liên kết đơn và các thao tác ở trên để:
– Nhập vào một danh sách liên kết đơn gồm n Sinh viên (n bất kỳ).
– Hiển thị danh sách đã nhập ra màn hình.
-Liệt kê ra màn hình danh sách tất cả những Sinh viên thuộc lớp “D13CNPM”.
– Sắp sếp danh sách sinh viên theo mã sinh viên tăng dần
– Xóa phần tử cuối cùng khỏi danh sách.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <malloc.h>
using namespace std;
struct SinhVien
{
	int maSV;
	char tenSV;
	char lop;
	float diem;
	char hanhkiem[20];
};
typedef struct SinhVien SV;

struct node
{
	SV data;//dư liệu chứa trong 1 cái node,phụ thuộc yêu câu bài toán ở đây là số nguyên
	struct node* pNext;//con trỏ  dùng để liên kết giữa các node với nhau 
};
typedef struct node NODE; // thay thế ct con struct node bằng NODE
// khai báo cấu trúc của danh sách liên kết đơn 
struct list
{
	NODE* pHead;//node quản lí đầu danh sách
	NODE* pTail;//node quả lý cuối danh sách
};
typedef struct list LIST;// thay thế ct con list
///////////////////////////Khời tạo danh sách liên kết đơn các số nguyên///////////////////////////////
void khoitao(LIST& l)
{
	//cho 2 node  trỏ đến null vì danh sách lk đơn chưa có phần tử 
	l.pHead = NULL;
	l.pTail = NULL;
}
int kiemtrarong(LIST& l)
{
	if (l.pHead == 0)
	{
		return 1;
	}
	return 0;
}

//Hàm khởi tạo 1 cái node 
NODE* khoitaoNODE(SV x)// truyền dữ liệu x từ bên ngoài vào node 
{
	NODE* p = new NODE;// CẤP PHÁT VÙNG NHỚ node p
	if (p == NULL)
	{
		cout << "\n Không đủ bộ nhớ để cấp phát !";//ví dụ như ram 4gb mà cấp bộ nhớ bằng 4gb thì sẽ thông báo 
		return NULL;
	}
	p->data = x;       // truyền giá trị x vào data
	p->pNext = NULL;   // đầu tiền khai báo node khi node chưa liên kết đến node nào hếtthì sẽ trỏ đến NULL 
	return p;//trả về NODE p vừa khởi tạo 
}
// Hàm thêm NODE vào đầu danh sách liên kết

void themvaodau(LIST& l, NODE* p)//thêm vào trong dâu và để thay đổi nó 
{
	// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;//l cũng chính là nút cuối và là p luôn 
	}
	else
	{
		p->pNext = l.pHead;//cho con trỏ của node cần thâm là node p liên kết đến node node đầu-phead
		l.pHead = p;  //cập nhật lại phead chính là node p
	}
}
//Hàm thêm node p vào cuối ds liên kết đơn
void themvaocuoi(LIST& l, NODE* p)//thêm vào trong dâu và để thay đổi nó 
{
	// danh sách đang rỗng
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;//l cũng chính là nút cuối và là p luôn 
	}
	else
	{
		l.pTail->pNext = p;//cho con tror cuar ptail lieen keets vowis node p
		l.pTail = p;//caapj nhaatj p laf node cuoois laf ptail
	}
}
//Nhập vào danh sách
void nhapdanhsach(LIST& l, int n)
{
	cout << "NHAP VAO THONG TIN SINH VIEN\n";
	for (int i = 0; i < n; i++)
	{
		SV x;
		cout << "Nhap ma sinh vien: ";
		fflush(stdin);
		cin >> x.maSV;
		cout << "Nhap  ho ten sinh vien: ";
		fflush(stdin);
		cin >> x.tenSV;
		cout << "Nhap lop: ";
		fflush(stdin);
		cin >> x.lop;
		cout << "Nhap diem tong ket: ";
		fflush(stdin);
		cin >> x.diem;
		cout << "Nhap hanh kiem: ";
		fflush(stdin);
		cin >> x.hanhkiem;
		cout <<"\n \n ";
		NODE* p = new NODE;
		p = khoitaoNODE(x);
		themvaocuoi(l, p);
	}
}


//xuat danh sach lieen ket don
void xuatdanhsach(LIST l) //cos danh sachs roi ko can dau vaf de luu lai
{
	//for(int i=0;i<n;i++) tuwowng dduwowng
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)//duyet tu dau ds den cuoi ds trong lien ket don
	{
		cout <<  k->data.maSV, k->data.tenSV, k->data.lop, k->data.diem, k->data.hanhkiem;
	}
}
void SVD13CNPM(LIST l)
{
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->data.lop == 0)
		{
			cout <<  p->data.maSV, p->data.tenSV, p->data.lop, p->data.diem, p->data.hanhkiem;
		}
	}
}
void sapxep(LIST& l)
{
	NODE* p, * q;
	for (p = l.pHead; p != l.pTail; p = p->pNext)
	{
		for (q = p->pNext; q != NULL; q = q->pNext)
		{
			if (p->data.maSV > q->data.maSV)
			{
				SV x = p->data;
				p->data = q->data;
				q->data = x;
			}
		}
	}
	xuatdanhsach(l);
}
void xoacuoi(LIST& l)
{
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
		}
	}
	xuatdanhsach(l);
}

int main()
{
	LIST l;
	int n;
	cout << "NHAP VAO n:\n ";
	cin >> n;
	khoitao(l);
	nhapdanhsach(l, n);
	cout << "DANH SACH SINH VIEN\n: ";
	xuatdanhsach(l);
	cout << "DANH SACH SINH VIEN D13CNPM\n: ";
	SVD13CNPM(l);
	cout << "DANH SACH SINH VIEN SAP XEP THEO MAU\n: ";
	sapxep(l);
	cout << "DANH SACH SINH VIEN DA XOA PHAN TU CUOI \n: ";
	xoacuoi(l);

}

