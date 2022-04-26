#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
#define MAX 100
int Random(int min, int max)
{
    int a = min + rand() % (max - min + 1);
    return a;
}
void PhatSinhMang(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        a[i] = Random(1, 100);
    }
}
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
};
typedef struct Node* Tree;
Tree root;
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

void ThemNodeVaoCay(Tree& root, int x)
{
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
        if (root->data > x)
        {
            ThemNodeVaoCay(root->left, x);
        }
        else if (root->data < x)
        {
            ThemNodeVaoCay(root->right, x);
        }
    }
}
void NLR(Tree root)
{
    if (root != NULL)
    {
        cout << "\t" << root->data;
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Tree root) {
    if (root != NULL)
    {
        LNR(root->left);
        cout << "\t" << root->data;
        LNR(root->right);
    }
}
void LRN(Tree root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << "\t" << root->data;
    }
}
void nhapvao(Tree& root)
{
    srand(time(NULL));
    int n;
    cout << "NHAP SO LUONG NODE Cần THêm: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int temp = 10 + rand() % (100 - 10 + 1);
        // tao node p có data =x
       
        ThemNodeVaoCay(root,temp);
    }
}
// So Nguyen To 
int SoNguyenTo(int n) {
    // so nguyen n < 2 khong phai la so nguyen to
    if (n < 2) {
        return 0;
    }
    // check so nguyen to khi n >= 2
    int squareRoot = (int)sqrt(n);
    int i;
    for (i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
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
    if (root == NULL) {
        return;
    }
    if (root->data > X) {
        return DeleteNode(root->left, X);
    }
    if (root->data < X) {
        return DeleteNode(root->right, X);
    }
    Node* p = root;
    if (root->left == NULL) {

        root = root->right;
    }
    else if (root->right == NULL)
    {
        root = root->left;
    }
    else
    {
        FindReplNode(p, root->right);
    }
    delete p;
}
void delete_SNT(Tree& root)
{
    if (root) {
        delete_SNT(root->left);
        delete_SNT(root->right);
        if (SoNguyenTo(root->data))
        {
            DeleteNode(root, root->data);

        }
    }
}
void dem_nut_2_cay(Tree root)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            cout << root->data << " ";//xuat node
        }
        dem_nut_2_cay(root->left);
        dem_nut_2_cay(root->right);
    }
}
void menu(Tree& root)
{
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhập dữ liệu cho cây: ";
        cout << "\n2. Duyệt cây NLR";
        cout << "\n3. Xoa tat ca cac so nguyen to";
        cout << "\n4. Nut Co Cay Con Phai Bang Cay Con Trai:";
        cout << "\n0. Thoát";
        cout << "\n\n\t\t ============================";
        int chon;
        cout << "\nNhập lựa chọn của bạn: ";
        cin >> chon;
        if (chon < 0 || chon >12)
        {
            cout << "\n khong hop le:";
        }
        else if (chon == 1)
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
            delete_SNT(root);
            NLR(root);

        }
        else if (chon == 4)
        {
            cout << "\nSO NUT LA CO HAI CAY CON LA: ";
            dem_nut_2_cay(root);
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
    cout << "\n BYE ";

}


