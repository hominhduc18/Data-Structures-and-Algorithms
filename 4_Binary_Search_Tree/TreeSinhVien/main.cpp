#include <iostream>
#include<stdio.h>
using namespace std;
struct SinhVien{
        int maSV;
        char ten[20];
        char nganh[20];
        char lop[10];
        double diemTB;
};

struct Node{
	SinhVien data;
	Node *left;
	Node *right;
};
void Free(Node* root )
{
	if (root == NULL)
		return;
	Free(root -> left);
	Free(root -> right);
	free(root);
}
int LeftOf(SinhVien &value, const Node* root){
	return value.maSV < root->data.maSV;
}
int RightOf(SinhVien &value, const Node* root){
	return value.maSV > root->data.maSV;
}
Node* Insert(Node* root, SinhVien value){
	if(root== NULL){
		Node* node = (Node*)malloc(sizeof(Node));
		node->left = NULL;
		node->right = NULL;
		node->data = value;
		return node;
	}
	if(LeftOf(value,root))
		root->left= Insert(root->left,value);
	else if(RightOf(value,root))
		root->right= Insert(root->right,value);
    return root;
}

void Input(Node* &root){
        SinhVien value;
	cout<<"Nhap ma -1 de ket thuc!!!\n";
	do{
		cout<<"Nhap ma sinh vien: ";
		scanf("%d",&value.maSV);
		if(value.maSV==-1)
                        break;
		cout<<"Nhap ten sinh vien: ";
		fflush(stdin);
		gets(value.ten);
		cout<<"Nhap nganh cua sinh vien: ";
		fflush(stdin);
		gets(value.nganh);
		cout<<"Nhap diem TB cua sinh vien:";
		scanf("%lf",&value.diemTB);
		if(value.maSV!=-1)
		{
			root = Insert(root,value);
		}
	}while(value.maSV!=-1);
}

void xuatSV(SinhVien &sv){
        printf("\n|%10d|%20s|%20s|%15.2f|",sv.maSV,sv.ten,sv.nganh,sv.diemTB);
}
void NLR(Node* root){
	if(root!= NULL){
		xuatSV(root->data);
		NLR(root->left);
		NLR(root->right);
	}
}

void LNR(Node* root){
	if(root!= NULL){
        LNR(root->left);
		xuatSV(root->data);
		LNR(root->right);
	}
}

void LRN(Node* root){
	if(root!= NULL){
		LRN(root->left);
		LRN(root->right);
		xuatSV(root->data);
	}
}

int main()
{
        Node* root = NULL;
	Input(root);
	LNR(root);
    return 0;
}
