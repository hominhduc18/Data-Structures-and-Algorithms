#include <iostream>
#include <cstring>
#include<fstream>
#include<string>
#include <ctime>
#include <time.h>
#include <iomanip>

using namespace std;
struct problem
{
	string cauHoi;
	string ansRight;
	string  ansWrong[3];
};

struct Node
{
    problem data;
    Node *link;
};

struct List
{
    Node *first, *last;
};

void Init(List &l)
{
    l.first = l.last = NULL;
}

Node *GetNode(problem x)
{
    Node *p;
    p= new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}


void addLast(List &l,Node *new_ele){
        if(l.first==NULL) l.first=new_ele;
        else
        {
                Node* p;
                p=l.first;
                while(p->link!=NULL){
                        p=p->link;
                }p->link=new_ele;
        }
}

void InsertLast(List &l, problem x)
{
	Node* new_ele = GetNode(x);
	if (new_ele == NULL)
		return;
	addLast(l, new_ele);
}

void docCauHoi(ifstream &filein,problem &pr){
        getline(filein , pr.cauHoi ,'\n');
        getline(filein , pr.ansRight ,'\n');
        getline(filein ,pr.ansWrong[0],'\n');
        getline(filein , pr.ansWrong[1],'\n');
        getline(filein , pr.ansWrong[2],'\n');
}

void docDSCauHoi(ifstream &filein,List &l){
        filein.open("Cauhoi.txt",ios::in);
        while(!filein.eof()){
                problem pr;
                docCauHoi(filein,pr);
                InsertLast(l,pr);
        }
        filein.close();
}

void xuat(problem &pr,int x){
        if(x==1){
        cout<<"\n\n\n"<<setw(10) << " "<< setw(60)<<left<<pr.cauHoi;
        cout<<"\n\n"<<setw(10) << " "<<"1."<<setw(40)<<left<<pr.ansRight<<"2."<<setw(30)<<left<<pr.ansWrong[0];
        cout<<"\n\n"<<setw(10) << " "<<"3."<<setw(40)<<left<<pr.ansWrong[1]<<"4."<<setw(30)<<left<<pr.ansWrong[2];
        }
        if(x==2){
        cout<<"\n\n\n"<<setw(10) << " "<< setw(30)<<left<<pr.cauHoi;
        cout<<"\n\n"<<setw(10) << " "<<"1."<<setw(40)<<left<<pr.ansWrong[2]<<"2."<<setw(30)<<left<<pr.ansRight;
        cout<<"\n\n"<<setw(10) << " "<<"3."<<setw(40)<<left<<pr.ansWrong[1]<<"4."<<setw(30)<<left<<pr.ansWrong[0];
        }
        if(x==3){
        cout<<"\n\n\n"<<setw(10) << " "<<setw(30)<<left<<pr.cauHoi;
        cout<<"\n\n"<<setw(10) << " "<< "1."<<setw(40)<<left<<pr.ansWrong[2]<<"2."<<setw(30)<<left<<pr.ansWrong[1];
        cout<<"\n\n"<<setw(10) << " "<<"3."<<setw(40)<<left<<pr.ansRight<<"4."<<setw(30)<<left<<pr.ansWrong[0];
        }
        if(x==4){
        cout<<"\n\n\n"<<setw(10) << " "<< setw(30)<<left<<pr.cauHoi;
        cout<<"\n\n"<<setw(10) << " "<<"1."<<setw(40)<<left<<pr.ansWrong[1]<<"2."<<setw(30)<<left<<pr.ansWrong[0];
        cout<<"\n\n"<<setw(10) << " "<<"3."<<setw(40)<<left<<pr.ansWrong[2]<<"4."<<setw(30)<<left<<pr.ansRight;
        }
}

void wait ( int seconds )
{
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {}
}

void show(Node* p,int x,int count){
                int n;
                system("cls");
                for (n = 15; n > 0; n--) {
                cout<<"\n\n\n\n"<<setw(18)<<left<<"so diem cua ban la "<<count<<setw(30) << " "<<setw(20)<<right<<n;
                xuat(p->data,x);
                wait (1);
                system("cls");
                }
}

void star(){
        cout<<"\n\n\n\n\n\n"<<setw(30)<<" "<<"Chao Mung Ban Den Choi Chuong Trinh Ai la Trieu Phu";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(20)<<" "<<"Cach Choi Chuong Trinh Nay Bat Ban Phai Tra Loi Het Tat Ca Cac Cau Hoi";
         //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(40)<<" "<<"Voi Tieu Tri Duoc An Ca Nga Ve Khong";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(35)<<" "<<"Ban Co 15 Giay De Suy Nghi De Dua Ra Dap An";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(45)<<" "<<"Bat Dau Vao Chuong Trinh";
        //wait(3);
}

int choi(List &l){
        Node *p=l.first;
        int count=0;
        int dapAn,res;
        srand(time(NULL));
        star();
        while(p!=NULL){
                res = rand() % (4)+1;
                show(p,res,count);
                 cout<<"\n\n\n\n"<<setw(18)<<left<<"so diem cua ban la "<<count;
                xuat(p->data,res);
                cout<<"\n\n\n\tdap an: ";
                cin>>dapAn;
                if(dapAn==res){
                        p=p->link;
                        count++;
                }else {
                        p=l.last;
                }
        }return count;
}

problem nhap(){
        problem pr;
        cout<<"\n\n"<<setw(30)<<"nhap cau hoi";
        cin>>pr.cauHoi;
        cout<<setw(30)<<"nhap cau tra loi dung";
        cin>>pr.ansRight;
        cout<<setw(30)<<"nhap cau tra loi sai";
        cin>>pr.ansWrong[0];
        cout<<setw(30)<<"nhap cau tra loi sai";
        cin>>pr.ansWrong[1];
        cout<<setw(30)<<"nhap cau tra loi sai";
        cin>>pr.ansWrong[2];
        return pr;
}
void ghiCauHoi(ofstream &fileout){
        problem pr=nhap();
        fileout.open("Cauhoi.txt",ios::out);
        fileout<<"\n"<<pr.cauHoi;
        fileout<<"\n"<<pr.ansRight;
        fileout<<"\n"<<pr.ansWrong[0];
        fileout<<"\n"<<pr.ansWrong[1];
        fileout<<"\n"<<pr.ansWrong[3];
        fileout.close();
}

int main()
{
    ofstream fileout;
    ifstream filein;
    List l;
    Init(l);
    docDSCauHoi(filein,l);
    ghiCauHoi(fileout);
    docDSCauHoi(filein,l);
    return 0;
}
