#include <iostream>
using namespace std;
/*
1) hàm nhập mảng
2)hàm xuat mang
3)ham interchange sort
4)hoan vi
*/

void nhapmang(int a[],int n) /* mảng a hoạc khai báo con trỏ a */
{
 cout << "nhập các phần tử trong mảng";
 for(int i=0;i<n;i++)
 {
    cout <<"nhập giá trị cho phần tử thứ a[" << i <<"]";
    cin >>a[i];
 }
}
void xuatmang(int a[],int n)
{
  cout << "day la mnag dc săp xep \n";
  for(int i=0;i<n;i++)
  {
      cout << a[i] << ";";
  }
}
void hoanvi(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void innterchangesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            // săp xcep thang dan
            if(a[j]<a[i])
            {
                hoanvi(a[i],a[j]);
            }nhap
        }
    }
}
void selectionsort(int a[],int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j] <a[min])
            {
                min=j;
            }
        }
        hoanvi(a[min],a[i]);
    }
}
void bubblesort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(a[j]<a[j-1])
            {
                hoanvi(a[j],a[j-1]);
            }
        }
    }
}
//////
void Heapify(int a[],int n,int i)
{
   while (i<(n/2)-1)
   {
       int left=2*i+1;
       int right=2*i+2;
       int max=left;
       if(right <n && a[right]>a[max])
       {
            max=right;
       }
       if(a[i] <a[max])
       {
           hoanvi(a[i],a[max]);
       }
       i=max;
   }

}
void Buildhead(int a[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        Heapify(a,n,i);
    }
}
void heasort(int a[],int n)
{
    Buildhead(a,n);
    for(int i=n-1;i>=0;i--)
    {
      hoanvi(a[0],a[i]);
      Heapify(a,i,0);
    }
}
/////////
void shellsort(int a[],int n,int divideby)/// tuyen vào khoản cacs chia 2 hay 3
{
    int i,j,x,gap;
    for(gap =n/divideby;gap >0;gap=gap/divideby)
    {
        for (i=gap;i<n;i++)
        {
            x=a[i];
            j=i-gap;//a[j] đưng kề trước a[i] trong cùng dãy con
            while ((x<a[j])&& (j>=0))
            {
                a[j+gap]=a[j];// dời vbề sau
                j=j-gap;// đông thời giảm j về phía trươcvs
            }
            a[j+gap]=x;// khi nó đúng
        }
    }
}
void chuyen(int n,char A,char B)
{
    cout  <<"chueyn di tư A sang B";
}
void thaphn(int n,char A,char B,char C)
{
    if(n==1)
    {
        chuyen(1,A,C);
    }
    else{
        thaphn(n-1,A,C,B);// A sang trung gian
        chuyen(n,A,C);
        thaphn(n-1,B,A,C);
    }
}
void quicksort(int a[,int left,int right)
{
    int i,j,x;
    k=a[(left+right)/2]; /// chonj x pivot
    i=left;
    j=right;
    do
    {
        while(a[i]<x)
        {
            i++;
        }
        while(a[j]>x)
        {
            j--;
        }
        if(i<=j)
        {
            hoanvi(a[i],a[j]);
            i++;
            j--;
        }

    }
    while(i<=j);
    if(left <j)
        quicksort(a,left,j);
    if(i<right)
        quicksort(a,i,right);
}
void merge(int a[],int b[],int low,int pivot,int hight)
{
    int h,i,j,k;
    h=low;i=low;
    j=pivot+1;
    while((h<=pivot)&&(j<=hight))
    {
        if(a[h] <=a[j])// been tria nhor hown been phair
        {
            b[i]=a[h];//lutru ben trai vao tam mang
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    if(h>pivot)//duyet xong ben trai copy nhung phan tu con lai cuar ben phair vaof mang tam
    {
       for(k=j;k<=hight;k++)
       {
           b[i]=a[k];
           i++;
       }

    }
    else //nguoc lai copy nhung phan tu con lai caur ben trai vano mang tam
    {
        for(k=h;k<=pivot;k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    }
    for(k=low;k<hight;k++)//copy phan tu vao mang goc
    {
        a[k]=b[k];
    }
}
void mergesort(int a[],int b[],int low,int right)
{
     int pivot;// bieens lu truw ,bien o giua
     if(low<hight)
     {
         pivot=(low+right)/2;

         mergesort(a,b,low,pivot);
         mergesort(a,b,pivot+1,hight);
         merge(a,b,low,pivot,hight);
     }

}
int linerSearch(int a[],int n,int x)
{
    int i=0;
    a[n]=x;//a[n] laf phaanf tuwr linhs canh
    while (a[i]!=x)
        i++;
    if(i==n)
        return 0;
    else
        return 1;
}
int main()
{
    int *a;
    int n;
    cout <<"nhap so phan tu n= ";
    cin >> n;
    a=new int[n]; // cấp phát động tạo ra 1 mảng do ng dung nhập vào
    nhapmang(a,n);
    cout <<"mang truoc khi săp xep \n";
    xuatmang(a,n);
    innterchangesort(a,n);
    cout << "mang sau khi săp xep \n";
    xuatmang(a,n);
    selectionsort(a,n);
    bubblesort(a,n);
    heasort(a,n);
    shellsort(a,n,2);
    quicksort(a,0,n-1);
    system("pause");
    //
    cout <<"nhaapj vaof soos ddiax n= ";
    char a='A';
    char b='b';
    char c='c';
    thaphn(n,a,b,c);
    return 0;
    // merrge
    int num=sizeof(a)/sizeof(int);
    int b[num];//khia bao bien tanm de thuc hien
    mergesort(a,b,0,num-1);
    for(int i=0;i<num;i++)
        cout << a[i]<< ;
}



