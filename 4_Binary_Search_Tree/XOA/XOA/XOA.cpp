#include<iostream>
using namespace std;
// khai báo cấu trúc 1 cái node trong cây nhị phân tìm kiếm
struct node
{
    int data; // dữ liệu chứa trong 1 cái node
    struct node* pLeft; // con trỏ liên kết với cái node bên trái <=> cây con trái
    struct node* pRight; // con trỏ liên kết với cái node bên phải <=> cây con phải
};
typedef struct node NODE;
typedef NODE* TREE;

// hàm khởi tạo cây nhị phân tìm kiếm
void KhoiTaoCay(TREE& t)
{
    t = NULL;
}

// hàm thêm 1 cái phần tử vào cây
void ThemNodeVaoCay(TREE& t, int x)
{
    // nếu cây rỗng
    if (t == NULL)
    {
        NODE* p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        if (x < t->data)
        {
            ThemNodeVaoCay(t->pLeft, x);
        }
        else if (x > t->data)
        {
            ThemNodeVaoCay(t->pRight, x);
        }
    }
}

void NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t->data << "  ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void NodeTheMang(TREE& X, TREE& Y) 
{
   
    if (Y->pLeft != NULL)
    {
        NodeTheMang(X, Y->pLeft);
    }
    else 
    {
        X->data = Y->data; 
        X = Y; 
        Y = Y->pRight;
    }

}
void XoaNode(TREE& t, int data) 
{
    // nếu như cây đang rỗng
    if (t == NULL)
    {
        return;
    }
    else
    {
        if (data < t->data)
        {
            XoaNode(t->pLeft, data);
        }
        else if (data > t->data)
        {
            XoaNode(t->pRight, data); 
        }
        else 
        {
            NODE* X = t; 
            if (t->pLeft == NULL)
            {
                t = t->pRight;
            }
            else if (t->pRight == NULL)
            {
                t = t->pLeft;
            }
            else
            {
                
                NodeTheMang(X, t->pRight);
                
            }
            delete X; // xóa node cần xóa
        }
    }
}

// hàm nhập cây nhị phân tìm kiếm
void Menu(TREE& t)
{
    int luachon;
    while (true)
    {
        cout << "\n1. Nhập phần tử cho cây";
        cout << "\n2. Duyệt cây";
        cout << "\n3. Xóa một Node bất kì";
        cout << "\n0. Thoát";
   

        cout << "\nNhập lựa chọn của bạn: ";
        cin >> luachon;

        if (luachon == 1)
        {
            int x;
            cout << "\nNhập giá trị: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\nCây nhị phân tìm kiếm\n";
            NLR(t);
        }
        else if (luachon == 3)
        {
            int x;
            cout << "\nNhập giá trị cần xóa: ";
            cin >> x;
            XoaNode(t, x);
        }
        else
        {
            break;
        }
    }
}


int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);

   
   
}
