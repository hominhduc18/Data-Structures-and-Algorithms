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
        // đọc câu hỏi
        getline(filein , pr.cauHoi ,'\n');
        //đọc câu trả lời đúng
        getline(filein , pr.ansRight ,'\n');
        // đọc câu trả lời sai thứ 1
        getline(filein ,pr.ansWrong[0],'\n');
        // đọc câu trả lời sai thứ 2
        getline(filein , pr.ansWrong[1],'\n');
        // đọc câu trả lời sai thứ 3
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
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        cout<<"|"<<setw(10) << " "<< setw(60)<<left<<pr.cauHoi<<setw(10)<<right<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"1."<<setw(30)<<left<<pr.ansRight<<"2."<<setw(35)<<left<<pr.ansWrong[0]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"3."<<setw(30)<<left<<pr.ansWrong[1]<<"4."<<setw(35)<<left<<pr.ansWrong[2]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        }
        if(x==2){
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        cout<<"|"<<setw(10) << " "<< setw(60)<<left<<pr.cauHoi<<setw(10)<<right<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"1."<<setw(30)<<left<<pr.ansWrong[2]<<"2."<<setw(35)<<left<<pr.ansRight<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"3."<<setw(30)<<left<<pr.ansWrong[1]<<"4."<<setw(35)<<left<<pr.ansWrong[0]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        }
        if(x==3){
                        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        cout<<"|"<<setw(10) << " "<<setw(60)<<left<<pr.cauHoi<<setw(10)<<right<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<< "1."<<setw(30)<<left<<pr.ansWrong[2]<<"2."<<setw(35)<<left<<pr.ansWrong[1]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"3."<<setw(30)<<left<<pr.ansRight<<"4."<<setw(35)<<left<<pr.ansWrong[0]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        }
        if(x==4){
                        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        cout<<"|"<<setw(10) << " "<< setw(60)<<left<<pr.cauHoi<<setw(10)<<right<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"1."<<setw(30)<<left<<pr.ansWrong[1]<<"2."<<setw(35)<<left<<pr.ansWrong[0]<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout<<"|"<<setw(10) << " "<<"3."<<setw(30)<<left<<pr.ansWrong[2]<<"4."<<setw(35)<<left<<pr.ansRight<<"|"<<endl;
        cout<<"|"<<setw(80)<<right<<"|"<<endl;
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
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
                cout<<"\n\n\n\n"<<setw(21)<<right<<"SO DIEM CUA LA: "<<count<<setw(55) << right<<"Time: "<<setw(2)<<left<<n<<endl;
                xuat(p->data,x);
                wait (1);
                system("cls");
                }
}

void star(){
        cout << setfill('=');
	cout << setw(81) << "=" ;
	cout << setfill(' ')<<endl;
        cout<<"\n\n\n\n\n\n"<<setw(45)<<" "<<"CHAO MUNG BAN DEN VOI CHUONG TRINH AI LA TRIEU PHU !!!";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(30)<<" "<<"CACH DE BAN THANG GAME NAY THI BAN PHAI BAT BUOC TRA LOI HET TAT CA CAC CAU HOI";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(60)<<" "<<"BAN CO 15S DE SUY NGHI VA DUA RA DAP AN";
        //wait(5);
        system("cls");
        cout<<"\n\n\n\n\n\n"<<setw(65)<<" "<<"BAT DAU VAO CHUONG TRINH NAO";
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
                 cout<<"\n\n\n\n"<<setw(21)<<right<<"SO DIEM CUA BAN LA "<<count<<endl;
                xuat(p->data,res);
                cout<<"\n\n\tDAP AN: ";
                cin>>dapAn;
                if(dapAn==res){
                        p=p->link;
                        count++;
                }else {
                        p=l.last;
                }
        }return count;
}

void ketQua(List &l){
        int key;
        if(key==choi(l))
                cout<<"\n\n\n\n\n"<<setw(40)<<right<<"CHUC MUNG BAN DA TRO THANH TRIEU PHU";
        else
                cout<<"\n\n\n\n\n"<<setw(40)<<right<<"CHUC BAN MAY MAN LAN SAU";
        system("cls");
}

void nhap(List &l){
        problem pr;
        cout<<"\n\n"<<setw(30)<<left<<"NHAP CAU HOI : ";
        fflush(stdin);
        cin>>pr.cauHoi;
        cout<<setw(30)<<left<<"NHAP CAU TRA LOI DUNG : ";
        fflush(stdin);
        cin>>pr.ansRight;
        cout<<setw(30)<<"NHAP CAU TRA LOI SAI: ";
        fflush(stdin);
        cin>>pr.ansWrong[0];
        cout<<setw(30)<<left<<"NHAP CAU TRA LOI SAI: ";
        fflush(stdin);
        cin>>pr.ansWrong[1];
        cout<<setw(30)<<left<<"NHAP CAU TRA LOI SAI: ";
        fflush(stdin);
        cin>>pr.ansWrong[2];
        InsertLast(l,pr);
}

