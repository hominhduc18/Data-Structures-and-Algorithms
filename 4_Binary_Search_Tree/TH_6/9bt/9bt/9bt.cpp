#include <iostream>
#include <stdio.h>
using namespace std;
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

/*void nhapvao(Tree& root)
{
    int n;
    cout << "NHAP SO LUONG NODE Cần THêm: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cout << "NHAP DATA CHO NODE :";
        cin >> x;
        Node* p = taonode(x);
        themnode(root, p);
    }
}
*/
//1. Nhập và duyệt cây theo các thứ tự: trước, giữa và sau.
void NLR(Tree root)
{
    if (root != NULL)
    {
        cout <<"\t\t" <<root->data;
        NLR(root->left);
        NLR(root->right);
    }
}
void LNR(Tree root) {
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->data;
        LNR(root->right);
    }
}
void LRN(Tree root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data;
    }
}
//2. Tìm node có giá trị x trên cây.
Node* Search_Node(Tree root, int x) {
    if (root != NULL) {
        if (root->data == x)
        {
            return root;
        }
        if (root->data > x) {
            return Search_Node(root->left, x);
        }
        else
        {
            return Search_Node(root->right, x);
        }
    }
    return NULL;
}
//2. Tìm node có giá trị x trên cây.
Node* SearchNode(Tree root, int x) {
    Node* p = root;
    while (p != NULL)
    {
        if (p->data == x) {
            return p;
        }
        else
        {
            if (x < p->data)
            {
                p = p->left;
            }
            else
            {
                p = p->right;
            }
        }
    }
    return NULL;
}
//3. Tìm node có giá trị nhỏ nhất.
void Search_Node_Min(Tree root)
{
    if (root->left == NULL)
    {
        cout << root->data;
    }
    Search_Node_Min(root->left);
}
//4. Tìm node có giá trị lớn nhất.
void Search_Node_Max(Tree root)
{
    if (root->right == NULL)
    {
        cout << root->data;
    }
    Search_Node_Max(root->right);

}
//5. Tính độ cao của cây.
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int heigh_tree(Tree root)
{
    if (root == NULL)
        return 0;
    else
        return max(heigh_tree(root->left), heigh_tree(root->right)) + 1;
}
//6. Đếm số nút lá của cây
int dem_Node(Tree root)
{
    if (root == NULL)
        return 0;
    else
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            return dem_Node(root->left) + dem_Node(root->right);
}
//7. Đếm số nút có đúng 2 cây con.
void dem_nut_2_cay(Tree root)
{
    if (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            cout << root->data << " ";//xuat node
        }
        dem_nut_2_cay(root->left);//duyet cay con trai hien tai
        dem_nut_2_cay(root->right);// duyet cay con phai hien tai
    }
}
//8. Đếm số nút có đúng 1 cây con.
void dem_nut_1_cay(Tree root)
{

    if (root != NULL)
    {
        if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        {
            cout << root->data << " ";//xuat node
        }
        dem_nut_2_cay(root->left);//duyet cay con trai hien tai
        dem_nut_2_cay(root->right);// duyet cay con phai hien tai
    }
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
//9. Xóa nút có giá trị x.
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
void RemoveTree(Tree& root) {
    //neu van ton tai node goc
    if (root) {
        //de quy sang nhanh trai
        RemoveTree(root->left);
        //de quy sang nhanh phai
        RemoveTree(root->right);
        //xoa node goc
        delete(root);
    }
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
        cout << "\n5. Tim Node Co Gia Tri x:";
        cout << "\n6. Tim Node co Gia Tri x Nho Nhat: ";
        cout << "\n7. Tim Node co Gia Tri x Lon Nhat:";
        cout << "\n8. Tính độ cao của cây: ";
        cout << "\n9. Đếm số nút lá của cây: ";
        cout << "\n10. Đếm số nút có đúng 2 cây con:";
        cout << "\n11. Đếm số nút có đúng 1 cây con: ";
        cout << "\n12. Xóa nút có giá trị x:";
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
            int x;
            cout << "\n Nhap So Nguyen : ";
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

