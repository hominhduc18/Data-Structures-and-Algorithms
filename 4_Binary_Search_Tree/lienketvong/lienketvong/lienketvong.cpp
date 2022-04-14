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
Node* searchNode(Tree t, int x)
{
    if (t)
    {
        if (t->data == x) return t;
        else
        {
            Node* p = searchNode(t->left, x);
            if (!p) p = searchNode(t->right, x);
        }
    }
    return NULL;
}

void insearchNode(Tree& root, Node* p)
{
    if (!root) root = p;
    else
    {
        int x;
        cout << "\n nhap "; cin >> x;
        Node* q = searchNode(root, x);
        if (p)
        {
            int vt;
            cout << "\n1 thêm trai ,\n2_themphai :";
            cin >> vt;
            if (vt == 1)
            {
                q->left = p;
            }
            else
            {
                q->right = p;
            }
        }
        else cout << "sai";
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
        insearchNode(root, p);
    }
}

void LNR(Tree root)
{
    if (root)
    {
        LNR(root->left);
        cout << root->data << " ";
        LNR(root->right);
    }
}
int main()
{
    Tree root;
    init(root);
    nhapvao(root);
    LNR(root);
    return 0;
}

