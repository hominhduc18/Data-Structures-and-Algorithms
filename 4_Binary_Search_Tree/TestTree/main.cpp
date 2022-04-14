#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef int item; //kieu item la kieu nguyen
struct Node
{
     item key; //truong key cua du lieu
     Node *Left, *Right; //con trai va con phai
};
typedef Node *Tree;  //cay

int insertNode(Tree &T, item x) // chen 1 Node vao cay
{
    if (T != NULL)
    {
        if (T->key == x) return -1;  // Node nay da co
        if (T->key > x) return insertNode(T->Left, x); // chen vao Node trai
        else if (T->key < x) return insertNode(T->Right, x);   // chen vao Node phai
    }
    T = (Node *) malloc(sizeof(Node));
    if (T == NULL) return 0;    // khong du bo nho
    T->key = x;
    T->Left = T->Right = NULL;
    return 1;   // ok
}

void CreateTree(Tree &T)        // nhap cay
{
    int x;
    while (1)
    {
        printf("Nhap vao Node: ");
        scanf("%d", &x);
        if (x == 0) break;  // x = 0 thi thoat
        int check = insertNode(T, x);
        if (check == -1) printf("Node da ton tai!");
        else if (check == 0) printf("Khong du bo nho");

    }
}

// Duyet theo LNR
void LNR(Tree T)
{
     if(T!=NULL)
     {
      LNR(T->Left);
      printf("%d   ",T->key);
      LNR(T->Right);
     }
}

Node* searchKey(Tree T, item x)     // tim nut co key x
{
    if (T!=NULL)
    {
        if (T->key == x) { Node *P = T; return P;}
        if (T->key > x) return searchKey(T->Left, x);
        if (T->key < x) return searchKey(T->Right, x);
    }
    return NULL;
}

int delKey(Tree &T, item x)     // xoa nut co key x
{
    if (T==NULL) return 0;
    else if (T->key > x) return delKey(T->Left, x);
    else if (T->key < x) return delKey(T->Right, x);
    else // T->key == x
    {
        if (T->Left == NULL) T = T->Right;    // Node chi co cay con phai
        else if (T->Right == NULL) T = T->Left;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            Node *Q = T->Left;
            while (Q->Right != NULL)
            {
                Q = Q->Right;
            }
            T->key = Q->key;
            delKey(T->Left, Q->key);
        }
    }
    return 1;
}

int kTSNT(item key ){
    for(int i=2;i<=sqrt(key);i++)
    {
        if(key%i==0)
            return 0;
    }return 1;
}

void DelSNT(Tree &Root)
{
	if(Root==NULL)
                return ;
	else
	{
		if(kTSNT(Root->key)==1)
		{
                                if(delKey(Root,Root->key))
                                        printf("xoa thanh cong");
		}
		DelSNT(Root->Left);
		DelSNT(Root->Right);
	}
}

int main()
{
    Tree T;
    T=NULL; //Tao cay rong

    CreateTree(T); //Nhap cay
    //duyet cay
    printf("Duyet cay theo LNR: \n");
    LNR(T);
    printf("\n");

    Node *P;
    item x;
    printf("Nhap vao key can tim: ");
    scanf("%d", &x);
    P = searchKey(T, x);
    if (P != NULL) printf("Tim thay key %d\n", P->key);
    else printf("Key %d khong co trong cay\n", x);

    if (delKey(T, x)) printf("Xoa thanh cong\n");
    else printf("Khong tim thay key %d can xoan", x);
    printf("Duyet cay theo LNR: \n");
    LNR(T);
    printf("\n");
    DelSNT(T);
    printf("Duyet cay theo LNR: \n");
    LNR(T);
    return 0;
}
