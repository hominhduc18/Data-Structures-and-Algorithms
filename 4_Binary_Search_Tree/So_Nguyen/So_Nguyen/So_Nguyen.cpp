/*
 Bài 1: Khai báo cấu trúc dữ liệu cây nhị phân (các node có giá trị là số nguyên) và viết 
chương trình thực hiện các yêu cầu sau:
1. Nhập và duyệt cây theo các thứ tự: trước, giữa và sau.
2. Tìm node có giá trị x trên cây.
3. Tìm node có giá trị nhỏ nhất.
4. Tìm node có giá trị lớn nhất.
5. Tính độ cao của cây.
6. Đếm số nút lá của cây.
7. Đếm số nút có đúng 2 cây con.
8. Đếm số nút có đúng 1 cây con.
9. Xóa nút có giá trị x
*/
#include <iostream>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct Node
{
    // khai báo biến dữ liệu của node
    int data;
    // khai bao con tro den cay trai
    Node* left;
    // khai bao con tro den cay phai
    Node* right;
};
typedef struct Node* Tree;
Tree root;
// gan node gốc về NUll
void init(Tree& root) // tao cay
{
    root = NULL;
}
Node* taonode(int x)
{
    // tao node moi
    Node* p = new Node;
    // neu node p đươc cap phat cho bo nho 
    if (p != NULL)
    {
        // gan cay con trai va cay con phai mac đinh bang NULL
        p->left = NULL;
        p->right = NULL;
        // gan data=x
        p->data = x;
    }
    return p;
}
// thêm phan tu vao trong cay
void ThemNodeVaoCay(Tree& root, int x)
{
    // nếu cây rỗng
    if (root == NULL)
    {
        Node* p = new Node;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        root = p;
    }
    else
    {
        // nếu phần tử thêm vào mà nhỏ hơn nút gốc thì sẽ duyệt qua bên trái
        if (x < root->data)
        {
            ThemNodeVaoCay(root->left, x);
        }
        else if (x > root->data)
        {
            ThemNodeVaoCay(root->right, x);
        }
    }
}
void NLR(Tree root)
{
    if (root != NULL)
    {
        // hien thi du lieu cua tung node sau khi duyet
        cout << root->data;
        // duyet tiep cay con trai
        NLR(root->left);
        // duyet tiep cay con phai
        NLR(root->right);
    }
}
void LNR(Tree root) {
    if (root != NULL) {
        //su dung de quy de duyet tiep cay con trai
        LNR(root->left);
        //xy ly node goc
        cout << root->data;
        //su dung de quy de duyet tiep cay con phai
        LNR(root->right);
    }
}
void LRN(Tree root) {
    if (root != NULL) {
        //su dung de quy de duyet tiep cay con trai
        LRN(root->left);
        //su dung de quy de duyet tiep cay con phai
        LRN(root->right);
        //xu ly node goc
        cout << root->data;
    }
}
Node* Search(Tree root, int x) {
    //neu cay khong rong
    if (root != NULL) {
        //neu data cua node goc bang x can tim 
        if (root->data == x) {
            //tra ve node goc cua cay
            return root;
        }
        //neu data cua node goc lon hon x can tim   
        if (root->data > x) {
            //goi lai ham tim kiem theo cay con trai
            return Search(root->left, x);
        }
        else {//nguoc lai data cua node goc nho hon x can tim
           //goi lai ham tim kiem theo cay con phai 
            return Search(root->right, x);
        }
    }
    //neu khong tim thay node co data bang x thi tra ve rong
    return NULL;
}
int timMax(Tree root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    return timMax(root->right);
    
}
void FindReplNode(Tree& p, Tree& q) {
    if (q->left) {
        FindReplNode(p, q->left);
    }
    else {
        p->data = q->data;
        p = q;
        q = q->right;
    }
}
void menu(Tree& root)
{
    int chon;
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhập dữ liệu cho cây: ";
        cout << "\n2. Duyệt cây NLR";
        cout << "\n3. Duyệt cây LNR";
        cout << "\n4. Duyệt cây LRN";
        cout << "\n5.tim xoa :";
        cout << "\n6.tim max :";
        cout << "\n0. Thoát";
        cout << "\n\n\t\t ============================";
        
        cout << "\nNhập lựa chọn của bạn: ";
        cin >> chon;
        if (chon < 0 || chon >7)
        {
            cout << "\n khong hop le:";
        }
        else if (chon == 1)
        {
            int x;
            cout << "\nNhập giá trị: ";
            cin >> x;
            ThemNodeVaoCay(root, x);
        }
        else if (chon == 2)
        {
            cout << "\n duyet cay NLR: ";
            NLR(root);
        }
        else if (chon == 3)
        {
            cout << "\n duyet cay LNR: ";
            LNR(root);
        }
        else if (chon == 4)
        {
            cout << "\nduyet cay LRN: ";
            LRN(root);
        }
        else if (chon == 5)
        {
            int x;
            cin >> x;
            cout << "\n tim kiem có ko  :";

        }
        else if (chon == 6)
        {
            cout << "\n tim max :"<< timMax(root);

        }
        else
        {
            break;
        }
    }
}
int main()
{
    Tree root;
    init(root);
    menu(root);
    cout << "\nSAY GOOD BYE ";
   
    
    
    
}