#include <iostream>
#include "Supplies.h"
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
string arr[100];
class ListSup
{
private:
    int n;
    Supplies a[100];

public:
    ListSup();
    ~ListSup();
    int GetN();
    void SetN(int N);
    void NhapList();
    void ShowList();
    friend class Management;
};

// Dinh nghia
ListSup::ListSup()
{
    this->n = 1;
    Supplies a[1];
}

ListSup::~ListSup()
{
}

int ListSup::GetN()
{
    return this->n;
}

void ListSup::SetN(int N)
{
    this->n = N;
}

void ListSup::NhapList()
{
    string id, t, l, dem, dv, ori, nn;
    int c;
    fstream new_file;
    new_file.open("DataSupplies.txt", ios::in);
    if (new_file.is_open())
    {
        getline(new_file, nn);
        this->n = stoi(nn);
        for (int i = 0; i < n; i++)
        {
            getline(new_file, id);
            getline(new_file, t);
            getline(new_file, l);
            getline(new_file, dem);
            istringstream(dem) >> c;
            getline(new_file, dv);
            getline(new_file, ori);
            a[i].SetID(id); arr[i]=id;
            a[i].SetTen(t);
            a[i].SetLoai(l);
            a[i].SetCount(c);
            a[i].SetDonVi(dv);
            a[i].SetOrigin(ori);
        }
    }
}

void ListSup::ShowList()
{
    cout << endl
         << "                                    THONG TIN VAT TU                                              " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(3) << "   " << setw(11) << left << "Ma vat tu "
         << "|"
         << setw(3) << "   " << setw(11) << left << "Ten vat tu"
         << "|"
         << setw(3) << "   " << setw(13) << left << "Loai vat tu"
         << "|"
         << setw(3) << "   " << setw(11) << left << "So luong"
         << "|"
         << setw(3) << "   " << setw(11) << left << "Don vi"
         << "|"
         << setw(3) << "   " << setw(16) << left << "Nuoc san xuat"
         << "|" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        this->a[i].Show();
    }
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << endl << endl << endl;
}