#include <iostream>
#include "Order.h"
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
class ListOrder
{
private:
    int n;
    Order b[100];

public:
    ListOrder();
    ~ListOrder();
    int GetN();
    void SetN(int N);
    void NhapListIn(char tep);
    void ShowListIn(char tep);
    friend class Management;
};

// Dinh nghia
ListOrder::ListOrder()
{
    this->n = 1;
    Order b[1];
}

ListOrder::~ListOrder()
{
}

int ListOrder::GetN()
{
    return this->n;
}

void ListOrder::SetN(int N)
{
    this->n = N;
}

void ListOrder::NhapListIn(char tep)
{
    string nn, ido, ids, te, lo, d1, m1, y1, sl1, g1;
    int n, d, m, y, sl, g, i = 0;
    fstream new_file1;
    switch (tep)
    {
    case ('n'):
    {
        new_file1.open("DataInput.txt", ios::in);
        break;
    }
    case ('x'):
    {
        new_file1.open("DataOutput.txt", ios::in);
        break;
    }
    }
    if (new_file1.is_open())
    {
        while (!new_file1.eof())
        {
            getline(new_file1, ido);
            getline(new_file1, d1);
            istringstream(d1) >> d;
            getline(new_file1, m1);
            istringstream(m1) >> m;
            getline(new_file1, y1);
            istringstream(y1) >> y;
            getline(new_file1, ids);
            getline(new_file1, te);
            getline(new_file1, lo);
            getline(new_file1, sl1);
            istringstream(sl1) >> sl;
            getline(new_file1, g1);
            istringstream(g1) >> g;
            b[i].SetIDorder(ido);
            b[i].SetDay(d);
            b[i].SetMonth(m);
            b[i].SetYear(y);
            b[i].SetID(ids);
            b[i].SetTen(te);
            b[i].SetLoai(lo);
            b[i].SetSLorder(sl);
            b[i].SetGia(g);
            i++;
        }
    }
    this->SetN(i);
}

void ListOrder::ShowListIn(char tep)
{
    switch (tep)
    {
    case ('n'):
    {
        cout << endl
             << "                                               THONG TIN DON NHAP                                                " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(2) << "  " << setw(13) << left << "Ma don nhap "
             << "|"
             << setw(3) << "   " << setw(13) << left << " Ngay nhap"
             << "|"
             << setw(2) << "  " << setw(10) << left << "Ma vat tu  "
             << "|"
             << setw(3) << "   " << setw(11) << left << "Ten vat tu"
             << "|"
             << setw(3) << "   " << setw(13) << left << "Loai vat tu"
             << "|"
             << setw(3) << "   " << setw(11) << left << "So luong"
             << "|"
             << setw(4) << "    " << setw(13) << left << "Gia nhap "
             << "|" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < this->GetN(); i++)
        {
            this->b[i].Show();
        }
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl
             << endl
             << endl;
        break;
    }
    case ('x'):
    {
        cout << endl << "                                               THONG TIN DON XUAT                                                " << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(2) << "  " << setw(13) << left << "Ma don xuat " << "|"
        << setw(3) << "   " << setw(13) << left << " Ngay xuat" << "|"
        << setw(2) << "  " << setw(10) << left << "Ma vat tu  " << "|"
        << setw(3) << "   " << setw(11) << left << "Ten vat tu" << "|"
        << setw(3) << "   " << setw(13) << left << "Loai vat tu" << "|"
        << setw(3) << "   " << setw(11) << left << "So luong" << "|"
        << setw(4) << "    " << setw(13) << left << "Gia xuat " << "|" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        for (int i=0; i<this->GetN(); i++)
        {
            this->b[i].Show();
        }
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl << endl << endl;
    }
    }
}
