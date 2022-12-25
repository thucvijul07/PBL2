#include <iostream>
#include "ListSup.h"
#include "ListOrder.h"
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;
string ma, newma;
int sl, newsl;

class Management
{
private:
    ListSup LI;
    ListOrder LII;
    ListOrder LIO;
public:
    Management();
    ~Management();
    void Start();
    void ShowListSup();
    void ShowListIn();
    void ShowListOut();
    void Add();
    void Delete();
    void Nhap();
    void UpdateNhap();
    void InsertOrderIn();
    void Xuat();
    void UpdateXuat();
    void InsertOrderOut();
    int SSearch(string arr[], int l, int r, string x);
    void Search();
    void Update(int n);
    void ThongKe();
    void Sort(int n);
};

Management::Management()
{
}

Management::~Management()
{
}
void Management::Start()
{
    LI.NhapList();
    LII.NhapListIn('n');
    LIO.NhapListIn('x');
}
void Management::ShowListSup()
{
    LI.NhapList();
    LI.ShowList();
}
void Management::ShowListIn()
{
    LII.NhapListIn('n');
    LII.ShowListIn('n');
    fstream in;
    in.open("FILESIN.txt", ios::out);
    in << endl << "                                     THONG TIN DON NHAP                                                " << endl;
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    in << "|" << setw(2) << "  " << setw(13) << left << "Ma don nhap " <<"|"
    << setw(3) << "   " << setw(13) << left << " Ngay nhap" << "|"
    << setw(2) << "  " << setw(10) << left << "Ma vat tu  " << "|"
    << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
    << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
    << setw(3) << "   " << setw(11) << left << "So luong" << "|"
    << setw(4) << "    " << setw(13) << left << "Gia nhap " << "|" << endl;
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<LII.GetN(); i++)
    {
    in << "|" << setw(3) << "     " << setw(10) << left << LII.b[i].GetIDorder() << "|"
    << setw(3) << "   " << right << setw(2) << LII.b[i].GetDay()<< "/" << setw(2) << LII.b[i].GetMonth() << "/" << LII.b[i].GetYear() << "   "<< left << "|"
    << setw(4) << "    " << setw(9) << left << LII.b[i].GetID() << left << "|"
    << setw(3) << "   " << setw(11) << left << LII.b[i].GetTen() << left << "|"
    << setw(3) << "   " << setw(13) << left << LII.b[i].GetLoai() << left << "|"
    << setw(5) << "     " << setw(6) << right << LII.b[i].GetSLorder() << left << "   |"
    << setw(3) << "      " << setw(9) << right << LII.b[i].GetGia() << left << "  |" << endl;
    }
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    in.close();

}
void Management::ShowListOut()
{
    LIO.NhapListIn('x');
    LIO.ShowListIn('x');
    fstream in;
    in.open("FILESOUT.txt", ios::out);
    in << endl << "                                     THONG TIN DON XUAT                                                " << endl;
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    in << "|" << setw(2) << "  " << setw(13) << left << "Ma don xuat " <<"|"
    << setw(3) << "   " << setw(13) << left << " Ngay xuat" << "|"
    << setw(2) << "  " << setw(10) << left << "Ma vat tu  " << "|"
    << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
    << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
    << setw(3) << "   " << setw(11) << left << "So luong" << "|"
    << setw(4) << "    " << setw(13) << left << "Gia xuat " << "|" << endl;
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<LIO.GetN(); i++)
    {
    in << "|" << setw(3) << "     " << setw(10) << left << LIO.b[i].GetIDorder() << "|"
    << setw(3) << "   " << right << setw(2) << LIO.b[i].GetDay()<< "/" << setw(2) << LIO.b[i].GetMonth() << "/" << LIO.b[i].GetYear() << "   "<< left << "|"
    << setw(4) << "    " << setw(9) << left << LIO.b[i].GetID() << left << "|"
    << setw(3) << "   " << setw(11) << left << LIO.b[i].GetTen() << left << "|"
    << setw(3) << "   " << setw(13) << left << LIO.b[i].GetLoai() << left << "|"
    << setw(5) << "     " << setw(6) << right << LIO.b[i].GetSLorder() << left << "   |"
    << setw(3) << "      " << setw(9) << right << LIO.b[i].GetGia() << left << "  |" << endl;
    }
    in << "-----------------------------------------------------------------------------------------------------------------" << endl;
    in.close();
}

