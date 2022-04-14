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
void init(Tree& root)
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
int themnode(Tree& root, Node* p)
{
    // neu node khac rong thi them vao cay 
    if (root != NULL)
    {
        //nếu 2 data của 2 node băng nhau thi ket thuc
        if (root->data == p->data)
        {
            return 0;
        }
        // neu khoa cua root lon hon khoa cua p thi gọi de quy trai
        if (root->data > p->data)
        {
            return themnode(root->right, p);
        }
        else
        {
            // neu khoa của root nhỏ hơn khóa của p thì gọi đệ quy phait
            return themnode(root->right, p);
        }
    }
    else
    {
        // neu node root rổng thuig thêm node p vao node root
        root = p;
    }
}
void nhapvao(Tree& root)
{
    int n;
    cout << "NHAP SO LUONG NODE Cần THêm: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "NHAP DATA CHO NODE :";
        cin >> x;
        // tao node p có data =x
        Node* p = taonode(x);
        themnode(root, p);
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


 void DeleteNode(Tree& root, int X) {
     //neu cay rong thi ket thuc ham xoa
     if (root == NULL) {
         return;
     }
     //neu khoa X nho hon data cua node dang xet
     if (root->data > X) {
         //de quy ham xoa theo nhanh trai
         return DeleteNode(root->left, X);
     }
     //neu khoa X lon hon data cua node dang xet
     if (root->data < X) {
         //de quy ham xoa theo nhanh phai
         return DeleteNode(root->right, X);
     }
     //tao node p lam node the mang
     Node* p = root;
     //neu cay con trai la rong
     if (root->left == NULL) {
         //gan lai node goc theo nhanh phai
         root = root->right;
     }
     else if (root->right == NULL) {//neu cay con phai la rong
        //gan lai node goc theo nhanh trai
         root = root->left;
     }
     else { // nguoc lai, neu cay co du 2 con
        //su dung node the mang
         FindReplNode(p, root->right);
     }
     //xoa di node p
     delete p;
 }

void menu(Tree& root)
{
    while (true)
    {

        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhập dữ liệu cho cây: ";
        cout << "\n2. Duyệt cây NLR";
        cout << "\n3. Duyệt cây LNR";
        cout << "\n4. Duyệt cây LRN";
        cout << "\n5.tim xoa :";
        cout << "\n0. Thoát";
        cout << "\n\n\t\t ============================";
        int chon;
        cout << "\nNhập lựa chọn của bạn: ";
        cin >> chon;
        if (chon < 0 || chon >5)
        {
            cout << "\n khong hop le:";
        }
        else if(chon==1)
        {
            nhapvao(root);
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
        else if(chon==5)
        {
            int x;
            cin >> x;
            cout << "\n tim kiem có ko  :";
            
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
    int x;
    cout << "nhập x cân xoa";
    cin >> x;
    nhapvao(root);
    DeleteNode(root, x);
}