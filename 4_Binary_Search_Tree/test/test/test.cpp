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
}/*
void timnodecha(Tree& root, Node* p)
{
    if (root != NULL)
    {
        if (root->left != NULL)
            timnodecha(root->left, p);
        if (root->left == p || root->right == p)
            cout << root->data;
        if (root->right != NULL)
            timnodecha(root->right, p);
    }
}
void timnut(Tree& root, int x)
{
    while (root != NULL)
    {
        if (root->data < x)
            root = root->right;
        else if (root->data > x)
            root = root->left;
        else
            root;
    }
}
*/
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
int main()
{
    Tree root;
    //khoi tao cay
    init(root);
    //nhap n phan tu vao cay
    nhapvao(root);
    //them mot phan tu moi vao trong cay
    int x = 15;
    Node* p = taonode(x);
    themnode(root, p);
    //hien thi tat ca du lieu vua them vao cay
    timnodecha(root, p);
    //
    cin >> x;
    timnut(root, x);
}