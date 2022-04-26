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

        ThemNodeVaoCay(root, temp);
    }
}

int SOChinhPhuong(int n) {
    int i = 0;
    while (i * i <= n) {
        if (i * i == n) {
            return 1;
        }
        ++i;
    }
    return 0;
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
        if (SOChinhPhuong(root->data))
        {
            DeleteNode(root, root->data);

        }
    }
}
int sum2_nut(Tree root)
{
    int sum = 0;
    if (root)
    {
        sum = root->data;
        sum += sum2_nut(root->left);
        sum += sum2_nut(root->right);
    }
    return sum;
}
void dem_nut_2_cay(Tree root)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            if (sum2_nut(root->left) == sum2_nut(root->right))
            {
                cout << root->data << " ";
            }
            dem_nut_2_cay(root->left);
            dem_nut_2_cay(root->right);
        }
    }
}
void menu(Tree& root)
{
    while (true)
    {
        cout << "\n\n\t\t =========== MENU ===========";
        cout << "\n1. Nhập dữ liệu cho cây: ";
        cout << "\n2. Duyệt cây NLR";
        cout << "\n3. XOA ";
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
            cout << "\n " << SOChinhPhuong(root->data);
            delete_SNT(root);
            NLR(root);

        }
        else if (chon == 4)
        {
            cout << "\nTong Cay Con hai root: ";
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
    ThemNodeVaoCay(root, 10);
    ThemNodeVaoCay(root, 6);
    ThemNodeVaoCay(root, 15);
    ThemNodeVaoCay(root, 2);
    ThemNodeVaoCay(root, 9);
    ThemNodeVaoCay(root, 12);
    ThemNodeVaoCay(root, 26);
    ThemNodeVaoCay(root, 14);
    menu(root);
    sum2_nut(root);
    cout << "\n BYE ";

}


