#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
struct node
{
	int data;//dư liệu chứa trong 1 cái node,phụ thuộc yêu câu bài toán ở đây là số nguyên
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
//Hàm khởi tạo 1 cái node 
NODE* khoitaoNODE(int x)// truyền dữ liệu x từ bên ngoài vào node 
{
	NODE* p = new NODE;// CẤP PHÁT VÙNG NHỚ node p
	if (p == NULL)
	{
		cout<< "\n Không đủ bộ nhớ để cấp phát !";//ví dụ như ram 4gb mà cấp bộ nhớ bằng 4gb thì sẽ thông báo 
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

//xuat danh sach lieen ket don
void xuatdanhsach(LIST l) //cos danh sachs roi ko can dau vaf de luu lai
{
	//for(int i=0;i<n;i++) tuwowng dduwowng
	for (NODE* k = l.pHead; k != NULL; k = k->pNext)//duyet tu dau ds den cuoi ds trong lien ket don
	{
		cout << k->data << " ";
	}
}
void xuatchan(LIST l)
{
	NODE* p = l.pHead;
	while (p)
	{
		if ((p->data) % 2 == 0 && p->data !=0)
		{
			cout << p->data;
		}
		p = p->pNext;
	}
}
int TimMax(LIST l)
{
	NODE* p = l.pHead;
	int max;
	max = l.pHead->data;
	while (p!=NULL)
	{
		if (max < p->data)
		{
			max = p->data;
		}
		p = p->pNext;
	}
	return max;
}

bool LASNT(int x)
{
	if (x < 2)
		return 0;
	for (int i = 2; i <= sqrt((float)x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int demSNT(LIST l)
{
	int dem=0;
	NODE* p = l.pHead;
	while (p)
	{
		if (LASNT(p->data))
		{
			dem++;
		}
		p = p->pNext;
	}
	return dem;
}
NODE* TimChanDau(LIST* l)
{
	NODE* p = l->pHead;
	while (p)
	{
		if (p->data % 2 == 0 && p->data !=0) {
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}
void ThemkTruocp(LIST* l, NODE* p, NODE* k) {
	NODE* temp = l->pHead;
	NODE* temp2 = l->pHead->pNext;
	if (p == NULL) 
	{
		return;
	}
	if (temp == p)
	{
		themvaodau(*l, k);
	}
	else {
		while (temp2 != p) {
			temp = temp->pNext;
			temp2 = temp2->pNext;
		}
		temp->pNext = k;
		k->pNext = p;
	}
}
void themXTruocChanDau(LIST* l, int x) {
	NODE* p = khoitaoNODE(x);
	NODE* temp = TimChanDau(l);
	if (temp == NULL) 
	{
		themvaodau(*l, p);
	}
	else
	{
		ThemkTruocp(l, temp, p);
	}
}
NODE* TimLeCuoi(LIST* l)
{
	NODE* p = l->pHead;
	while (p)
	{
		if (p->data % 2 != 0 ) {
			return p;
		}
		p = p->pNext;
	}
	return NULL;
}

void ThemkSaup(LIST* l, NODE* p, NODE* k) {
	NODE* temp = l->pHead;
	if (p == NULL)
	{
		return;
	}
	if (p == l->pTail)
	{
		themvaocuoi(*l, k);
	}
	else {
		while (temp == p->pNext) {
			p->pNext = k;
			k->pNext = temp;
			if (temp == l->pTail)
			{
				temp->pNext = NULL;
			}
			return;
		}
		temp = temp->pNext;
	}
}
void themXSauLeCuoi(LIST* l, int x) {
	NODE* p = khoitaoNODE(x);
	NODE* temp = TimLeCuoi(l);
	if (temp == NULL)
	{
		themvaocuoi(*l, p);
	}
	else
	{
		ThemkSaup(l, temp, p);
	}
}
void XoaDau(LIST l)
{
	//gan p bang phan tu dau danh sach
	NODE* p = l .pHead;
	//thuc hien gan lai phan tu dau danh sach
	l.pHead = l.pHead->pNext;
	l.pHead->pNext = NULL;
	//neu khong ton tai phan tu dau danh sach
	if (l.pHead == NULL) {
		l.pTail = NULL;
	}
	//thay doi con tro next ve NULL
	p->pNext = NULL;
	//xoa node p duoc gan bang phan tu dau danh sach
	delete p;
}
void XoaCuoi(LIST& ds)
{
	//tao node p va gan bang phan tu cuoi danh sach
	NODE* p = ds.pTail;
	//thuc hien gan lai phan tu cuoi danh sach
	ds.pTail = ds.pTail->pNext;
	ds.pTail->pNext = NULL;
	//kiem tra phan tu cuoi neu rong
	if (ds.pTail == NULL) {
		ds.pHead = NULL;
	}
	//thay doi con tro prev cua node p ve NULL
	p->pNext = NULL;
	//xoa p duoc gan bang phan tu cuoi danh sach
	delete p;
}
void XoaTheoKhoaK(LIST l, int k) {
	//tim kiem theo du lieu x va gan vao node p
	NODE* p = l.pHead;
	//neu tim thay ket qua
	if (p != NULL) {
		//neu p->prev == NULL thuc hien xoa dau
		if (p->pNext == NULL) {
			XoaDau(l);
			return;
		}
		//neu p->next == NULL thuc hien xoa cuoi
		if (p->pNext == NULL) {
			XoaCuoi(l);
			return;
		}
		//thay doi lai lien ket cua phan tu co khoa K can xoa
		p->pNext->pNext = p->pNext;
		p->pNext->pNext = p->pNext;
		//gan con tro prev va next cua phan tu co khoa K can xoa ve null
		p->pNext = NULL;
		p->pNext = NULL;
		//xoa node p co phan tu la khoa k
		delete p;
	}
}
int main()
{
	LIST l;
	khoitao(l);//khoi tao ds lk don
	int n;
	cout << "\nnhap so luong node can them:  ";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cout << "\n Nhap gia tri so nguyen: ";
		cin >> x;
		NODE* p = khoitaoNODE(x);
		themvaodau(l, p);
	}
	cout << "\n DANH SACH THEM VAO DAU LINK LIST : ";
	xuatdanhsach(l);
	cout << "\n XUAT PHAN TU CAU MANG CHAN : ";
	xuatchan(l);
	cout << "\n TIM PHAN TU LON NHAT TRONG MANG :" <<TimMax(l);
	int x;
	cout << "\n NHAP VAO SO X: ";
	cin >> x;
	cout << "\n SO NGUYEN TO TRONG MANG LA :" << LASNT(x);
	cout << "\n CO TONG  SO NGUYEN TO TRONG MANG LA : " << demSNT(l);
	cout << "\n--------------------------------------------------------------------";
	/*
	cout << "\nNhap gia tri can them vao truoc chan dau : ";
	cin >> x;
	themXTruocChanDau(&l, x);
	cout << "\nDanh sach sau khi them vao truoc chan dau : \n";
	xuatdanhsach(l);
	*/
	cout << "\nDANH SACH LE CUOI : ";
	cin >> x;
	themXSauLeCuoi(&l, x);
	xuatdanhsach(l);
	cout << "\nDanh sach sau khi them vao truoc chan dau : \n";
	xuatdanhsach(l);

}
	