void Print(problem &pr)
{
		cout<<"\t\t\t"<<pr.cauHoi<<endl;
		cout<<"\t\t\t"<<pr.ansRight<<endl;
		cout<<"\t\t\t"<<pr.ansWrong[0]<<endl;
		cout<<"\t\t\t"<<pr.ansWrong[1]<<endl;
		cout<<"\t\t\t"<<pr.ansWrong[2]<<endl;
}


int main()
{
        ifstream filein;
        ofstream fileout;
        List l;
        Init(l);
        int chon;docDSCauHoi(filein,l);
        do{
                system("cls");
                cout<<"\n\n\n\n\n-------------------------------------------------------------------------\n";
                cout<<"|\t\t CHAO MUNG DEN CHUONG TRINH AI LA TRIEU PHU\t\t|\n";
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"|\t\t\t 1: PLAYER \t\t\t\t\t|\n";
                cout<<"|\t\t\t 2: ADMIN(ad key = 123) \t\t\t|\n";
                cout<<"|\t\t\t 0: THOAT \t\t\t\t\t|\n";
                cout<<"-------------------------------------------------------------------------\n";
                cout<<"\n\nBAN LA AI : ";
                cin>>chon;
                switch(chon){
                        case 1:{
                                choi(l);
                        }break;
                        case 2:{int key;
                                do{
                                cout<<"\n\n\n\n\n-------------------------------------------------------------------------\n";
                                cout<<"|\t\t CHAO MUNG DEN CHUONG TRINH AI LA TRIEU PHU\t\t|\n";
                                cout<<"-------------------------------------------------------------------------\n";
                                cout<<"|\t\t\t 1: XUAT CAU HOI \t\t\t\t|\n";
                                cout<<"|\t\t\t 2: NHAP CAU HOI\t\t\t\t|\n";
                                cout<<"|\t\t\t 3: XOA CAU HOI\t\t\t\t\t|\n";
                                cout<<"|\t\t\t 4: SUA CAU HOI\t\t\t\t\t|\n";
                                cout<<"|\t\t\t 0: THOAT \t\t\t\t\t|\n";
                                cout<<"-------------------------------------------------------------------------\n";
                                cout<<"\n\nCHON CONG VIEC BAN MUON LAM : ";
                                cin>>key;
                                switch(key){
                                        case 1: {
                                                system("cls");
                                                int dem=1;
                                                for(Node* p=l.first;p!=NULL;p=p->link){
                                                cout<<"\n\t\t\tCAU HOI SO "<<dem++<<endl;
                                                Print(p->data);
                                                }
                                        }break;
                                        case 2:{
                                                system("cls");
                                                nhap(l);
                                        }break;
                                        case 4:{
                                                int tmp; int i=0;
                                                cout<<"NHAP CAU SO ? CAN SUA"<<endl;
                                                cin>>tmp;
                                                for(Node *p=l.first;p!=NULL;p=p->link){
                                                        Node *q=p;
                                                        if(i==tmp){
                                                                Print(q->data);
                                                                cout<<"\n\n"<<setw(30)<<left<<"NHAP CAU HOI : ";
                                                                fflush(stdin);
                                                                cin>>p->data.cauHoi;
                                                                cout<<setw(30)<<left<<"NHAP CAU TRA LOI DUNG : ";
                                                                fflush(stdin);
                                                                cin>>p->data.ansRight;
                                                                cout<<setw(30)<<"NHAP CAU TRA LOI SAI: ";
                                                                fflush(stdin);
                                                                cin>>p->data.ansWrong[0];
                                                                cout<<setw(30)<<left<<"NHAP CAU TRA LOI SAI: ";
                                                                fflush(stdin);
                                                                cin>>p->data.ansWrong[1];
                                                                cout<<setw(30)<<left<<"NHAP CAU TRA LOI SAI: ";
                                                                fflush(stdin);
                                                                cin>>p->data.ansWrong[2];
                                                                break;
                                                        }
                                                        i++;
                                                }
                                        }break;
                                        case 3:{
                                                int tmp; int i=1;
                                                cout<<"NHAP CAU SO ? CAN SUA"<<endl;
                                                cin>>tmp;

                                                for (Node *p=l.first;p!=NULL;p=p->link){
                                                                Node *q=p->link;

                                                                        if(i==tmp-1){
                                                                                if(p==l.first) l.first=p->link;
                                                                        else p->link=q->link;
                                                                        }
                                                                        i++;
                                                }
                                        } break;
                                        //default:
                                }
                        }while(key<=4&&key>0);
                        }break;
                        //default:
                }
        }while(chon!=2||chon!=1);
        return 0;
}
