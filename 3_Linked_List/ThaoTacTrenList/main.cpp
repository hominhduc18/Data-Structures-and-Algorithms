
#include<fstream>
#include <iostream>
using namespace std;

//khai báo 1 node
struct node{
        int data;
        node*next;
};

struct dslk{
        node* head;
        node* tail;
};
//Thu tuc cho phep tao 1 node khi có gia tri x
//@param x la gia tri cua nut
//@return con tro tro den nut chua gia tri x
node* createNode(int x){
        node *p;
        p=new node;
        if(p==NULL)
                return NULL;
        p->data=x;
        p->next=NULL;
        return p;
}
///Ham khoi tao 1 dslk
//@param l la danh sach can khoi tao
void init( dslk &l){
        l.head=NULL;
        l.tail=NULL;
}
//ham them 1 nut vao dau dslk
//param p la nut can them
void addFirst(dslk &l,node*p){
        if(l.head==NULL)
                l.head=l.tail=p;
        else{
                p->next=l.head;
                l.head=p;
        }
}

void addLast(dslk &l,node*p){
        if(l.head==NULL)
                .head=l.tail=p;
        else{
                l.tail->next=p;
                l.tail=p;
        }
}
//chen node n vao sau node p trong danh sach
void addAfter(dslk&l,node *q,node*new_node){
        if(l.head==NULL&&q==NULL)
                l.head=l.tail=new_node;
        if (q!=NULL){
                new_node->next = q->next;
                q->next = new_node;
                if(q == l.tail)
                        l.tail = new_node;
        }
}

void addBefore(dslk&l,node *q,node*new_node){
        node*p=NULL;
        node*t=l.head;
        while(t->data!=q->data&&t!=NULL){
                p=t;
                t=t->next;
        }
        addAfter(l,p,new_node);
}
//add phan tu vao sao cho danh sach luon tang dan
void addSort(dslk&l,node*n){
        if(l.head==NULL)
                l.head=l.tail=n;
        else{
                if(n->data<=l.head->data)
                        addFirst(l,n);
                else if(n->data>=l.tail->data)
                        addLast(l,n);
                        else{
                                node*t=l.head;
                                while(t!=NULL){
                                if(t->data>n->data)
                                        break;
                                t=t->next;
                                }
                                addBefore(l,t,n);
                        }
        }
}

//Ham nay dung de duyet qua danh sach va in gia tri data
//param l la danh sach can duyet
void traverse(dslk l){
        node*t=l.head;
        while(t!=NULL){
                cout<<t->data<<" ";
                t=t->next;
        }
        cout<<endl;
}

int nodesCounter(dslk l){
        node*t=l.head;
        int dem=0;
        while(t!=NULL){
                dem++;
                t=t->next;
        }
        return dem;
}

node*searchByKey(dslk l,int data){
        node*t=l.head;
        while(t!=NULL){
                if(t->data==data)
                        return t;
                t=t->next;
        }
        return NULL;
}
//xoa 1 phan tu dau danh sach
int deleteFirst(dslk&l){
        if(l.head==NULL)
                return -1;
        node*p=l.head;//phan tu can xoa
                l.head=p->next;
        if(l.head==NULL)
                l.tail=NULL;
        delete p;
        return 1;
}
//Xoa 1 node sau node q
//tra ve 1 neu xoa thanh cong
int deleteAfter(dslk&l,node*q){
        if(q==NULL || q->next==NULL)
                return -1;
        node*p=q->next;
        q->next=p->next;
        if(p==l.tail)
                l.tail=q;
        delete p;
        return 1;
}
//xoa 1 nút có khóa là key
//tra ve -1 neu ds rong, 0 neu khong tim thay, 1 neu OK
int deleteByKey(dslk&l,int key){
        if(l.head==NULL) return -1;
        node*sau=l.head;
        node*truoc=NULL;
        while(sau!=NULL){
                if(sau->data==key) break;
                truoc=sau;
                sau=sau->next;
        }
        if(sau==NULL)
                return 0;
        if(truoc==NULL)
                return deleteFirst(l);
        return deleteAfter(l,truoc);
}
//xoa tat ca cac nut trong dslk l co data=key
void deleteByKeyAll(dslk&l,int key){
        if(l.head==NULL) return;
        node*sau=l.head;
        node*truoc=NULL;int x=-1;
        while(sau!=NULL){
                x=-1;
                if(sau->data==key){
                        if(truoc==NULL)
                                deleteFirst(l);
                        else
                                deleteAfter(l,truoc);
                        sau=l.head;
                        truoc=NULL;
                        x=1;
                }
                if(x!=1){
                        truoc=sau;
                        sau=sau->next;
                }
        }
}
//huy toan bo danh sach
void removeAll(dslk&l){
        node*p;
        while(l.head!=NULL){
        p=l.head;
        l.head=p->next;
        delete p;
        }
        l.tail=NULL;
}
//ham ghi du lieu xuong file
void write2file(char * filename, dslk ds){
        ofstream fs(filename, ios::binary | ios::out );//| ios::app
        node*t=ds.head;
        while(t!=NULL){
                fs.write((char*)&t->data,sizeof(int));
                t=t->next;
        }
        fs.close();
}
///hàm doc du lieu tu file
void readfromfile(char * filename, dslk &ds){
        init(ds);
        ifstream infile(filename,ios::in|ios::binary);
        if(infile!=NULL){
                int data;
                infile.read((char*)&data,sizeof(int));
                while(!infile.eof()){
                        node*n=createNode(data);
                        addLast(ds,n);
                        infile.read((char*)&data,sizeof(int));
                }
        }
        infile.close();
}