void Management::Add()
{
    string id,t,l,dv,nc;
    do{
        cout << "Nhap ma vat tu can them: ";
        cin >> id;
        if(SSearch(arr,0,LI.GetN()-1,id) == 1){
            cout << "Trung ma vat tu. Hay nhap lai ma vat tu can them! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,id) == 1);

    LI.a[LI.GetN()].SetID(id);
    cout << "Nhap ten vat tu: ";
    cin.ignore(32767,'\n');
    getline(cin,t); LI.a[LI.GetN()].SetTen(t);

    cout << "Nhap loai vat tu: ";
    getline(cin,l); LI.a[LI.GetN()].SetLoai(l);

    LI.a[LI.GetN()+1].SetCount(0);

    cout << "Nhap don vi: ";
    getline(cin,dv); LI.a[LI.GetN()].SetDonVi(dv);

    cout << "Nhap nuoc san xuat: ";
    getline(cin,nc); LI.a[LI.GetN()].SetOrigin(nc);

    fstream ofs;
    ofs.open("DataSupplies.txt", ios::out);
    LI.SetN(LI.GetN()+1);
    ofs << LI.GetN() << endl;
    for (int i = 0; i < LI.GetN(); i++)
    {
        ofs << LI.a[i].GetID() << endl;
        ofs << LI.a[i].GetTen() << endl;
        ofs << LI.a[i].GetLoai() << endl;
        ofs << LI.a[i].GetCount() << endl;
        ofs << LI.a[i].GetDonVi() << endl;
        ofs << LI.a[i].GetOrigin() << endl;
    }
    ofs.close();
    LI.NhapList();
    LI.ShowList();
}
void Management::Delete()
{
    LI.ShowList();
    int p;
    string name;
    do{
        cout << "Nhap ma vat tu can xoa: ";
        cin >> name;
        if(SSearch(arr,0,LI.GetN()-1,name) == -1){
            cout << "Nhap sai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,name) == -1);
    p = SSearch(arr, 0, LI.GetN(),name);
    fstream ofs;
    ofs.open("DataSupplies.txt", ios::out);
    ofs << LI.GetN()-1 << endl;
    for (int i = 0; i < LI.GetN(); i++)
    if (i!=p)
    {
        ofs << LI.a[i].GetID() << endl;
        ofs << LI.a[i].GetTen() << endl;
        ofs << LI.a[i].GetLoai() << endl;
        ofs << LI.a[i].GetCount() << endl;
        ofs << LI.a[i].GetDonVi() << endl;
        ofs << LI.a[i].GetOrigin() << endl;
    }
    ofs.close();
    LI.NhapList();
    LI.ShowList();
}
void Management::Nhap()
{
    string a;
    fstream ofs;
    ofs.open("DataInput.txt", ios::app);
    cout << "Nhap ma don nhap: ";
    cin >> a; ofs << endl << a;
    cout << "Nhap ngay: ";
    cin >> a; ofs << endl << a;
    cout << "Nhap thang: ";
    cin >> a; ofs << endl << a;
    cout << "Nhap nam: ";
    cin >> a; ofs << endl << a;
    do{
        cout << "Nhap ma vat tu : ";
        cin >> a;
        if(SSearch(arr,0,LI.GetN()-1,a) == -1){
            cout << "Ma vat tu khong ton tai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,a) == -1);
    ofs << endl << a; ma = a;
    for (int i = 0; i < LI.GetN(); i++)
    {
        if (LI.a[i].GetID() == ma)
            {
                a = LI.a[i].GetTen();
                ofs << endl << a;
                a = LI.a[i].GetLoai();
                ofs << endl << a;
            }
    }
    cout << "Nhap so luong : ";
    cin >> a; ofs << endl << a; istringstream(a) >> sl;
    cout << "Nhap gia nhap : ";
    cin >> a; ofs << endl << a;
    ofs.close();
    LII.SetN(LII.GetN() + 1);
}
void Management::UpdateNhap()
{
    for (int i = 0; i < LI.GetN(); i++)
    {
        if (LI.a[i].GetID() == ma)
            LI.a[i].SetCount(LI.a[i].GetCount()+sl);
    }
    fstream ofs;
    ofs.open("DataSupplies.txt", ios::out);
    ofs << LI.GetN() << endl;
    for (int i = 0; i < LI.GetN(); i++)
    {
        ofs << LI.a[i].GetID() << endl;
        ofs << LI.a[i].GetTen() << endl;
        ofs << LI.a[i].GetLoai() << endl;
        ofs << LI.a[i].GetCount() << endl;
        ofs << LI.a[i].GetDonVi() << endl;
        ofs << LI.a[i].GetOrigin() << endl;
    }
    ofs.close();
}
void Management::InsertOrderIn()
{
    Nhap();
    UpdateNhap();
}
void Management::Xuat()
{
    string a;
    fstream ofs1;
    ofs1.open("DataOutput.txt", ios::app);
    cout << "Nhap ma don xuat: ";
    cin >> a; ofs1 << endl << a;
    cout << "Nhap ngay: ";
    cin >> a; ofs1 << endl << a;
    cout << "Nhap thang: ";
    cin >> a; ofs1 << endl << a;
    cout << "Nhap nam: ";
    cin >> a; ofs1 << endl << a;
    do{
        cout << "Nhap ma vat tu : ";
        cin >> a;
        if(SSearch(arr,0,LI.GetN()-1,a) == -1){
            cout << "Ma vat tu khong ton tai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,a) == -1);
    ofs1 << endl << a;
    newma = a;
    for (int i = 0; i < LI.GetN(); i++)
    {
        if (LI.a[i].GetID() == newma)
            {
                a = LI.a[i].GetTen();
                ofs1 << endl << a;
                a = LI.a[i].GetLoai();
                ofs1 << endl << a;
            }
    }
    cout << "Nhap so luong : ";
    cin >> a; ofs1 << endl << a;
    istringstream(a) >> newsl;
    cout << "Nhap gia xuat : ";
    cin >> a; ofs1 << endl << a;
    ofs1.close();
    LIO.SetN(LIO.GetN() + 1);
}
void Management::UpdateXuat()
{
    newsl = 0 - newsl;
    for (int i = 0; i < LI.GetN(); i++)
    {
        if (LI.a[i].GetID() == newma)
            LI.a[i].SetCount(LI.a[i].GetCount() + newsl);
    }
    fstream ofs1;
    ofs1.open("DataSupplies.txt", ios::out);
    ofs1 << LI.GetN() << endl;
    for (int i = 0; i < LI.GetN(); i++)
    {
        ofs1 << LI.a[i].GetID() << endl;
        ofs1 << LI.a[i].GetTen() << endl;
        ofs1 << LI.a[i].GetLoai() << endl;
        ofs1 << LI.a[i].GetCount() << endl;
        ofs1 << LI.a[i].GetDonVi() << endl;
        ofs1 << LI.a[i].GetOrigin() << endl;
    }
    ofs1.close();
}
void Management::InsertOrderOut()
{
    Xuat();
    UpdateXuat();
}
int Management::SSearch(string arr[], int l, int r, string x)
{
    for (int j=l; j<=r; j++)
    {
        if (x == arr[j])
            return j;
    }
    return -1;
}
void Management::Search()
{
    string id;
    int i=LI.GetN(),p;
    do{
        cout << "Nhap ma vat tu can tim kiem: ";
        cin >> id;
        if(SSearch(arr,0,LI.GetN()-1,id) == -1){
            cout << "Ma vat tu khong ton tai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,id) == -1);
    cout << endl << endl;
    p=SSearch(arr, 0,i,id);
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(3) << "   " << setw(11) << left << "Ma vat tu "<< "|"
         << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
         << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
         << setw(3) << "   " << setw(11) << left << "So luong" << "|"
         << setw(3) << "   " << setw(11) << left << "Don vi" << "|"
         << setw(3) << "   " << setw(16) << left << "Nuoc san xuat" << "|" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    LI.a[p].Show();
    cout << "--------------------------------------------------------------------------------------------------" << endl;
}
void Management::Update(int n)
{
    string id,t;
    int i=LI.GetN(),p,q;
    do{
        cout << "Nhap ma vat tu can cap nhat: ";
        cin >> id;
        if(SSearch(arr,0,LI.GetN()-1,id) == -1){
            cout << "Ma vat tu khong ton tai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,id) == -1);
    cout << endl;
    p=SSearch(arr, 0,i-1,id);
    switch (n)
    {
    case (1):
        {
        cin.ignore(32767,'\n');
        cout << "Ten ma vat tu hien co cua ma vat tu " << LI.a[p].GetID() << " la: " << LI.a[p].GetTen() << endl;
        cout << "Ten moi can cap nhat: ";
        getline(cin,t);
        LI.a[p].SetTen(t);
        cout << "Cap nhat thanh cong" << endl;
        break;
        }
    case (2):
        {
        cout << "Loai vat tu hien co cua ma vat tu " << LI.a[p].GetID() << " la: " << LI.a[p].GetLoai() << endl;
        cout << "Loai vat tu moi can cap nhat: ";
        cin.ignore(32767,'\n');
        getline(cin,t);
        LI.a[p].SetLoai(t);
        cout << "Cap nhat thanh cong" << endl;
        break;
        }
    case (3):
        {
        cout << "So luong vat tu hien co cua ma vat tu " << LI.a[p].GetID() << " la: " << LI.a[p].GetCount() << endl;
        cout << "So luong moi can cap nhat: ";
        cin >> q;
        LI.a[p].SetCount(q);
        cout << "Cap nhat thanh cong" << endl;
        break;
        }
    case (4):
        {
        cout << "Don vi hien co cua ma vat tu " << LI.a[p].GetID() << " la: " << LI.a[p].GetDonVi() << endl;
        cout << "Don vi moi can cap nhat: ";
        cin.ignore(32767,'\n');
        getline(cin,t);
        LI.a[p].SetDonVi(t);
        cout << "Cap nhat thanh cong" << endl;
        break;
        }
    case (5):
        {
        cout << "Nha san xuat hien co cua ma vat tu " << LI.a[p].GetID() << " la: " << LI.a[p].GetOrigin() << endl;
        cout << "Nha san xuat moi can cap nhat: ";
        cin.ignore(32767,'\n');
        getline(cin,t);
        LI.a[p].SetOrigin(t);
        cout << "Cap nhat thanh cong" << endl;
        break;
        }
    }
    fstream ofs;
    ofs.open("DataSupplies.txt", ios::out);
    ofs << LI.GetN() << endl;
    for (int i = 0; i < LI.GetN(); i++)
    {
        ofs << LI.a[i].GetID() << endl;
        ofs << LI.a[i].GetTen() << endl;
        ofs << LI.a[i].GetLoai() << endl;
        ofs << LI.a[i].GetCount() << endl;
        ofs << LI.a[i].GetDonVi() << endl;
        ofs << LI.a[i].GetOrigin() << endl;
    }
    ofs.close();
}
void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
bool ascending( int x, int y){
	return x > y; 
}
bool descending( int x, int y){
	return x < y;
}
void SelectionSort( int *p, int *q, int length, bool (*cmp)(int, int))
{
	for (int i = 0; i < length - 1; i++)
		for (int j = i + 1; j < length; j++)
			if (cmp(*(p + i), *(p + j))){
				Swap(*(p + i), *(p + j));
                Swap(*(q + i), *(q + j));
                }
}
void Management::Sort(int n)
{
    int A[100],B[100];
    int length = LI.GetN();
    for (int i=0; i<length; i++)
    {
        A[i]=i;
        B[i]=LI.a[i].GetCount();
    }
    switch (n)
    {
    case (1):
        {
        SelectionSort(B,A,length,ascending);
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(3) << "   " << setw(11) << left << "Ma vat tu "<< "|"
         << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
         << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
         << setw(3) << "   " << setw(11) << left << "So luong" << "|"
         << setw(3) << "   " << setw(11) << left << "Don vi" << "|"
         << setw(3) << "   " << setw(16) << left << "Nuoc san xuat" << "|" << endl;
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        for (int j=0; j<length; j++)
            LI.a[A[j]].Show();
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        break;
        }
    case (2):
        {
        SelectionSort(B,A,length,descending);
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(3) << "   " << setw(11) << left << "Ma vat tu "<< "|"
         << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
         << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
         << setw(3) << "   " << setw(11) << left << "So luong" << "|"
         << setw(3) << "   " << setw(11) << left << "Don vi" << "|"
         << setw(3) << "   " << setw(16) << left << "Nuoc san xuat" << "|" << endl;
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        for (int j=0; j<length; j++)
            LI.a[A[j]].Show();
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        break;
        }
    }
}
void Management::ThongKe()
{
    string name;
    int PriceI=0, PriceO=0;
    do{
        cout << "Nhap ma vat tu can thong ke: ";
        cin >> name;
        if(SSearch(arr,0,LI.GetN()-1,name) == -1){
            cout << "Ma vat tu khong ton tai. Hay nhap lai ma vat tu! " << endl;
        }
    } while (SSearch(arr,0,LI.GetN()-1,name) == -1);
    cout << endl << endl;
    cout << "-----------------------------------------------------DON NHAP----------------------------------------------------" << endl;
    cout << "|" << setw(2) << "  " << setw(13) << left << "  Ma don    " <<"|"
    << setw(3) << "   " << setw(13) << left << " Ngay nhap" << "|"
    << setw(2) << "  " << setw(10) << left << "Ma vat tu  " << "|"
    << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
    << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
    << setw(3) << "   " << setw(11) << left << "So luong" << "|"
    << setw(4) << "    " << setw(13) << left << "Gia nhap " << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    for (int i=0; i<=LII.GetN(); i++)
    {
        if (LII.b[i].GetID()==name)
            {
                LII.b[i].Show();
                PriceI += LII.b[i].GetSLorder()*LII.b[i].GetGia();
            }
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                              |   TONG TIEN  |" << setw(15) <<right << PriceI << "  |" << endl
    
         << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "-----------------------------------------------------DON XUAT----------------------------------------------------" << endl;
    cout << "|" << setw(2) << "  " << setw(13) << left << "  Ma don    " <<"|"
    << setw(3) << "   " << setw(13) << left << " Ngay nhap" << "|"
    << setw(2) << "  " << setw(10) << left << "Ma vat tu  " << "|"
    << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
    << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
    << setw(3) << "   " << setw(11) << left << "So luong" << "|"
    << setw(4) << "    " << setw(13) << left << "Gia xuat " << "|" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    for (int j=0; j<=LIO.GetN(); j++)
    {
        if (LIO.b[j].GetID()==name)
            {
                LIO.b[j].Show();
                PriceO += LIO.b[j].GetSLorder()*LIO.b[j].GetGia();
            }
    }
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                                              |   TONG TIEN  |" << setw(15) <<right << PriceO << "  |" << endl
    
         << "-----------------------------------------------------------------------------------------------------------------" << endl;
}


